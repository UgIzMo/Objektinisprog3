#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
public:
    virtual ~Zmogus() = default; // Virtual destructor
    virtual int getAge() const = 0; // Pure virtual function
    virtual std::string getName() const = 0; // Pure virtual function
};

#endif
