#include "studentas.h"
#include <algorithm>

double skaiciuotiVidurki(const std::vector<int>& nd) {
    if (nd.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    return suma / nd.size();
}

double skaiciuotiMediana(const std::vector<int>& namuDarbai) {
    if (namuDarbai.empty()) return 0;
    std::vector<int> tempNamuDarbai = namuDarbai;
    std::sort(tempNamuDarbai.begin(), tempNamuDarbai.end());
    int dydis = tempNamuDarbai.size();
    if (dydis % 2 == 0) {
        return (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0;
    } else {
        return tempNamuDarbai[dydis / 2];
    }
}

double skaiciuotiGalutini(const std::vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki) {
    if (naudotiVidurki) {
        double vidurkis = skaiciuotiVidurki(namuDarbai);
        return 0.4 * vidurkis + 0.6 * egzaminas;
    } else {
        return 0.4 * skaiciuotiMediana(namuDarbai) + 0.6 * egzaminas;
    }
}

void atsitiktiniai(Studentas& studentas) {
    studentas.namuDarbai.resize(rand() % 10 + 1);
    for (int& pazymys : studentas.namuDarbai) {
        pazymys = rand() % 10 + 1;
    }
    studentas.egzaminas = rand() % 10 + 1;
}

void atsitiktiniaiStudentai(Studentas& studentas) {
    const char* vardai[] = {"Ana", "Gloria", "Sofia", "Ugne", "Aina", "Guoda"};
    const char* pavardes[] = {"Mockute", "Liuc", "Mickute", "Macaite", "Migonyte", "Peleda"};
    int vardasIndex = rand() % 6;
    int pavardeIndex = rand() % 6;
    studentas.vardas = vardai[vardasIndex];
    studentas.pavarde = pavardes[pavardeIndex];
    atsitiktiniai(studentas);
}