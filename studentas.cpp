#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Abstract Base Class: Person
class Person {
public:
    virtual ~Person() = default;  // Virtual destructor
    virtual std::string getVardas() const = 0;
    virtual void setVardas(const std::string& vardas) = 0;
    virtual std::string getPavarde() const = 0;
    virtual void setPavarde(const std::string& pavarde) = 0;
    virtual std::vector<int> getNamuDarbai() const = 0;
    virtual void setNamuDarbai(const std::vector<int>& nd) = 0;
    virtual int getEgzaminas() const = 0;
    virtual void setEgzaminas(int egzaminas) = 0;

    virtual void addNamuDarbas(int pazymys) = 0;
    virtual double skaiciuotiVidurki() const = 0;
    virtual double skaiciuotiMediana() const = 0;
    virtual double skaiciuotiGalutini(bool naudotiVidurki) const = 0;
    virtual void atsitiktiniai() = 0;
    virtual void atsitiktiniaiStudentai() = 0;
};

// Derived Class: Student
class Student : public Person {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;

public:
    // Constructors
    Student() : egzaminas(0) {}
    Student(const std::string& vardas, const std::string& pavarde)
        : vardas(vardas), pavarde(pavarde), egzaminas(0) {}

    // Destructor
    ~Student() override {
        namuDarbai.clear();
        vardas.clear();
        pavarde.clear();
        egzaminas = 0;
    }

    // Copy Constructor
    Student(const Student& other)
        : vardas(other.vardas), pavarde(other.pavarde),
          namuDarbai(other.namuDarbai), egzaminas(other.egzaminas) {}

    // Assignment Operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            namuDarbai = other.namuDarbai;
            egzaminas = other.egzaminas;
        }
        return *this;
    }

    // Move Constructor
    Student(Student&& other) noexcept
        : vardas(std::move(other.vardas)), pavarde(std::move(other.pavarde)),
          namuDarbai(std::move(other.namuDarbai)), egzaminas(other.egzaminas) {
        other.egzaminas = 0;
    }

    // Move Assignment Operator
    Student& operator=(Student&& other) noexcept {
        if (this != &other) {
            vardas = std::move(other.vardas);
            pavarde = std::move(other.pavarde);
            namuDarbai = std::move(other.namuDarbai);
            egzaminas = other.egzaminas;
            other.egzaminas = 0;
        }
        return *this;
    }

    // Getter and Setter Methods
    std::string getVardas() const override { return vardas; }
    void setVardas(const std::string& vardas) override { this->vardas = vardas; }

    std::string getPavarde() const override { return pavarde; }
    void setPavarde(const std::string& pavarde) override { this->pavarde = pavarde; }

    std::vector<int> getNamuDarbai() const override { return namuDarbai; }
    void setNamuDarbai(const std::vector<int>& nd) override { namuDarbai = nd; }

    int getEgzaminas() const override { return egzaminas; }
    void setEgzaminas(int egzaminas) override { this->egzaminas = egzaminas; }

    void addNamuDarbas(int pazymys) override { namuDarbai.push_back(pazymys); }

    // Calculation Methods
    double skaiciuotiVidurki() const override {
        double suma = 0.0;
        for (int pazymys : namuDarbai) {
            suma += pazymys;
        }
        return namuDarbai.empty() ? 0.0 : suma / namuDarbai.size();
    }

    double skaiciuotiMediana() const override {
        if (namuDarbai.empty()) return 0.0;
        std::vector<int> tempNamuDarbai = namuDarbai;
        std::sort(tempNamuDarbai.begin(), tempNamuDarbai.end());
        int dydis = tempNamuDarbai.size();
        return (dydis % 2 == 0) ? (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0
                                : tempNamuDarbai[dydis / 2];
    }

    double skaiciuotiGalutini(bool naudotiVidurki) const override {
        double galutinis = naudotiVidurki ? (0.4 * skaiciuotiVidurki() + 0.6 * egzaminas)
                                            : (0.4 * skaiciuotiMediana() + 0.6 * egzaminas);
        return galutinis;
    }

    void atsitiktiniai() override {
        namuDarbai.resize(rand() % 10 + 1);
        for (int& pazymys : namuDarbai) {
            pazymys = rand() % 10 + 1;
        }
        egzaminas = rand() % 10 + 1;
    }

    void atsitiktiniaiStudentai() override {
        const char* vardai[] = {"Morta", "Aina", "Guoda", "Marija", "Paulina"};
        const char* pavardes[] = {"Petraityte", "Jurksaityte", "Mockute", "Macaite", "Liekyte"};
        int vardasIndex = rand() % 5; // 5, nes masyvas prasideda nuo 0
        int pavardeIndex = rand() % 5; // 5, nes masyvas prasideda nuo 0
        vardas = vardai[vardasIndex];
        pavarde = pavardes[pavardeIndex];
        atsitiktiniai();
    }

    // Output Operator (Serialization)
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.vardas << " " << student.pavarde << " " << student.egzaminas << " ";
        for (int pazymys : student.namuDarbai) {
            os << pazymys << " ";
        }
        return os;
    }

    // Input Operator (Deserialization)
    friend std::istream& operator>>(std::istream& is, Student& student) {
        is >> student.vardas >> student.pavarde >> student.egzaminas;
        student.namuDarbai.clear();
        int pazymys;
        while (is >> pazymys) {
            student.namuDarbai.push_back(pazymys);
        }
        return is;
    }
};
