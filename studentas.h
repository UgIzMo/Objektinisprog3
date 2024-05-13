#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <iostream>
#include <vector>

/**
 * @brief Klasė Studentas atstovauja studentą, paveldintį iš klasės Žmogus.
 */
class Studentas : public Human {
public:
    /**
     * @brief Numatytasis Studentas klasės konstruktorius.
     */
    Studentas();
    
    /**
     * @brief Konstruktorius su parametrais Studentas klasėje.
     * @param vardas Studento vardas.
     * @param pavarde Studento pavardė.
     */
    Studentas(const std::string& vardas, const std::string& pavarde);
    
    /**
     * @brief Studentas klasės kopijavimo konstruktorius.
     * @param other Kita Studentas klasės instancija.
     */
    Studentas(const Studentas& other);
    
    /**
     * @brief Studentas klasės kopijavimo priskyrimo operatorius.
     * @param other Kita Studentas klasės instancija.
     * @return Nuoroda į priskirtą Studentas instanciją.
     */
    Studentas& operator=(const Studentas& other);
    
    /**
     * @brief Studentas klasės perkėlimo konstruktorius.
     * @param other Kita Studentas klasės instancija.
     */
    Studentas(Studentas&& other) noexcept;
    
    /**
     * @brief Studentas klasės perkėlimo priskyrimo operatorius.
     * @param other Kita Studentas klasės instancija.
     * @return Nuoroda į perkeltą Studentas instanciją.
     */
    Studentas& operator=(Studentas&& other) noexcept;
    
    /**
     * @brief Studentas klasės destruktorius.
     */
    ~Studentas() override;

    /**
     * @brief Nustato studento vardą.
     * @param vardas Studento vardas.
     */
    void setVardas(const std::string& vardas) override;
    
    /**
     * @brief Gražina studento vardą.
     * @return Studento vardas.
     */
    std::string getVardas() const override;

    /**
     * @brief Nustato studento pavardę.
     * @param pavarde Studento pavardė.
     */
    void setPavarde(const std::string& pavarde) override;
    
    /**
     * @brief Gražina studento pavardę.
     * @return Studento pavardė.
     */
    std::string getPavarde() const override;

    /**
     * @brief Nustato studento namų darbų rezultatus.
     * @param nd Studento namų darbų rezultatų sąrašas.
     */
    void setNamuDarbai(const std::vector<int>& nd) override;
    
    /**
     * @brief Gražina studento namų darbų rezultatus.
     * @return Studento namų darbų rezultatų sąrašas.
     */
    std::vector<int> getNamuDarbai() const override;

    /**
     * @brief Prideda naują namų darbą prie studento namų darbų sąrašo.
     * @param pazymys Pridedamas namų darbo rezultatas.
     */
    void addNamuDarbas(int pazymys) override;

    /**
     * @brief Nustato studento egzamino rezultatą.
     * @param egzaminas Studento egzamino rezultatas.
     */
    void setEgzaminas(int egzaminas) override;
    
    /**
     * @brief Gražina studento egzamino rezultatą.
     * @return Studento egzamino rezultatas.
     */
    int getEgzaminas() const override;

    /**
     * @brief Skaičiuoja studento vidurkį.
     * @return Vidurkis.
     */
    double skaiciuotiVidurki() const override;
    
    /**
     * @brief Skaičiuoja studento medianą.
     * @return Mediana.
     */
    double skaiciuotiMediana() const override;
    
    /**
     * @brief Skaičiuoja galutinį studento rezultatą.
     * @param naudotiVidurki Ar naudoti vidurkį.
     * @return Galutinis rezultatas.
     */
    double skaiciuotiGalutini(bool naudotiVidurki) const override;

    /**
     * @brief Generuoja atsitiktinius studento rezultatus.
     */
    void atsitiktiniai() override;
    
    /**
     * @brief Generuoja atsitiktinius rezultatus studentams sąraše.
     */
    void atsitiktiniaiStudentai() override;
    
    // testavimas
    /**
     * @brief Testuoja penkių taisyklę Studentas klasėje.
     */
    void testRuleOfFive();
    
    /**
     * @brief Perkrovimas << operatoriaus Studentas klasėje.
     * @param os Išvesties srautas.
     * @param student Studentas objektas.
     * @return Išvesties srautas.
     */
    friend std::ostream& operator<<(std::ostream& os, const Studentas& student);
    
    /**
     * @brief Perkrovimas >> operatoriaus Studentas klasėje.
     * @param is Įvesties srautas.
     * @param student Studentas objektas.
     * @return Įvesties srautas.
     */
    friend std::istream& operator>>(std::istream& is, Studentas& student);

private:
    std::string vardas; ///< Studento vardas.
    std::string pavarde; ///< Studento pavardė.
    std::vector<int> namuDarbai; ///< Studento namų darbų rezultatai.
    int egzaminas; ///< Studento egzamino rezultatas.
};

#endif // STUDENTAS_H
