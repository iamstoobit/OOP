#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include "Person.h"

class Car {
public:
    Car(const char* model, const char* brand, const Date& manufactured, Person* owner, unsigned int colour);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();

    const char* getModel() const;
    const char* getBrand() const;
    const Date getManufactured() const;
    Person* getOwner() const;
    int getColour() const;

    bool setOwner(Person* owner);
    bool setColour(const int& colour);

    void print() const;
    bool changeOwner(const Person& newOwner);

private:
    void setModel(const char* model);
    void free();
    void copyFrom(const Car& other);

    void setBrand(const char* brand);
    void setModel(const char* model);

    const char* model;
    const char* brand;
    const Date manufactured;
    Person* owner;
    unsigned int colour;
};

#endif
