#ifndef FUNCTIONS_LIST_H
#define FUNCTIONS_LIST_H

#include "studentas.h"
#include <list>

void readDataList(std::list<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesList(int size);
void divideStudentsList(const std::string& failoVardas);

#endif 