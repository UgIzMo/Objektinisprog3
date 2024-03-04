#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

struct Studentas
{
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
};

double skaiciuotiVidurki(const std::vector<int>& nd);
double skaiciuotiMediana(const std::vector<int>& namuDarbai);
double skaiciuotiGalutini(const std::vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki);
void atsitiktiniai(Studentas& studentas);
void atsitiktiniaiStudentai(Studentas& studentas);

#endif // STUDENTAS_H
