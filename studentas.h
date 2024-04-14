#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h" // Include base class if needed
#include <iostream>
#include <string>
#include <vector>

class Studentas : public Zmogus {
public:
    // Constructors
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde);

    // Destructor
    ~Studentas();

    // Getters and Setters
    void setVardas(const std::string& vardas);
    std::string getVardas() const;
    void setPavarde(const std::string& pavarde);
    std::string getPavarde() const;
    void setNamuDarbai(const std::vector<int>& nd);
    std::vector<int> getNamuDarbai() const;
    void setEgzaminas(int egzaminas);
    int getEgzaminas() const;

    // Implementing Zmogus virtual functions
    int getAge() const override; // Override Zmogus method to get age
    std::string getName() const override;

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
    int age; // Member variable to store age
};

#endif
