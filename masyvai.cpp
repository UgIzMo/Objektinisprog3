#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    int* namuDarbai;
    int namuDarbuDydis;
    int egzaminas;
};

double skaiciuotiVidurki(const int* namuDarbai, int dydis) {
    if (dydis == 0)
        return 0.0;
    double suma = 0.0;
    for (int i = 0; i < dydis; i++) {
        suma += namuDarbai[i];
    }
    return suma / dydis;
}

double skaiciuotiMediana(int* namuDarbai, int dydis) {
    if (dydis == 0)
        return 0.0;
    sort(namuDarbai, namuDarbai + dydis);
    if (dydis % 2 == 0) {
        return (namuDarbai[dydis / 2 - 1] + namuDarbai[dydis / 2]) / 2.0;
    } else {
        return namuDarbai[dydis / 2];
    }
}

double skaiciuotiGalutini(const int* namuDarbai, int namuDarbuDydis, int egzaminas, bool naudotiVidurki) {
    if (naudotiVidurki) {
        return 0.4 * skaiciuotiVidurki(namuDarbai, namuDarbuDydis) + 0.6 * egzaminas;
    } else {
        int* kopija = new int[namuDarbuDydis];
        for (int i = 0; i < namuDarbuDydis; ++i) {
            kopija[i] = namuDarbai[i];
        }
        double rezultatas = 0.4 * skaiciuotiMediana(kopija, namuDarbuDydis) + 0.6 * egzaminas;
        delete[] kopija;
        return rezultatas;
    }
}

void atsitiktiniai(Studentas& studentas) {
    studentas.namuDarbuDydis = rand() % 10 + 1;
    studentas.namuDarbai = new int[studentas.namuDarbuDydis];
    for (int i = 0; i < studentas.namuDarbuDydis; i++) {
        studentas.namuDarbai[i] = rand() % 10 + 1;
    }
    studentas.egzaminas = rand() % 10 + 1;
}

void atsitiktiniaiStudentai(Studentas& studentas) {
    const string vardai[] = {"Anna", "Gloria", "Sofia", "Ugne", "Aina", "Guoda"};
    const string pavardes[] = {"Mockute", "Liuc", "Mickute", "Macaite", "Miller", "Peleda"};

    studentas.vardas = vardai[rand() % 6];
    studentas.pavarde = pavardes[rand() % 6];
    atsitiktiniai(studentas);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Studentas* studentai = nullptr;
    int studentuSkaicius = 0;
    char testi = 'n';
    int meniu;

    do {
        cout << "Pasirinkite buda:\n"
             << "1 - ivesti studentu duomenis rankiniu budu\n"
             << "2 - sugeneruoti pazymius\n"
             << "3 - generuoti ir pazymius ir studentu vardus, pavardes\n"
             << "4 - baigti darba\n";
        cin >> meniu;

        switch (meniu) {
            case 1: {
                do {
                    Studentas naujas;
                    naujas.namuDarbai = nullptr;
                    naujas.namuDarbuDydis = 0;

                    cout << "Iveskite studento varda: ";
                    cin >> naujas.vardas;

                    cout << "Iveskite studento pavarde: ";
                    cin >> naujas.pavarde;

                    cout << "Iveskite namu darbu rezultatus (0 baigia ivedima): ";
                    int pazymys;
                    while (cin >> pazymys && pazymys != 0) {
                        int* laikina = new int[naujas.namuDarbuDydis + 1];
                        for (int i = 0; i < naujas.namuDarbuDydis; i++) {
                            laikina[i] = naujas.namuDarbai[i];
                        }
                        laikina[naujas.namuDarbuDydis] = pazymys;
                        delete[] naujas.namuDarbai;
                        naujas.namuDarbai = laikina;
                        ++naujas.namuDarbuDydis;
                    }

                    cout << "Iveskite egzamino rezultata: ";
                    cin >> naujas.egzaminas;

                    Studentas* laikina = new Studentas[studentuSkaicius + 1];
                    for (int i = 0; i < studentuSkaicius; i++) {
                        laikina[i] = studentai[i];
                    }
                    laikina[studentuSkaicius] = naujas;
                    delete[] studentai;
                    studentai = laikina;
                    ++studentuSkaicius;

                    cout << "Ar norite ivesti dar viena studenta? (t/n): ";
                    cin >> testi;
                } while (testi == 't');
                break;
            }
            case 2:
            case 3: {
                int kiekis = (meniu == 2) ? 1 : 0;
                cout << "Kiek studentu sugeneruoti: ";
                cin >> kiekis;
                Studentas* laikina = new Studentas[studentuSkaicius + kiekis];
                for (int i = 0; i < studentuSkaicius; i++) {
                    laikina[i] = studentai[i];
                }
                delete[] studentai;
                studentai = laikina;
                for (int i = 0; i < kiekis; i++) {
                    if (meniu == 3) {
                        atsitiktiniaiStudentai(studentai[studentuSkaicius + i]);
                    } else {
                        atsitiktiniai(studentai[studentuSkaicius + i]);
                    }
                }
                studentuSkaicius += kiekis;
                break;
            }
            case 4:
                cout << "Baigti darba.\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
                break;
        }
    } while (meniu != 4);
        cout << "Vardas       Pavarde       Galutinis (Vid.)  Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for (int i = 0; i < studentuSkaicius; i++)
        {
            double vidurkisGalutinis = skaiciuotiGalutini(studentai[i].namuDarbai, studentai[i].namuDarbuDydis, studentai[i].egzaminas, true);
            double medianaGalutinis = skaiciuotiGalutini(studentai[i].namuDarbai, studentai[i].namuDarbuDydis, studentai[i].egzaminas, false);

            cout << setw(12) << left << studentai[i].vardas << setw(13) << left << studentai[i].pavarde
                << setw(17) << left << fixed << setprecision(2) << vidurkisGalutinis
                << setw(18) << left << fixed << setprecision(2) << medianaGalutinis << endl;
        }

    // isvalome dinamine atminti
    for (int i = 0; i < studentuSkaicius; ++i) {
        delete[] studentai[i].namuDarbai;
    }
    delete[] studentai;

    return 0;
}
