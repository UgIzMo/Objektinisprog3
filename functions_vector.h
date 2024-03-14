#ifndef FUNCTIONS_VECTOR_H
#define FUNCTIONS_VECTOR_H

#include "studentas.h"
#include <vector>

void readDataVector(std::vector<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesVector(int size);
void rusiuotStudentusVector(const std::string& failoVardas);

#endif // FUNKCIJOSVECTOR_H