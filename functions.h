#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

#include "studentas.h"

using namespace std;

double skaiciuotiVidurki(const vector<int>& nd);
double skaiciuotiMediana(const vector<int>& namuDarbai);
double skaiciuotiGalutini(const vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki);
void atsitiktiniai(Studentas& studentas);
void atsitiktiniaiStudentai(Studentas& studentas);
void nuskaitymas(vector<Studentas>& studentai, const string& failoPavadinimas);
bool rusiuotiPagalVarda(const Studentas& a, const Studentas& b);
bool rusiuotiPagalPavarde(const Studentas& a, const Studentas& b);
bool rusiuotiPagalGalutiniVidurki(const Studentas& a, const Studentas& b);
bool rusiuotiPagalGalutiniMediana(const Studentas& a, const Studentas& b);
void spausdinimas(const vector<Studentas>& studentai, const string& isvedimoFailas = "");
string pasirinktiFaila();

#endif
