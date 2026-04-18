#include "Array.h"

Array::Array() {
    this->data = new int[1];
    this->size = 0;
    this->capacity = 1;
}

Array::Array(const int length) {
    if(length > 0) {
        this->data = new int[length];
        this->size = 0;
        this->capacity = length;
    }

    else {
        throw(std::invalid_argument) "Array cannot be created with negative size!";
    }
}

Array::Array(const Array& other) {
    copyFrom(other);
}

Array& Array::operator=(const Array& other) {
    if(this != &other) {
        delete[] this->data;
        copyFrom(other);
    }

    return *this;
}

Array::~Array() {
    delete[] this->data;
}

void Array::print() const {
    std::cout << "Array data: ";
    for(size_t i = 0; i < this->size; ++i) {
        std::cout << this->data[i] << " ";
    }

    std::cout << "| Array size: " << this->size << '\n';
}

bool Array::changeElement(const int index, const int newData) {
    if(index >= this->size || index < 0) {
        return false;
    }
    
    this->data[index] = newData;
    return true;
}

int* Array::pushBack(const int number) {
    if(this->size == this->capacity) {
        resize();
    }

    this->data[this->size] = number;
    this->size++;
    return &this->data[this->size - 1];
}

void Array::removeElement(const int index) {
    for(size_t i = index; i < this->size - 2; ++i) {
        this->data[i] = this->data[i + 1];
    }

    this->size--;
}

void Array::sortAsc() {
    if(!isSorted()) {
        for(size_t i = 0; i < this->size - 1; ++i) {
            int min = i;
            for(size_t j = i + 1; j < this->size; ++j) {
                if(this->data[min] > this->data[j]) {
                    min = j;
                }
            }
            std::swap(this->data[i], this->data[min]);
        }
    }
}

void Array::filter(bool (*pred)(int)) {
    for (size_t i = 0; i < this->size; ++i) {
        if(!pred(this->data[i])) {
            removeElement(i);
            --i;
        }
    }
}

void Array::shrinkToFit() {
    int* temp = this->data;
    this->data = new int[this->size];

    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] = temp[i];
    }

    this->capacity = this->size;
    delete[] temp;
}

bool Array::operator==(const Array& other) const {
    if(this->size != other.size) {
        return false;
    }

    for (size_t i = 0; i < this->size; i++) {
        if(this->data[i] != other.data[i]) {
            return false;
        }
    }
    
    return true;
}

void Array::resize() {
    int* temp = this->data;
    this->capacity *= 2;
    this->data = new int[this->capacity];

    for(size_t i = 0; i < this->size; ++i) {
        this->data[i] = temp[i];
    }

    delete[] temp;
}

bool Array::isSorted() const {
    for(size_t i = 0; i < this->size - 2; ++i) {
        if(this->data[i] > this->data[i + 1]) {
            return false;
        }
    }

    return true;
}

void Array::copyFrom(const Array& other) {
    this->data = new int[other.capacity];
    for(size_t i = 0; i < other.size; ++i) {
        this->data[i] = other.data[i];
    }

    this->size = other.size;
    this->capacity = other.capacity;
}
