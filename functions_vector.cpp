#include "functions_vector.h"
#include "studentas.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>

void readDataVector(std::vector<Studentas>& studentai, const std::string& failoVardas) {
    std::ifstream file(failoVardas);
    if (!file) {
        std::cerr << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        Studentas studentas;
        if (iss >> studentas) {
            studentai.push_back(std::move(studentas));
        }
    }
    file.close();
}

void generateStudentFilesVector(int size) {
    std::string fileName = "studentai" + std::to_string(size) + ".txt";
    std::ofstream outFile(fileName);

    if (!outFile) {
        std::cerr << "Nepavyko atidaryti failo: " << fileName << std::endl;
        return;
    }

    outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė";
    for (int i = 1; i <= 15; ++i) {
        outFile << std::setw(10) << "ND" + std::to_string(i);
    }
    outFile << std::setw(10) << "Egz." << std::endl;

    for (int i = 1; i <= size; i++) {
        outFile << std::left << std::setw(15) << "Vardas" + std::to_string(i)
                << std::setw(15) << "Pavardė" + std::to_string(i);
        for (int j = 0; j < 15; j++) {
            outFile << std::setw(10) << (rand() % 10 + 1);
        }
        outFile << std::setw(10) << (rand() % 10 + 1);
        outFile << std::endl;
    }

    outFile.close();
}

void rusiuotStudentusVector1(const std::string& failoVardas) {
    std::vector<Studentas> studentai;

    auto readStart = std::chrono::high_resolution_clock::now();
    readDataVector(studentai, failoVardas);
    auto readEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> readElapsed = readEnd - readStart;
    std::cout << std::fixed << std::setprecision(7) << "Skaitymas uztruko: " << readElapsed.count() << "s\n";

    auto sortStart = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return (0.4 * a.skaiciuotiVidurki() + 0.6 * a.getEgzaminas()) <
               (0.4 * b.skaiciuotiVidurki() + 0.6 * b.getEgzaminas());
    });
    auto sortEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortElapsed = sortEnd - sortStart;
    std::cout << std::fixed << std::setprecision(7) << "Rusiavimas uztruko: " << sortElapsed.count() << "s\n";

    std::vector<Studentas> kietiakai, vargsiukai;
    auto divideStart = std::chrono::high_resolution_clock::now();
    for (const auto& studentas : studentai) {
        double galutinisBalas = studentas.skaiciuotiGalutini(true);
        if (galutinisBalas < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakai.push_back(studentas);
        }
    }
    auto divideEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> divideElapsed = divideEnd - divideStart;
    std::cout << std::fixed << std::setprecision(7) << "Studentu skirstymas uztruko: " << divideElapsed.count() << "s\n";

    std::ofstream kietiakaiFile("kietiakai.txt"), vargsiukaiFile("vargsiukai.txt");

    for (const auto& studentas : kietiakai) {
        kietiakaiFile << studentas << std::endl;
    }

    for (const auto& studentas : vargsiukai) {
        vargsiukaiFile << studentas << std::endl;
    }

    kietiakaiFile.close();
    vargsiukaiFile.close();
}
