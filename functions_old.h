#ifndef FUNCTIONS_OLD_H
#define FUNCTIONS_OLD_H

#include <vector>
#include <string>
#include "studentas.h"

/**
 * @brief Surūšiuoja studentų kategorijas pagal jų rezultatus ir išskirsto į atskirus vektorius.
 * 
 * @param studentai Visų studentų sąrašas.
 * @param vargsiukai Vektorius, kuriame bus saugomi studentai, kurių galutinis rezultatas yra mažesnis nei 5.
 * @param kietiakai Vektorius, kuriame bus saugomi studentai, kurių galutinis rezultatas yra 5 arba didesnis.
 * @param laikas Laikas, kuris bus naudojamas kaip veiksmų vykdymo trukmės rodiklis.
 */
void surusiuotiKategorijas(const std::vector<Studentas> &studentai, std::vector<Studentas> &vargsiukai, std::vector<Studentas> &kietiakai, double &laikas);

/**
 * @brief Įrašo studentų duomenis į failą.
 * 
 * @param studentai Studentų sąrašas.
 * @param failoPavadinimas Pavadinimas, kurį turės turės naujas failas.
 * @param laikas Laikas, kuris bus naudojamas kaip veiksmų vykdymo trukmės rodiklis.
 */
void irasymasFaile(const std::vector<Studentas> &studentai, const std::string &failoPavadinimas, double &laikas);

/**
 * @brief Surūšiuoja studentus ir juos išveda į naują failą.
 * 
 * @param studentai Studentų sąrašas.
 * @param laikas Laikas, kuris bus naudojamas kaip veiksmų vykdymo trukmės rodiklis.
 */
void rusiuotiStudentusIrIrasymas(const std::vector<Studentas> &studentai, double &laikas);

/**
 * @brief Generuoja studentų failus pagal nurodytus dydžius.
 * 
 * @param sizes Dydis, pagal kurį bus sugeneruoti studentų failai.
 */
void generuotiStudentuFailus(const std::vector<int>& sizes);

/**
 * @brief Nuskaito studentų duomenis iš failo į vektorių.
 * 
 * @param studentai Vektorius, į kurį bus nuskaitomi studentų duomenys.
 * @param failoPavadinimas Pavadinimas, iš kurio bus nuskaitomi duomenys.
 * @param laikas Laikas, kuris bus naudojamas kaip veiksmų vykdymo trukmės rodiklis.
 */
void nuskaitymas(std::vector<Studentas>& studentai, const std::string& failoPavadinimas, double &laikas);

/**
 * @brief Funkcija, kuri lygina du Studentas objektus pagal vardą.
 * 
 * @param a Pirmasis Studentas objektas.
 * @param b Antrasis Studentas objektas.
 * @return True, jei pirmasis objektas turėtų eiti pirmesnis, False, jei antrasis objektas turėtų eiti pirmesnis.
 */
bool rusiuotiPagalVarda(const Studentas& a, const Studentas& b);

/**
 * @brief Funkcija, kuri lygina du Studentas objektus pagal pavardę.
 * 
 * @param a Pirmasis Studentas objektas.
 * @param b Antrasis Studentas objektas.
 * @return True, jei pirmasis objektas turėtų eiti pirmesnis, False, jei antrasis objektas turėtų eiti pirmesnis.
 */
bool rusiuotiPagalPavarde(const Studentas& a, const Studentas& b);

/**
 * @brief Funkcija, kuri lygina du Studentas objektus pagal galutinį vidurkį.
 * 
 * @param a Pirmasis Studentas objektas.
 * @param b Antrasis Studentas objektas.
 * @return True, jei pirmasis objektas turėtų eiti pirmesnis, False, jei antrasis objektas turėtų eiti pirmesnis.
 */
bool rusiuotiPagalGalutiniVidurki(const Studentas& a, const Studentas& b);

/**
 * @brief Funkcija, kuri lygina du Studentas objektus pagal galutinę medianą.
 * 
 * @param a Pirmasis Studentas objektas.
 * @param b Antrasis Studentas objektas.
 * @return True, jei pirmasis objektas turėtų eiti pirmesnis, False, jei antrasis objektas turėtų eiti pirmesnis.
 */
bool rusiuotiPagalGalutiniMediana(const Studentas& a, const Studentas& b);

/**
 * @brief Spausdina studentų duomenis.
 * 
 * @param studentai Studentų sąrašas.
 * @param isvedimoFailas Naujo failo pavadinimas, į kurį bus išsaugoti duomenys (neprivaloma).
 */
void spausdinimas(const std::vector<Studentas>& studentai, const std::string& isvedimoFailas = "");

/**
 * @brief Leidžia vartotojui pasirinkti failą.
 * 
 * @return Pasirinktas failo pavadinimas.
 */
std::string pasirinktiFaila();

#endif // FUNCTIONS_OLD_H
