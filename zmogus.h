#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <vector>

/**
 * @brief Klasė Žmogus atstovauja žmogų.
 */
class Human {
public:
    /**
     * @brief Žmogaus klasės destruktorius.
     */
    virtual ~Human() = default;
    
    /**
     * @brief Nustato žmogaus vardą.
     * @param vardas Žmogaus vardas.
     */
    virtual void setVardas(const std::string& vardas) = 0; 
    
    /**
     * @brief Grąžina žmogaus vardą.
     * @return Žmogaus vardas.
     */
    virtual std::string getVardas() const = 0;

    /**
     * @brief Nustato žmogaus pavardę.
     * @param pavarde Žmogaus pavardė.
     */
    virtual void setPavarde(const std::string& pavarde) = 0;
    
    /**
     * @brief Grąžina žmogaus pavardę.
     * @return Žmogaus pavardė.
     */
    virtual std::string getPavarde() const = 0;

    /**
     * @brief Nustato žmogaus namų darbų rezultatus.
     * @param nd Žmogaus namų darbų rezultatų sąrašas.
     */
    virtual void setNamuDarbai(const std::vector<int>& nd) = 0;
    
    /**
     * @brief Gražina žmogaus namų darbų rezultatus.
     * @return Žmogaus namų darbų rezultatų sąrašas.
     */
    virtual std::vector<int> getNamuDarbai() const = 0;

    /**
     * @brief Prideda naują namų darbą prie žmogaus namų darbų sąrašo.
     * @param pazymys Pridedamas namų darbo rezultatas.
     */
    virtual void addNamuDarbas(int pazymys) = 0;

    /**
     * @brief Nustato žmogaus egzamino rezultatą.
     * @param egzaminas Žmogaus egzamino rezultatas.
     */
    virtual void setEgzaminas(int egzaminas) = 0;
    
    /**
     * @brief Grąžina žmogaus egzamino rezultatą.
     * @return Žmogaus egzamino rezultatas.
     */
    virtual int getEgzaminas() const = 0;

    /**
     * @brief Skaičiuoja žmogaus vidurkį.
     * @return Vidurkis.
     */
    virtual double skaiciuotiVidurki() const = 0;
    
    /**
     * @brief Skaičiuoja žmogaus medianą.
     * @return Mediana.
     */
    virtual double skaiciuotiMediana() const = 0;
    
    /**
     * @brief Skaičiuoja galutinį žmogaus rezultatą.
     * @param naudotiVidurki Ar naudoti vidurkį.
     * @return Galutinis rezultatas.
     */
    virtual double skaiciuotiGalutini(bool naudotiVidurki) const = 0;

    /**
     * @brief Generuoja atsitiktinius žmogaus rezultatus.
     */
    virtual void atsitiktiniai() = 0;
    
    /**
     * @brief Generuoja atsitiktinius rezultatus žmonių sąraše.
     */
    virtual void atsitiktiniaiStudentai() = 0;
};

#endif // ZMOGUS_H
