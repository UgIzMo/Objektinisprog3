#include "studentas.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

// Constructors
Studentas::Studentas() : egzaminas(0) {}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vardas(vardas), pavarde(pavarde), egzaminas(0) {}

// Destructor
Studentas::~Studentas() {
    namuDarbai.clear();
}

// Copy Constructor
Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde), namuDarbai(other.namuDarbai), egzaminas(other.egzaminas) {}

// Copy Assignment Operator
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        namuDarbai = other.namuDarbai;
        egzaminas = other.egzaminas;
    }
    return *this;
}

// Move Constructor
Studentas::Studentas(Studentas&& other) noexcept
    : vardas(std::move(other.vardas)), pavarde(std::move(other.pavarde)),
      namuDarbai(std::move(other.namuDarbai)), egzaminas(other.egzaminas) {}

// Move Assignment Operator
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        vardas = std::move(other.vardas);
        pavarde = std::move(other.pavarde);
        namuDarbai = std::move(other.namuDarbai);
        egzaminas = other.egzaminas;
    }
    return *this;
}

// Getters and Setters
void Studentas::setVardas(const std::string& vardas) {
    this->vardas = vardas;
}

std::string Studentas::getVardas() const {
    return vardas;
}

void Studentas::setPavarde(const std::string& pavarde) {
    this->pavarde = pavarde;
}

std::string Studentas::getPavarde() const {
    return pavarde;
}

void Studentas::setNamuDarbai(const std::vector<int>& nd) {
    namuDarbai = nd;
}

std::vector<int> Studentas::getNamuDarbai() const {
    return namuDarbai;
}

void Studentas::setEgzaminas(int egzaminas) {
    this->egzaminas = egzaminas;
}

int Studentas::getEgzaminas() const {
    return egzaminas;
}

// Calculations
double Studentas::skaiciuotiVidurki() const {
    double suma = 0.0;
    for (int pazymys : namuDarbai) {
        suma += pazymys;
    }
    return namuDarbai.empty() ? 0.0 : suma / namuDarbai.size();
}

double Studentas::skaiciuotiMediana() const {
    if (namuDarbai.empty()) return 0.0;
    std::vector<int> tempNamuDarbai = namuDarbai;
    std::sort(tempNamuDarbai.begin(), tempNamuDarbai.end());
    int dydis = tempNamuDarbai.size();
    return (dydis % 2 == 0) ? (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0 : tempNamuDarbai[dydis / 2];
}

double Studentas::skaiciuotiGalutini(bool naudotiVidurki) const {
    double galutinis = naudotiVidurki ? (0.4 * skaiciuotiVidurki() + 0.6 * egzaminas) : (0.4 * skaiciuotiMediana() + 0.6 * egzaminas);
    return galutinis;
}

// Randomization
void Studentas::atsitiktiniai() {
    namuDarbai.resize(rand() % 10 + 1);
    for (int& pazymys : namuDarbai) {
        pazymys = rand() % 10 + 1;
    }
    egzaminas = rand() % 10 + 1;
}

void Studentas::atsitiktiniaiStudentai() {
    const char* vardai[] = {"Ana", "Gloria", "Sofia", "Ugne", "Aina", "Guoda"};
    const char* pavardes[] = {"Mockute", "Liuc", "Mickute", "Macaite", "Migonyte", "Peleda"};
    int vardasIndex = rand() % 6;
    int pavardeIndex = rand() % 6;
    vardas = vardai[vardasIndex];
    pavarde = pavardes[pavardeIndex];
    atsitiktiniai();
}

// Output Operator (Serialization)
std::ostream& operator<<(std::ostream& os, const Studentas& student) {
    os << student.vardas << " " << student.pavarde << " " << student.egzaminas << " ";
    for (int pazymys : student.namuDarbai) {
        os << pazymys << " ";
    }
    return os;
}

// Input Operator (Deserialization)
std::istream& operator>>(std::istream& is, Studentas& student) {
    is >> student.vardas >> student.pavarde >> student.egzaminas;
    student.namuDarbai.clear();
    int pazymys;
    while (is >> pazymys) {
        student.namuDarbai.push_back(pazymys);
    }
    return is;
}
