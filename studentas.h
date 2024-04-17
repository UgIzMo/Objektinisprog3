#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <iostream>
#include <vector>

class Studentas : public Human {
public:
    // konstruktorius
    Studentas();
    // konstruktorius su parametrais
    Studentas(const std::string& vardas, const std::string& pavarde);
    // copy konstruktorius
    Studentas(const Studentas& other);
    // copy priskyrimo operatorius
    Studentas& operator=(const Studentas& other);
    // move konstruktorius
    Studentas(Studentas&& other) noexcept;
    // move priskyrimo operatorius
    Studentas& operator=(Studentas&& other) noexcept;
    //destruktorius
    ~Studentas() override;

    void setVardas(const std::string& vardas) override;
    std::string getVardas() const override;

    void setPavarde(const std::string& pavarde) override;
    std::string getPavarde() const override;

    void setNamuDarbai(const std::vector<int>& nd) override;
    std::vector<int> getNamuDarbai() const override;

    void addNamuDarbas(int pazymys) override;

    void setEgzaminas(int egzaminas) override;
    int getEgzaminas() const override;

    double skaiciuotiVidurki() const override;
    double skaiciuotiMediana() const override;
    double skaiciuotiGalutini(bool naudotiVidurki) const override;

    void atsitiktiniai() override;
    void atsitiktiniaiStudentai() override;
    
    // testing
void testRuleOfFive();
    
    friend std::ostream& operator<<(std::ostream& os, const Studentas& student);
    friend std::istream& operator>>(std::istream& is, Studentas& student);

private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
};

#endif // STUDENTAS_H
