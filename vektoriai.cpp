#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <random>
#include <ctime>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    //double vidurkis;
    //double galutinis;
};

double skaiciuotiVidurki(vector<int>& namuDarbai)
{
    if (namuDarbai.empty())   ///tikriname, ar nd vektorius tuscias
        return 0;
    double suma=0.0;
    for(int i=0; i<namuDarbai.size(); i++)
    {
        suma+=namuDarbai[i];
    }
    return suma / namuDarbai.size();
}

double skaiciuotiMediana(vector<int>& namuDarbai)
{
    if (namuDarbai.empty())  ///tikriname, ar nd vektorius tuscias?
        return 0;

    vector<int> tempNamuDarbai=namuDarbai;
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

double skaiciuotiGalutini(vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki)
{
    if (naudotiVidurki)
    {
        if (namuDarbai.empty())
            return egzaminas; /// Jei nd nera, galutinis balas yra egz.

        double vidurkis = skaiciuotiVidurki(namuDarbai);
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }
    else
    {
        return 0.4 * skaiciuotiMediana(namuDarbai) + 0.6 * egzaminas;
    }
}

void atsitiktiniai(Studentas& studentai)
{
    studentai.namuDarbai.resize(rand()%10+1);
    for(int& pazymys : studentai.namuDarbai)
    {
        pazymys=rand()%10+1;
    }
    studentai.egzaminas=rand()%10+1;
}

string vardaiPavardes(vector<string>& vardai, vector<string>& pavardes) {

    int vardas = rand()%vardai.size();
    int pavarde = rand()%pavardes.size();

    cerr << vardas << " " << pavarde << endl;

    return vardai[vardas] + " " + pavardes[pavarde];
}

int main()
{
    srand(static_cast <unsigned int>(time(nullptr)));

    vector<Studentas> studentai; ///studentu duomenys
    char testi;
    int meniu=0;

    do
    {
        cout << "Pasirinkite buda:\n"
        << "1 - ivesti studentu duomenis rankiniu budu \n"
        << "2 - sugeneruoti pazymius \n"
        << "3 - generuoti ir pažymius ir studentų vardus, pavardės \n"
        << "4 - baigti darba \n" ;
        cin >> meniu;

    switch(meniu)
    {
    case 1:
         do
    {
        Studentas naujas;

        cout << "Iveskite studento varda: ";
        cin >> naujas.vardas;

        cout << "Iveskite studento pavarde: ";
        cin >> naujas.pavarde;

        naujas.namuDarbai.clear(); /// Isvalome namų darbų pazymiu vektoriu

        int pazymys;
        cout << "Iveskite namu darbu rezultatus (iveskite -1 jei baigete ivedima): ";
        int k=1;

        while(true)
        {
            cout << k << "-asis pazymys: ";
            if(cin >> pazymys&& pazymys != -1)
            {
                naujas.namuDarbai.push_back(pazymys);
                k++;
            }
            else if (pazymys==-1)
                break;
            else
            {
                cin.clear();
                cin.ignore(80,'\n');
                cout << "Neteisingas ivedimas. Iveskite teisinga skaiciu" << endl;
            }
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> naujas.egzaminas;

        studentai.push_back(naujas);

        cout << "Ar norite vesti dar vieno studento duomenis? (t/n): ";
        cin >> testi;
    }

    while (testi == 't');

    cout << endl << "Pasirinkite skaiciavimo buda: " << endl;
    cout << "1 - Vidurkis" << endl;
    cout << "2 - Mediana" << endl;
    int pasirinkimas;
    cin >> pasirinkimas;
    while(pasirinkimas!=1 && pasirinkimas!=2)
    {
        cout << "Iveskite teisinga pasirinkima: " ;
        cin.clear();
        cin.ignore(80,'\n');
    }

    bool naudotiVidurki = (pasirinkimas == 1); /// Jei pasirinkimas = 1, naudosime vidurkį, kitu atveju medianą

    cout << setw(13) << left << "Pavarde" << setw(13) << left << "Vardas" << setw(13) << left << "Galutinis (vid.)" << endl;
    cout << "----------------------------------------------------------------------" <<endl;
    for (int i=0; i<studentai.size(); i++)
    {
        double galutinis = skaiciuotiGalutini(studentai[i].namuDarbai, studentai[i].egzaminas, naudotiVidurki);
        cout << setw(13) << left << studentai[i].vardas << setw(13) << left << studentai[i].pavarde << setw(13) << left << fixed << setprecision(2) << galutinis << endl;
    }
        break;

    case 2:
        atsitiktiniai(studentai);
     break;

    case 3:
        atsitiktiniai(studentai);
        vector<string> vardai = {"Anna", "Gloria", "Sofia", "Guoda", "Aina", "Ugne"};
        vector<string> pavardes = {"Mockute", "Liuc", "Macaite", "Mickute", "Miller", "Peleda"};
        for(int i=0; i<5; i++)
        {
            string random_vardas = vardaiPavardes(vardai, pavardes);
            cout << "Atsitiktiniai" << i+1 <<random_vardas << endl;
        }
        break;
    default:
            cout << "Neteisingas pasirinkimas. Pasirinkite nuo 1 iki 4.\n";

    }
    }
    while(meniu!=4);
    return 0;
}

