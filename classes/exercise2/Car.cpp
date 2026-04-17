#include "Car.h"

Car::Car(const char* model, const char* brand, const Date& manufactured, Person* owner, unsigned int colour) : manufactured(manufactured), owner(nullptr) {
    setModel(model);
    setBrand(brand);
    if(owner) {
        setOwner(owner);
    }
    this->colour = colour;
}

Car::Car(const Car& other) : manufactured(other.manufactured), owner(other.owner), colour(other.colour) {
    copyFrom(other);
}

Car& Car::operator=(const Car& other) {
    if(this != &other) { //only owner and colour
        this->owner = other.owner;
        this->colour = other.colour;
    }

    return *this;
}

Car::~Car() {
    free();
}

const char* Car::getModel() const {
    return this->model;
}

const char* Car::getBrand() const {
    return this->brand;
}

const Date Car::getManufactured() const {
    return this->manufactured;
}

Person* Car::getOwner() const {
    return this->owner;
}

int Car::getColour() const {
    return this->colour;
}

bool Car::setOwner(Person* owner) {
    this->owner = owner;
    return true;
}

bool Car::setColour(const int& colour) {
    this->colour = colour;
}

void Car::print() const {
    std::cout << this->model << " " << this->brand << '\n';
    this->manufactured.print();
    this->owner->print();
    std::cout << this->colour << '\n';
}

bool Car::changeOwner(const Person& newOwner) {
    
}

void Car::free() {
    delete[] this->model;
    this->model = nullptr;

    delete[] this->brand;
    this->brand = nullptr;
}

void Car::copyFrom(const Car& other) {
    setModel(other.model);
    setBrand(other.brand);
}

void Car::setModel(const char* model) {
    char* temp = new char[strlen(model) + 1];
    strcpy(temp, model);
    this->model = temp;
}

void Car::setBrand(const char* brand) {
    char* temp = new char[strlen(brand) + 1];
    strcpy(temp, brand);
    this->brand = temp;
}
