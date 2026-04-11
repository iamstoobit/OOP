#include "Person.h"

Person::Person(const char* fName, const char* mName, const char* lName, Date DOB, Gender pGender) :
                        firstName(nullptr), middleName(nullptr), lastName(nullptr),
                        DOB(DOB), gender(((pGender == Gender::MALE) || (pGender == Gender::FEMALE)) ? pGender : Gender::UNKNOWN) {
    setFirstName(fName);
    setMiddleName(mName);
    setLastName(lName);
};

Person::Person(const Person& other) : firstName(nullptr), middleName(nullptr), lastName(nullptr),
                                        DOB(other.DOB), gender(other.gender) {
    copyFrom(other);
}

Person& Person::operator=(const Person& other) {
    if(this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Person::~Person() {
    free();
}

Date Person::getDOB() const {
    return this->DOB;
}

int Person::getGender() const {
    return this->gender;
}

bool Person::setFirstName(const char* newName) {
    try {
        delete[] this->firstName;
        this->firstName = new char[strlen(newName) + 1];
        strcpy(this->firstName, newName);
    } catch(...) {
        return false;
    }

    return true;
}

bool Person::setMiddleName(const char* newName) {
    try {
        delete[] this->middleName;
        this->middleName = new char[strlen(newName) + 1];
        strcpy(this->middleName, newName);
    } catch(...) {
        return false;
    }

    return true;
}

bool Person::setLastName(const char* newName) {
    try {
        delete[] this->lastName;
        this->lastName = new char[strlen(newName) + 1];
        strcpy(this->lastName, newName);
    } catch(...) {
        return false;
    }

    return true;
}

void Person::print() const {
    std::cout << this->firstName << " " << this->middleName << " " << this->lastName << " | ";
    this->DOB.print();
    std::cout << this->gender << '\n';
}

void Person::free() {
    delete[] this->firstName;
    this->firstName = nullptr;

    delete[] this->middleName;
    this->middleName = nullptr;
    
    delete[] this->lastName;
    this->lastName = nullptr;
}

void Person::copyFrom(const Person& other) {
    setFirstName(other.firstName);
    setMiddleName(other.middleName);
    setLastName(other.lastName);
}
