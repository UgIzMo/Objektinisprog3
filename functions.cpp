#include "studentas.h"
#include "functions.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

double skaiciuotiVidurki(const vector<int>& nd)
{
    if (nd.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : nd)
    {
        suma += pazymys;
    }
    return suma / nd.size();
}

double skaiciuotiMediana(const vector<int>& namuDarbai)
{
    if (namuDarbai.empty()) return 0; ///tikriname, ar nd vektorius tuscias

    vector<int> tempNamuDarbai = namuDarbai;
    sort(tempNamuDarbai.begin(), tempNamuDarbai.end()); /// didejimo tvarka
    int dydis = tempNamuDarbai.size();
    if (dydis % 2 == 0)
    {
        return (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0;
    }
    else
    {
        return tempNamuDarbai[dydis / 2];
    }
}

double skaiciuotiGalutini(const vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki)
{
    if (naudotiVidurki)
    {
        double vidurkis = skaiciuotiVidurki(namuDarbai);
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }
    else
    {
        return 0.4 * skaiciuotiMediana(namuDarbai) + 0.6 * egzaminas;
    }
}

void atsitiktiniai(Studentas& studentas)
{
    studentas.getNamuDarbai().resize(rand() % 10 + 1);
    for (int& pazymys : studentas.getNamuDarbai())
    {
        pazymys = rand() % 10 + 1;
    }
    studentas.setEgzaminas(rand() % 10 + 1);
}

void atsitiktiniaiStudentai(Studentas& studentas)
{
    const char* vardai[] = {"Ana", "Gloria", "Sofia", "Ugne", "Aina", "Guoda"};
    const char* pavardes[] = {"Mockute", "Liuc", "Mickute", "Macaite", "Migonyte", "Peleda"};
    int vardasIndex=rand()%6;
    int pavardeIndex=rand()%6;
    studentas.setVardas(vardai[vardasIndex]);
    studentas.setPavarde(pavardes[pavardeIndex]);
    atsitiktiniai(studentas);
}

void nuskaitymas(vector<Studentas>& studentai, const string& failoPavadinimas)
{
    try
    {
        ifstream fd(failoPavadinimas);
        if (!fd.is_open())
        {
            throw runtime_error("Nepavyko atidaryti failo.");
        }

        string vardas, pavarde;
        vector<int> namuDarbai;
        int egzaminas;

        string eilute;
        getline(fd, eilute); //praleidzia pirmaja eil.

        while (getline(fd, eilute))
        {
            istringstream eilutesSrautas(eilute);
            eilutesSrautas >> vardas >> pavarde;

            int pazymys;
            namuDarbai.clear();
            while (eilutesSrautas >> pazymys && pazymys != -1)
            {
                namuDarbai.push_back(pazymys);
            }

            egzaminas = pazymys;

            // Create a Studentas object using the constructor
            Studentas studentas(vardas, pavarde, namuDarbai, egzaminas);
            studentai.push_back(studentas);
        }

        fd.close();
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
}


bool rusiuotiPagalVarda(const Studentas& a, const Studentas& b)
{
    return a.getVardas() < b.getVardas();
}

bool rusiuotiPagalPavarde(const Studentas& a, const Studentas& b)
{
    return a.getPavarde() < b.getPavarde();
}

bool rusiuotiPagalGalutiniVidurki(const Studentas& a, const Studentas& b)
{
    return skaiciuotiGalutini(a.getNamuDarbai(), a.getEgzaminas(), true) < skaiciuotiGalutini(b.getNamuDarbai(), b.getEgzaminas(), true);
}

bool rusiuotiPagalGalutiniMediana(const Studentas& a, const Studentas& b)
{
    return skaiciuotiGalutini(a.getNamuDarbai(), a.getEgzaminas(), false) < skaiciuotiGalutini(b.getNamuDarbai(), b.getEgzaminas(), false);
}

void spausdinimas(const vector<Studentas>& studentai, const string& isvedimoFailas)
{
    ostream& out = isvedimoFailas.empty() ? cout : *new ofstream(isvedimoFailas);

    ///rusiavimas atitinkamai pagal naudotojo pasirirnkima
    vector<Studentas> surusiuotiStudentai = studentai;

    int pasirinkimas;
    cout << "Pasirinkite kaip rusiuoti studentus:\n"
         << "1 - Pagal varda\n"
         << "2 - Pagal pavarde\n"
         << "3 - Pagal vidurki\n"
         << "4 - Pagal mediana\n";
    cin >> pasirinkimas;

    switch(pasirinkimas)
    {
    case 1:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), rusiuotiPagalVarda);
        break;
    case 2:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), rusiuotiPagalPavarde);
        break;
    case 3:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), rusiuotiPagalGalutiniVidurki);
        break;
    case 4:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), rusiuotiPagalGalutiniMediana);
        break;
    default:
        cout << "Pasirinkimas netinkamas, surusiuota pagal varda.\n";
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), rusiuotiPagalVarda);
    }

    out << fixed << setprecision(2);
    out << "Studentu galutiniai balai:\n";
    out << "----------------------------------------------------------------\n";
    out << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)\n";
    out << "----------------------------------------------------------------\n";

    for (const Studentas& studentas : surusiuotiStudentai)
    {
        double galutinisVidurkis = skaiciuotiGalutini(studentas.getNamuDarbai(), studentas.getEgzaminas(), true);
        double galutineMediana = skaiciuotiGalutini(studentas.getNamuDarbai(), studentas.getEgzaminas(), false);
        out << left << setw(15) << studentas.getVardas() << setw(15) << studentas.getPavarde() << setw(20) << galutinisVidurkis << setw(20) << galutineMediana << "\n";
    }
    out << "----------------------------------------------------------------\n";

    if (!isvedimoFailas.empty())
    {
        delete &out;
    }
}

string pasirinktiFaila()
{
    string failoPavadinimas;

    cout << "Pasirinkite faila is kurio norite skaityti duomenis:\n"
         << "1 - kursiokai.txt\n"
         << "2 - studentai10000.txt\n"
         << "3 - studentai100000.txt\n"
         << "4 - studentai1000000.txt\n";

    int pasirinkimas;
    cin >> pasirinkimas;

    switch (pasirinkimas)
    {
    case 1:
        failoPavadinimas = "kursiokai.txt";
        break;
    case 2:
        failoPavadinimas = "studentai10000.txt";
        break;
    case 3:
        failoPavadinimas = "studentai100000.txt";
        break;
    case 4:
        failoPavadinimas = "studentai1000000.txt";
        break;
    default:
        cout << "Neteisingas pasirinkimas. Skaitoma is kursiokai.txt\n";
        failoPavadinimas = "kursiokai.txt";
    }

    return failoPavadinimas;
}
