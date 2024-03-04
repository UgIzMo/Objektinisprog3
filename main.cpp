#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <limits>
#include "studentas.h"
#include "functions.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai;
    char testi;
    int meniu = 0;

    double visoLaikoSuma = 0.0;
    int testuSkaicius = 0;

    do
    {
        auto start = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas

        try
        {
            cout << "Pasirinkite buda:\n"
                 << "1 - ivesti studentu duomenis rankiniu budu \n"
                 << "2 - sugeneruoti pazymius \n"
                 << "3 - generuoti ir pazymius ir studentu vardus, pavardes \n"
                 << "4 - skaityti is failo \n"
                 << "5 - generuoti failus \n"
                 << "6 - baigti darba \n";
            try
            {
                cin >> meniu;
                if (!cin)
                {
                    throw runtime_error("Netinkamas pasirinkimas. Iveskite skaiciu.");
                }
            }
            catch (const std::exception &e)
            {
                cerr << "Klaida: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // Skip executing the switch statement
            }

            switch (meniu)
            {
            case 1:
            {
                try
                {
                    do
                    {
                        Studentas studentas;

                        cout << "Iveskite studento varda: ";
                        cin >> studentas.vardas;

                        cout << "Iveskite studento pavarde: ";
                        cin >> studentas.pavarde;

                        studentas.namuDarbai.clear();

                        int pazymys;
                        cout << "Iveskite namu darbu rezultatus (iveskite 0 jei baigete ivedima): " << endl;
                        int k = 1;

                        while (true)
                        {
                            cout << k << "-asis pazymys: ";
                            try
                            {
                                cin >> pazymys;
                                if (!cin)
                                {
                                    throw runtime_error("Neteisingas ivedimas. Iveskite skaiciu.");
                                }
                                if (pazymys == 0)
                                {
                                    break;
                                }
                                if (pazymys < 1 || pazymys > 10)
                                {
                                    throw runtime_error("Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10.");
                                }
                                studentas.namuDarbai.push_back(pazymys);
                                k++;
                            }
                            catch (const std::exception &e)
                            {
                                cerr << "Klaida: " << e.what() << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }

                        cout << "Iveskite egzamino rezultata: ";
                        try
                        {
                            cin >> studentas.egzaminas;
                            if (!cin)
                            {
                                throw runtime_error("Neteisingas ivedimas. Iveskite skaiciu.");
                            }
                            if (studentas.egzaminas < 1 || studentas.egzaminas > 10)
                            {
                                throw runtime_error("Neteisingas egzamino rezultatas. Iveskite skaiciu nuo 1 iki 10.");
                            }
                        }
                        catch (const std::exception &e)
                        {
                            cerr << "Klaida: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue; // Skip adding invalid data to the vector
                        }

                        studentai.push_back(studentas);

                        cout << "Ar norite ivesti dar vieno studento duomenis? (t/n): ";
                        cin >> testi;
                    } while (testi == 't');

                    spausdinimas(studentai);
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida ivedant duomenis: " << e.what() << endl;
                }
                break;
            }

            case 2:
            {
                try
                {
                    for (auto &studentas : studentai)
                    {
                        auto startTest = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

                        atsitiktiniai(studentas);
                        cout << "Studentas: \nEgzaminas: " << studentas.egzaminas
                             << "\nNamu darbu pazymiai: ";
                        for (int pazymys : studentas.namuDarbai)
                        {
                            cout << pazymys << " ";
                        }
                        cout << "\n\n";

                        auto endTest = chrono::high_resolution_clock::now();     // Baigiamas laiko skaiciavimas testui
                        chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
                        double laikasTest = timeTest.count();                    // Laikas testui
                        visoLaikoSuma += laikasTest;                             // Pridedamas laikas prie viso laiko sumos
                        testuSkaicius++;                                         // Pridedamas vienetinis testų skaičius
                    }
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida: " << e.what() << endl;
                }
                break;
            }

            case 3:
            {
                try
                {
                    auto startTest = chrono::high_resolution_clock::now(); // Pradedamas laiko skaiciavimas testui

                    cout << fixed << setprecision(2);
                    cout << "Studentu galutiniai balai:\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "Vardas" << setw(15) << "Pavardė" << setw(20) << "Galutinis (Vid.)"
                         << setw(20) << "Galutinis (Med.)\n";
                    cout << "----------------------------------------------------------------\n";

                    for (int i = 0; i < 6; i++)
                    {
                        Studentas naujasStudentas;
                        atsitiktiniaiStudentai(naujasStudentas);
                        studentai.push_back(naujasStudentas);

                        double galutinisVidurkis = skaiciuotiGalutini(naujasStudentas.namuDarbai, naujasStudentas.egzaminas, true);
                        double galutineMediana = skaiciuotiGalutini(naujasStudentas.namuDarbai, naujasStudentas.egzaminas, false);
                        cout << left << setw(15) << naujasStudentas.vardas << setw(15)
                             << naujasStudentas.pavarde << setw(20) << galutinisVidurkis << setw(20)
                             << galutineMediana << "\n";
                    }
                    cout << "----------------------------------------------------------------\n";

                    auto endTest = chrono::high_resolution_clock::now();     // Baigiamas laiko skaiciavimas testui
                    chrono::duration<double> timeTest = endTest - startTest; // Laikas testui
                    double laikasTest = timeTest.count();                    // Laikas testui
                    visoLaikoSuma += laikasTest;                             // Pridedamas laikas prie viso laiko sumos
                    testuSkaicius++;                                         // Pridedamas vienetinis testų skaičius
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida: " << e.what() << endl;
                }
                break;
            }

            case 4:
            {
                try
                {
                    auto startTest = chrono::high_resolution_clock::now();
                    nuskaitymas(studentai, pasirinktiFaila());
                    spausdinimas(studentai, "isvedimas.txt");
                    auto endTest = chrono::high_resolution_clock::now();
                    chrono::duration<double> timeTest = endTest - startTest;
                    double laikasTest = timeTest.count();
                    visoLaikoSuma += laikasTest;
                    testuSkaicius++;
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida skaitymo/metimo metu: " << e.what() << endl;
                }
                break;
            }

            case 5:
            {
                try
                {
                    generateFiles();
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Klaida generuojant failus: " << e.what() << std::endl;
                }
                break;
            }

            case 6:
                break;

            default:
                cout << "Netinkamas pasirinkimas" << endl;
                break;
            }
        }
        catch (const std::exception &e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        auto end = chrono::high_resolution_clock::now(); // Baigiamas laiko skaiciavimas
        chrono::duration<double> time = end - start;     // Laikas
        double laikas = time.count();                    // Issaugojamas laikas
        cout << "Visas sugaistas laikas: " << laikas << " s" << endl;

    } while (meniu != 5);

    double vidurkis = visoLaikoSuma / testuSkaicius;                    // Suskaiciuojamas laiku vidurkis
    cout << "Keliu testu laiku vidurkis: " << vidurkis << " s" << endl; // Isvedamas laiku vidurkis

    return 0;
}
