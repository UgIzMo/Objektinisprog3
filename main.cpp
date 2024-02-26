#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include "functions.h"
#include "studentas.h" // Move this line after including standard headers

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai; // Student data
    char testi;
    int meniu = 0;

    double visoLaikoSuma = 0.0;
    int testuSkaicius = 0;

    do {
        auto start = chrono::high_resolution_clock::now(); // Start timing

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
                    string vardas, pavarde;
                    vector<int> namuDarbai;
                    int pazymys, egzaminas;

                    cout << "Iveskite studento varda: ";
                    cin >> vardas;

                    cout << "Iveskite studento pavarde: ";
                    cin >> pavarde;

                    namuDarbai.clear();

                    cout << "Iveskite namu darbu rezultatus (iveskite 0 jei baigete ivedima): " << endl;
                    int k = 1;

                    while (true) {
                        cout << k << "-asis pazymys: ";
                        if (cin >> pazymys && pazymys != 0) {
                            namuDarbai.push_back(pazymys);
                            k++;
                        } else if (pazymys == 0)
                            break;
                        else {
                            cin.clear();
                            cin.ignore(80, '\n');
                            cout << "Neteisingas ivedimas. Iveskite teisinga skaiciu" << endl;
                        }
                    }

                    cout << "Iveskite egzamino rezultata: ";
                    cin >> egzaminas;

                    studentai.push_back(Studentas(vardas, pavarde, namuDarbai, egzaminas));

                    cout << "Ar norite vesti dar vieno studento duomenis? (t/n): ";
                    cin >> testi;
                } while (testi == 't');

                // Print student data
                for (const auto& studentas : studentai) {
                    cout << "Vardas: " << studentas.getVardas() << ", Pavarde: " << studentas.getPavarde() << endl;
                    cout << "Namu darbai: ";
                    for (int pazymys : studentas.getNamuDarbai()) {
                        cout << pazymys << " ";
                    }
                    cout << endl;
                    cout << "Egzaminas: " << studentas.getEgzaminas() << endl;
                }

                break;
            }
            case 2:
                // Implement case 2
                break;
            case 3:
                // Implement case 3
                break;
            case 4:
                // Implement case 4
                break;
            case 5:
                break;
        }

        auto end = chrono::high_resolution_clock::now(); // End timing
        chrono::duration<double> time = end - start; // Time duration
        double laikas = time.count(); // Time in seconds
        cout << "Visas sugaistas laikas: " << laikas << " s" << endl;

    } while (meniu != 5);

    double vidurkis = visoLaikoSuma / testuSkaicius; // Calculate the average time
    cout << "Keliu testu laiku vidurkis: " << vidurkis << " s" << endl;

    return 0;
}
