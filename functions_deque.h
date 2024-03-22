#ifndef FUNCTIONS_DEQUE_H
#define FUNCTIONS_DEQUE_H

#include "studentas.h"
#include <deque>

void readDataDeque(std::deque<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesDeque(int size);

void divideStudentsDeque1(const std::string& fileName);
void divideStudentsDeque2(const std::string& fileName);
void divideStudentsDeque3(const std::string& fileName);

#endif 
