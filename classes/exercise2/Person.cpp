#include "Person.h"

Person::Person(const char* fName, const char* mName, const char* lName, Date DOB, Gender pGender) :
                        firstName(nullptr), middleName(nullptr), lastName(nullptr),
                        DOB(DOB), gender(((pGender == Gender::MALE) || (pGender == Gender::FEMALE)) ? pGender : Gender::UNKNOWN) {
    try {
        setFirstName(fName);
        setMiddleName(mName);
        setLastName(lName);
    } catch(...) {
        delete[] this->firstName;
        delete[] this->middleName;
    }
};

Person::Person(const Person& other) : firstName(nullptr), middleName(nullptr), lastName(nullptr),
                                        DOB(other.DOB), gender(other.gender) {
    copyFrom(other);
}

Person& Person::operator=(const Person& other) {
    if(this != &other) {
        copyFrom(other);
    }

    return *this;
}

Person::~Person() {
    delete[] this->firstName;
    this->firstName = nullptr;

    delete[] this->middleName;
    this->middleName = nullptr;
    
    delete[] this->lastName;
    this->lastName = nullptr;
}

Date Person::getDOB() const {
    return this->DOB;
}

int Person::getGender() const {
    return this->gender;
}

bool Person::setFirstName(const char* newName) {
    try {
        char* temp = new char[strlen(newName) + 1];
        strcpy(temp, newName);
        delete[] this->firstName;
        this->firstName = temp;
    } catch(...) {
        throw;
    }

    return true;
}

bool Person::setMiddleName(const char* newName) {
    try {
        char* temp = new char[strlen(newName) + 1];
        strcpy(temp, newName);
        delete[] this->middleName;
        this->middleName = temp;
    } catch(...) {
        throw;
    }

    return true;
}

bool Person::setLastName(const char* newName) {
    try {
        char* temp = new char[strlen(newName) + 1];
        strcpy(temp, newName);
        delete[] this->lastName;
        this->lastName = temp;
    } catch(...) {
        throw;
    }

    return true;
}

void Person::print() const {
    std::cout << this->firstName << " " << this->middleName << " " << this->lastName << " | ";
    this->DOB.print();
    std::cout << this->gender << '\n';
}

void Person::copyFrom(const Person& other) {
    try {
        setFirstName(other.firstName);
        setMiddleName(other.middleName);
        setLastName(other.lastName);
    } catch(...) {
        delete[] this->firstName;
        delete[] this->middleName;
        throw;
    }
}
