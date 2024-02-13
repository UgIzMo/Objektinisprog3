#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
};

int main()
{
    vector<Studentas> studentai; ///studentu duomenys

    char testi;
    int n; ///studentu sk
    cout << "Kiek yra studentu: ";
    cin>> n;
    for(int i=0; i<n; i++)
    {
        Studentas naujas;

        cout << "Iveskite studento varda: ";
        cin >> naujas.vardas;

        cout << "Iveskite studento pavarde: ";
        cin >> naujas.pavarde;

        naujas.namuDarbai.clear(); /// Išvalome namu darbu pazymiu vektoriu

        int pazymys;
        int m; ///namu darbu pazymiai
        cout << "Kiek yra namu darbu: ";
        cin>> m;

       for(int j=0; j<m; j++)
       {
           cout << j+1 << "-asis namu darbas: ";
           cin >> pazymys;
           naujas.namuDarbai.push_back(pazymys);
       }

        cout << "Iveskite egzamino rezultata: ";
        cin >> naujas.egzaminas;

        studentai.push_back(naujas);
    }

    return 0;
}

