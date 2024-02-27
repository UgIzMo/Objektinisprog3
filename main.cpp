#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "studentas.h"
#include "functions.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

     vector<Studentas> studentai; ///studentu duomenys
    char testi;
    int meniu = 0;

    double visoLaikoSuma = 0.0;
    int testuSkaicius = 0;

    do {
        auto start = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas

         cout << "Pasirinkite buda:\n"
                  << "1 - ivesti studentu duomenis rankiniu budu \n"
                  << "2 - sugeneruoti pazymius \n"
                  << "3 - generuoti ir pazymius ir studentu vardus, pavardes \n"
                  << "4 - skaityti is failo \n"
                  << "5 - baigti darba \n";
         cin >> meniu;

        switch (meniu) {
            case 1: {
                do {
                    Studentas studentas;

                     cout << "Iveskite studento varda: ";
                     cin >> studentas.vardas;

                     cout << "Iveskite studento pavarde: ";
                     cin >> studentas.pavarde;

                    studentas.namuDarbai.clear(); /// Isvalome namų darbu pazymiu vektoriu

                    int pazymys;
                     cout << "Iveskite namu darbu rezultatus (iveskite 0 jei baigete ivedima): " <<  endl;
                    int k = 1;

                    while (true) {
                         cout << k << "-asis pazymys: ";
                        if ( cin >> pazymys && pazymys != 0) {
                            studentas.namuDarbai.push_back(pazymys);
                            k++;
                        } else if (pazymys == 0)
                            break;
                        else {
                             cin.clear();
                             cin.ignore(80, '\n');
                             cout << "Neteisingas ivedimas. Iveskite teisinga skaiciu" <<  endl;
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
            case 2: {
                for (auto &studentas : studentai) {
                    auto startTest =  chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

                    atsitiktiniai(studentas);
                     cout << "Studentas: \nEgzaminas: " << studentas.egzaminas
                              << "\nNamu darbu pazymiai: ";
                    for (int pazymys : studentas.namuDarbai) {
                         cout << pazymys << " ";
                    }
                     cout << "\n\n";

                    auto endTest =  chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas testui
                     chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
                    double laikasTest = timeTest.count(); // Laikas testui
                    visoLaikoSuma += laikasTest; // Pridedamas laikas prie viso laiko sumos
                    testuSkaicius++; // Pridedamas vienetinis testų skaičius
                }
                break;
            }

            case 3: {
                auto startTest =  chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

                 cout <<  fixed <<  setprecision(2);
                 cout << "Studentu galutiniai balai:\n";
                 cout << "----------------------------------------------------------------\n";
                 cout << "Vardas" <<  setw(15) << "Pavarde" <<  setw(20) << "Galutinis (Vid.)"
                          <<  setw(20) << "Galutinis (Med.)\n";
                 cout << "----------------------------------------------------------------\n";

                for (int i = 0; i < 6; i++) {
                    Studentas naujasStudentas;
                    atsitiktiniaiStudentai(naujasStudentas);
                    studentai.push_back(naujasStudentas);

                    double galutinisVidurkis = skaiciuotiGalutini(naujasStudentas.namuDarbai, naujasStudentas.egzaminas, true);
                    double galutineMediana = skaiciuotiGalutini(naujasStudentas.namuDarbai, naujasStudentas.egzaminas, false);
                     cout <<  left <<  setw(15) << naujasStudentas.vardas <<  setw(15)
                              << naujasStudentas.pavarde <<  setw(20) << galutinisVidurkis <<  setw(20)
                              << galutineMediana << "\n";
                }
                 cout << "----------------------------------------------------------------\n";

                auto endTest =  chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas testui
                 chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
                double laikasTest = timeTest.count(); // Laikas testui
                visoLaikoSuma += laikasTest; // Pridedamas laikas prie viso laiko sumos
                testuSkaicius++; // Pridedamas vienetinis testų skaičius
                break;
            }
            case 4: {
                auto startTest =  chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

                nuskaitymas(studentai, pasirinktiFaila());
                spausdinimas(studentai, "isvedimas.txt");

                auto endTest =  chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas testui
                 chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
                double laikasTest = timeTest.count(); // Laikas testui
                visoLaikoSuma += laikasTest; // Pridedamas laikas prie viso laiko sumos
                testuSkaicius++; // Pridedamas vienetinis testu skaicius
                break;
            }
            case 5:
                break;
        }

        auto end =  chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas
         chrono::duration<double> time = end - start; // Laikas
        double laikas = time.count(); // Issaugojamas laikas
         cout << "Visas sugaistas laikas: " << laikas << " s" <<  endl;

    } while (meniu != 5);

    double vidurkis = visoLaikoSuma / testuSkaicius; // Suskaiciuojamas laiku vidurkis
     cout << "Keliu testu laiku vidurkis: " << vidurkis << " s" <<  endl; // Isvedamas laiku vidurkis

    return 0;
}
