#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <random>
#include <ctime>
#include <sstream>
#include <chrono>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
};

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
    studentas.namuDarbai.resize(rand() % 10 + 1);
    for (int& pazymys : studentas.namuDarbai)
    {
        pazymys = rand() % 10 + 1;
    }
    studentas.egzaminas = rand() % 10 + 1;
}

void atsitiktiniaiStudentai(Studentas& studentas)
{
    const char* vardai[] = {"Ana", "Gloria", "Sofia", "Ugne", "Aina", "Guoda"};
    const char* pavardes[] = {"Mockute", "Liuc", "Mickute", "Macaite", "Migonyte", "Peleda"};
    int vardasIndex=rand()%6;
    int pavardeIndex=rand()%6;
    studentas.vardas=vardai[vardasIndex];
    studentas.pavarde=pavardes[pavardeIndex];
    atsitiktiniai(studentas);
}

void nuskaitymas(vector<Studentas>& studentai, const string& failoPavadinimas)
{
    ifstream fd(failoPavadinimas);
    if (!fd.is_open())
    {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    Studentas studentas;
    string eilute;
    getline(fd, eilute); //praleidzia pirmaja eil.

    while (getline(fd, eilute))
    {
        istringstream eilutesSrautas(eilute);
        eilutesSrautas >> studentas.vardas >> studentas.pavarde;

        int pazymys;
        studentas.namuDarbai.clear();
        while (eilutesSrautas >> pazymys && pazymys != -1)
        {
            studentas.namuDarbai.push_back(pazymys);
        }

        studentas.egzaminas = pazymys;
        studentai.push_back(studentas);
    }

    fd.close();
}


bool rusiuotiPagalVarda(const Studentas& a, const Studentas& b)
{
    return a.vardas < b.vardas;
}

bool rusiuotiPagalPavarde(const Studentas& a, const Studentas& b)
{
    return a.pavarde < b.pavarde;
}

bool rusiuotiPagalGalutiniVidurki(const Studentas& a, const Studentas& b)
{
    return skaiciuotiGalutini(a.namuDarbai, a.egzaminas, true) < skaiciuotiGalutini(b.namuDarbai, b.egzaminas, true);
}

bool rusiuotiPagalGalutiniMediana(const Studentas& a, const Studentas& b)
{
    return skaiciuotiGalutini(a.namuDarbai, a.egzaminas, false) < skaiciuotiGalutini(b.namuDarbai, b.egzaminas, false);
}

void spausdinimas(const vector<Studentas>& studentai, const string& isvedimoFailas = "")
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
        double galutinisVidurkis = skaiciuotiGalutini(studentas.namuDarbai, studentas.egzaminas, true);
        double galutineMediana = skaiciuotiGalutini(studentas.namuDarbai, studentas.egzaminas, false);
        out << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(20) << galutinisVidurkis << setw(20) << galutineMediana << "\n";
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

int main()
{
    srand(static_cast <unsigned int>(time(nullptr)));

    vector<Studentas> studentai; ///studentu duomenys
    char testi;
    int meniu = 0;

    double visoLaikoSuma = 0.0;
    int testuSkaicius = 0;

    do
    {
        auto start = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas

        cout << "Pasirinkite buda:\n"
             << "1 - ivesti studentu duomenis rankiniu budu \n"
             << "2 - sugeneruoti pazymius \n"
             << "3 - generuoti ir pazymius ir studentu vardus, pavardes \n"
             << "4 - skaityti is failo \n"
             << "5 - baigti darba \n" ;
        cin >> meniu;

        switch(meniu)
        {
        case 1:
        {
            do
            {
                Studentas studentas;

                cout << "Iveskite studento varda: ";
                cin >> studentas.vardas;

                cout << "Iveskite studento pavarde: ";
                cin >> studentas.pavarde;

                studentas.namuDarbai.clear(); /// Isvalome namų darbu pazymiu vektoriu

                int pazymys;
                cout << "Iveskite namu darbu rezultatus (iveskite 0 jei baigete ivedima): " << endl;
                int k=1;

                while(true)
                {
                    cout << k << "-asis pazymys: ";
                    if(cin >> pazymys && pazymys != 0)
                    {
                        studentas.namuDarbai.push_back(pazymys);
                        k++;
                    }
                    else if (pazymys==0)
                        break;
                    else
                    {
                        cin.clear();
                        cin.ignore(80,'\n');
                        cout << "Neteisingas ivedimas. Iveskite teisinga skaiciu" << endl;
                    }
                }

                cout << "Iveskite egzamino rezultata: ";
                cin >> studentas.egzaminas;

                studentai.push_back(studentas);

                cout << "Ar norite vesti dar vieno studento duomenis? (t/n): ";
                cin >> testi;
            }

            while (testi == 't');

            spausdinimas(studentai);

            break;
        }
        case 2:
        {
            for (auto& studentas : studentai)
            {
                auto startTest = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

                atsitiktiniai(studentas);
                cout << "Studentas: \nEgzaminas: " << studentas.egzaminas << "\nNamu darbu pazymiai: ";
                for (int pazymys : studentas.namuDarbai)
                {
                    cout << pazymys << " ";
                }
                cout << "\n\n";

                auto endTest = chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas testui
                chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
                double laikasTest = timeTest.count(); // Laikas testui
                visoLaikoSuma += laikasTest; // Pridedamas laikas prie viso laiko sumos
                testuSkaicius++; // Pridedamas vienetinis testų skaičius
            }
            break;
        }

        case 3:
        {
            auto startTest = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

            cout << fixed << setprecision(2);
            cout << "Studentu galutiniai balai:\n";
            cout << "----------------------------------------------------------------\n";
            cout << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)\n";
            cout << "----------------------------------------------------------------\n";

            for (int i = 0; i < 6; i++)
            {
                Studentas naujasStudentas;
                atsitiktiniaiStudentai(naujasStudentas);
                studentai.push_back(naujasStudentas);

                double galutinisVidurkis = skaiciuotiGalutini(naujasStudentas.namuDarbai, naujasStudentas.egzaminas, true);
                double galutineMediana = skaiciuotiGalutini(naujasStudentas.namuDarbai, naujasStudentas.egzaminas, false);
                cout << left << setw(15) << naujasStudentas.vardas << setw(15) << naujasStudentas.pavarde << setw(20) << galutinisVidurkis << setw(20) << galutineMediana << "\n";
            }
            cout << "----------------------------------------------------------------\n";

            auto endTest = chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas testui
            chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
            double laikasTest = timeTest.count(); // Laikas testui
            visoLaikoSuma += laikasTest; // Pridedamas laikas prie viso laiko sumos
            testuSkaicius++; // Pridedamas vienetinis testų skaičius
            break;
        }
        case 4:
        {
            auto startTest = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

            nuskaitymas(studentai, pasirinktiFaila());
            spausdinimas(studentai, "isvedimas.txt");

            auto endTest = chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas testui
            chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
            double laikasTest = timeTest.count(); // Laikas testui
            visoLaikoSuma += laikasTest; // Pridedamas laikas prie viso laiko sumos
            testuSkaicius++; // Pridedamas vienetinis testu skaicius
            break;
        }
        case 5:
            break;
        }

        auto end = chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas
        chrono::duration<double> time = end - start; // Laikas
        double laikas = time.count(); // Issaugojamas laikas
        cout << "Visas sugaistas laikas: " << laikas << " s" << endl;

    }
    while (meniu != 5);

    double vidurkis = visoLaikoSuma / testuSkaicius; // Suskaiciuojamas laiku vidurkis
    cout << "Keliu testu laiku vidurkis: " << vidurkis << " s" << endl; // Isvedamas laiku vidurkis

    return 0;
}
