#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>

class Studentas {
public:
    // Constructors
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde);
    // Destructor
    ~Studentas();
    // Copy Constructor
    Studentas(const Studentas& other);
    // Copy Assignment Operator
    Studentas& operator=(const Studentas& other);
    // Move Constructor
    Studentas(Studentas&& other) noexcept;
    // Move Assignment Operator
    Studentas& operator=(Studentas&& other) noexcept;

    // Getters and Setters
    void setVardas(const std::string& vardas);
    std::string getVardas() const;
    void setPavarde(const std::string& pavarde);
    std::string getPavarde() const;
    void setNamuDarbai(const std::vector<int>& nd);
    std::vector<int> getNamuDarbai() const;
    void setEgzaminas(int egzaminas);
    int getEgzaminas() const;

    // Calculations
    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    double skaiciuotiGalutini(bool naudotiVidurki) const;

    // Randomization
    void atsitiktiniai();
    void atsitiktiniaiStudentai();

    // Input/Output Operators
    friend std::ostream& operator<<(std::ostream& os, const Studentas& student);
    friend std::istream& operator>>(std::istream& is, Studentas& student);

private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
};

#endif
