#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
#include "../exercise1/Date.h"

enum Gender{
    MALE,
    FEMALE,
    UNKNOWN = -1
};

class Person{
public:
    Person(Date DOB, int pGender) :
                        firstName(nullptr), middleName(nullptr), lastName(nullptr),
                        DOB(DOB), gender((Gender)((-1 >= pGender) && (pGender <= 1) ? pGender : Gender::UNKNOWN)) {};
    Person(const char* fName, const char* mName, const char* lName, Date DOB, Gender pGender);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    Date getDOB() const;
    int getGender() const;

    bool setFirstName(const char* newName);
    bool setMiddleName(const char* newName);
    bool setLastName(const char* newName);

    void print() const;

private:
    void free();
    void copyFrom(const Person& other);

    char* firstName;
    char* middleName;
    char* lastName;
    const Date DOB;
    const Gender gender;
};

#endif
