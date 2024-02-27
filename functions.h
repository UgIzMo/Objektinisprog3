#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include "studentas.h"

double skaiciuotiVidurki(const std::vector<int>& nd);
double skaiciuotiMediana(const std::vector<int>& namuDarbai);
double skaiciuotiGalutini(const std::vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki);
void atsitiktiniai(Studentas& studentas);
void atsitiktiniaiStudentai(Studentas& studentas);
void nuskaitymas(std::vector<Studentas>& studentai, const std::string& failoPavadinimas);
bool rusiuotiPagalVarda(const Studentas& a, const Studentas& b);
bool rusiuotiPagalPavarde(const Studentas& a, const Studentas& b);
bool rusiuotiPagalGalutiniVidurki(const Studentas& a, const Studentas& b);
bool rusiuotiPagalGalutiniMediana(const Studentas& a, const Studentas& b);
void spausdinimas(const std::vector<Studentas>& studentai, const std::string& isvedimoFailas = "");
std::string pasirinktiFaila();

#endif // FUNCTIONS_H
