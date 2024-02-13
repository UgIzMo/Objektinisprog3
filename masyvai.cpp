#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    int* namuDarbai;
    int namuDarbuDydis;
    int egzaminas;
};

double skaiciuotiVidurki(int* namuDarbai, int dydis)
{
    if (dydis == 0)
        return 0;
    double suma = 0.0;
    for (int i = 0; i < dydis; i++)
    {
        suma += namuDarbai[i];
    }
    return suma / dydis;
}

double skaiciuotiMediana(int* namuDarbai, int dydis)
{
    if (dydis == 0)
        return 0;

    sort(namuDarbai, namuDarbai + dydis);
    int vidurinisIndeksas = dydis / 2;
    if (dydis % 2 == 0)
    {
        return (namuDarbai[vidurinisIndeksas - 1] + namuDarbai[vidurinisIndeksas]) / 2.0;
    }
    else
    {
        return namuDarbai[vidurinisIndeksas];
    }
}

double skaiciuotiGalutini(int* namuDarbai, int dydis, int egzaminas, bool naudotiVidurki)
{
    if (naudotiVidurki)
    {
        if (dydis == 0)
            return egzaminas;
        double vidurkis = skaiciuotiVidurki(namuDarbai, dydis);
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }
    else
    {
        if (dydis == 0)
            return egzaminas;
        return 0.4 * skaiciuotiMediana(namuDarbai, dydis) + 0.6 * egzaminas;
    }
}

void atsitiktiniai(Studentas *studentas)
{
    studentas->namuDarbuDydis = rand() % 10 + 1;
    studentas->namuDarbai = new int[studentas->namuDarbuDydis];
    for (int i = 0; i < studentas->namuDarbuDydis; i++)
    {
        studentas->namuDarbai[i] = rand() % 10 + 1;
    }
    studentas->egzaminas = rand() % 10 + 1;
}

void atsitiktiniaiStudentai(Studentas *studentas)
{
    const string vardai[] = {"Anna", "Gloria", "Sofia", "Ugne", "Aina", "Guoda"};
    const string pavardes[] = {"Mockute", "Liuc", "Mickute", "Macaite", "Miller", "Peleda"};

    int vardasIndex = rand() % 6;
    int pavardeIndex = rand() % 6;

    studentas->vardas = vardai[vardasIndex];
    studentas->pavarde = pavardes[pavardeIndex];

    atsitiktiniai(studentas);
}

int main()
{
    srand(time(nullptr));
    Studentas* studentai = nullptr;
    int studentuSkaicius = 0;
    char testi;
    int meniu, m = 0; ///stud sk-m

    do
    {
        cout << "Pasirinkite buda:\n"
             << "1 - ivesti studentu duomenis rankiniu budu \n"
             << "2 - sugeneruoti pazymius \n"
             << "3 - generuoti ir pazymius ir studentu vardus, pavardes \n"
             << "4 - baigti darba \n";
        cin >> meniu;

        if(meniu==4) break;

        switch (meniu)
        {
        case 1:
        {
            do
            {
                Studentas naujas;

                cout << "Iveskite studento varda: ";
                cin >> naujas.vardas;

                cout << "Iveskite studento pavarde: ";
                cin >> naujas.pavarde;

                naujas.namuDarbuDydis = 0;
                naujas.namuDarbai = nullptr;
                int pazymys;
                cout << "Iveskite namu darbu rezultatus (iveskite -1 jei baigete ivedima): " << endl;
                int k = 0;

                while (true)
                {
                    cout << ++k << "-asis pazymys: ";
                    if (cin >> pazymys && pazymys != -1)
                    {
                        if (pazymys < 0 || pazymys > 10)
                        {
                            cout << "Netinkamas ivedimas. Iveskite teisinga skaiciu." << endl;
                            continue;
                        }
                        int* naujiNamuDarbai = new int[naujas.namuDarbuDydis + 1];
                        for (int i = 0; i < naujas.namuDarbuDydis; i++)
                            naujiNamuDarbai[i] = naujas.namuDarbai[i];
                        naujiNamuDarbai[naujas.namuDarbuDydis++] = pazymys;
                        delete[] naujas.namuDarbai;
                        naujas.namuDarbai = naujiNamuDarbai;
                    }
                    else if (pazymys == -1)
                        break;
                    else
                    {
                        cin.clear();
                        cin.ignore(80, '\n');
                        cout << "Netinkamas ivedimas. Iveskite teisinga skaiciu." << endl;
                    }
                }

                cout << "Iveskite egzamino rezultata: ";
                cin >> naujas.egzaminas;

                Studentas* naujasStudentas = new Studentas[studentuSkaicius + 1];
                for (int i = 0; i < studentuSkaicius; i++)
                    naujasStudentas[i] = studentai[i];
                naujasStudentas[studentuSkaicius++] = naujas;
                delete[] studentai;
                studentai = naujasStudentas;

                cout << "Ar norite vesti dar vieno studento duomenis? (t/n): ";
                cin >> testi;
            }
            while (testi == 't');

            cout << endl << "Pasirinkite skaiciavimo buda: " << endl;
            cout << "1 - Vidurkis" << endl;
            cout << "2 - Mediana" << endl;
            int pasirinkimas;
            cin >> pasirinkimas;
            while (pasirinkimas != 1 && pasirinkimas != 2)
            {
                cout << "Iveskite teisinga pasirinkima: ";
                cin.clear();
                cin.ignore(80, '\n');
            }

            bool naudotiVidurki = (pasirinkimas == 1);

            cout << setw(13) << left << "Pavarde" << setw(13) << left << "Vardas" << setw(13) << left << "Galutinis (vid./med.)" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            for (int i = 0; i < studentuSkaicius; i++)
            {
                double galutinis = skaiciuotiGalutini(studentai[i].namuDarbai, studentai[i].namuDarbuDydis, studentai[i].egzaminas, naudotiVidurki);
                cout << setw(13) << left << studentai[i].vardas << setw(13) << left << studentai[i].pavarde << setw(13) << left << fixed << setprecision(2) << galutinis << endl;
                delete[] studentai[i].namuDarbai;
            }
            delete[] studentai;
            studentai = nullptr;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 6; ++i)
            {
                Studentas naujasStudentas;
                atsitiktiniai(&naujasStudentas);
                studentai = new Studentas[studentuSkaicius + 1];
                for (int j = 0; j < studentuSkaicius; j++)
                    studentai[j] = studentai[j];
                studentai[studentuSkaicius++] = naujasStudentas;
                cout << "Studentas: " << naujasStudentas.vardas << " " << naujasStudentas.pavarde << "\nEgzaminas: " << naujasStudentas.egzaminas << "\nNamu darbu pazymiai: ";
                for (int j = 0; j < 10; ++j)
                {
                    cout << naujasStudentas.namuDarbai[j] << " ";
                }
                cout << "\n\n";
            }
            break;
        }
        case 3:
        {
            char testi = 't';
            do
            {
                studentai = (Studentas *)realloc(studentai, (m + 1) * sizeof(Studentas));
                atsitiktiniaiStudentai(&studentai[m]);
                m++;
                cout << "Sugeneruotas naujas studentas. Ar norite generuoti dar viena? (t/n): ";
                cin >> testi;
            }
            while (testi == 't');
            break;

        }
        }
    }
    while (meniu != 4);
    return 0;
}
