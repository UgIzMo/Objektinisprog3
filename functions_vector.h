#ifndef FUNCTIONS_VECTOR_H
#define FUNCTIONS_VECTOR_H

#include "studentas.h" 
#include <string>
#include <vector>

/**
 * @brief Funkcijos deklaracijos.
 */

/**
 * @brief Įveda duomenis apie studentus iš failo į vektorių.
 * 
 * @param studentai Vektorius, kuriame bus saugomi studentų duomenys.
 * @param failoVardas Failo pavadinimas, iš kurio bus skaityti duomenys.
 */
void readDataVector(std::vector<Studentas>& studentai, const std::string& failoVardas);

/**
 * @brief Generuoja studentų failus pagal nurodytą dydį ir atsitiktinius duomenis.
 * 
 * @param size Studentų failų dydis.
 */
void generateStudentFilesVector(int size);

/**
 * @brief Rusiuoja studentus ir išveda juos į naują failą (versija 1).
 * 
 * @param failoVardas Naujo failo pavadinimas, į kurį bus išsaugoti surūšiuoti studentai.
 */
void rusiuotStudentusVector1(const std::string& failoVardas);

#endif // FUNCTIONS_VECTOR_H
