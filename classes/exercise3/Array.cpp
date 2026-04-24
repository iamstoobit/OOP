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

    std::cout << "| Array size: " << this->size << " | Array capacity: " << this->capacity << '\n';
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

bool Array::removeElement(const int index) {
    if(index < this->size && index > 0) {
        for(size_t i = index; i < this->size - 2; ++i) {
            this->data[i] = this->data[i + 1];
        }

        this->size--;
        return true;
    }
    
    return false;
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
    int* temp = new int[this->size];

    for (size_t i = 0; i < this->size; ++i) {
        temp[i] = this->data[i];
    }

    delete[] this->data;
    this->data = temp;
    this->capacity = this->size;
}

int Array::getSize() const {
    return this->size;
}

int Array::getCap() const {
    return this->capacity;
}

Array Array::operator+(const Array& other) const {
    Array result = other;
    if(result.size < this->size) {
        while(result.capacity < this->size) {
            result.resize();
        }

        result.size = this->size;

        for(size_t i = other.size; i < this->size; ++i) {
            result.data[i] = this->data[i];
        }
    }

    for(size_t i = 0; i < std::min(this->size, other.size); ++i) {
        result.data[i] += this->data[i];
    }

    return result;
}

Array& Array::operator+=(const Array& other) {
    *this = *this + other;
    return *this;
}

Array Array::operator-(const Array& other) const {
    Array result = other;
    if(result.size < this->size) {
        while (result.capacity < this->size) {
            result.resize();
        }
        
        result.size = this->size;
        
        for(size_t i = other.size; i < this->size; ++i) {
            result.data[i] = this->data[i];
        }
    }

    for(size_t i = 0; i < std::min(this->size, other.size); ++i) {
        result.data[i] = this->data[i] - other.data[i];
    }

    return result;
}

Array& Array::operator-=(const Array& other) {
    *this = *this - other;
    return *this;
}

Array Array::operator*(const Array& other) const {
    Array result = other;
    if(result.size < this->size) {
        while(result.capacity < this->size) {
            result.resize();
        }

        result.size = this->size;

        for(size_t i = other.size; i < this->size; ++i) {
            result.data[i] = this->data[i];
        }
    }

    for(size_t i = 0; i < std::min(other.size, this->size); ++i) {
        result.data[i] = this->data[i] * other.data[i];
    }

    return result;
}

Array& Array::operator*=(const Array& other) {
    *this = *this * other;
    return *this;
}

Array& Array::operator++() {
    if(this->size == this->capacity) {
        resize();
    }

    this->data[this->size] = 0;
    this->size++;

    return *this;
}

Array Array::operator++(int) {
    Array old = *this;
    ++(*this);

    return old;
}

Array& Array::operator--() {
    this->size--;
    return *this;
}

Array Array::operator--(int) {
    Array old = *this;

    --(*this);
    return old;
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

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

bool Array::operator>(const Array& other) const {
    if(this->size > other.size) {
        return true;
    }

    if(this->size < other.size) {
        return false;
    }

    for(size_t i = 0; i < this->size; ++i) {
        if(this->data[i] > other.data[i]) {
            return true;
        }

        if(this->data[i] < other.data[i]) {
            return false;
        }
    }

    return false;
}

bool Array::operator<(const Array& other) const {
    if(this->size > other.size) {
        return false;
    }

    if(this->size < other.size) {
        return true;
    }

    for(size_t i = 0; i < this->size; ++i) {
        if(this->data[i] > other.data[i]) {
            return false;
        }

        if(this->data[i] < other.data[i]) {
            return true;
        }
    }

    return false;
}

bool Array::operator>=(const Array& other) const {
    return !(*this < other);
}

bool Array::operator<=(const Array& other) const {
    return !(*this > other);
}

int& Array::operator[](int index) {
    return this->data[index];
}

int Array::operator[](int index) const {
    return this->data[index];
}

int& Array::at(int index) {
    if(index < 0 || index > this->size) {
        throw (std::out_of_range) "Bad index in function: int &Array::at(int index)";
    }

    return this->data[index];
}

int Array::at(int index) const {
    if(index < 0 || index > this->size) {
        throw (std::out_of_range) "Bad index in function: int Array::at(int index) const";
    }

    return this->data[index];
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
//-------------------------------- Friend functions ------------------------------------------------------------

std::istream& operator>>(std::istream is, Array& arr) {
    int readCap = 0, readSize = 0;
    is >> readCap >> readSize;
    int* readData = nullptr;

    if(is) {
        readData = new int[readCap];
    }
    
    for(size_t i = 0; i < readSize; ++i) {
        is >> readData[i];
    }

    if(is) {
        arr.capacity = readCap;
        arr.size = readSize;

        delete[] arr.data;
        arr.data = readData;
    }
    
    else {
        delete[] readData;
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, Array& arr) {
    os << arr.capacity << " " << arr.size;
    for(size_t i = 0; i < arr.size; ++i) {
        os << " " << arr[i];
    }
    os << '\n';

    return os;
}

//-------------------------------- Non-member functions ------------------------------------------------------------

Array operator+(Array& arr, int num) {
    Array result = arr;

    for(size_t i = 0; i < result.getSize(); ++i) {
        result[i] += num;
    }

    return result;
}

Array operator+(int num, Array& arr) {
    return arr + num;
}

Array operator-(Array& arr, int num) {
    Array result = arr;

    for(size_t i = 0; i < result.getSize(); ++i) {
        result[i] -= num;
    }

    return result;
}

Array operator-(int num, Array& arr) {
    return arr - num;
}

Array operator-=(Array& arr, int num) {
    for(size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] -= num;
    }

    return arr;
}

Array operator-=(int num, Array& arr) {
    return arr - num;
}

Array operator*(Array& arr, int num) {
    Array result;
    
    for(size_t i = 0; i < result.getSize(); ++i) {
        result[i] *= num;
    }

    return result;
}

Array operator*(int num, Array& arr) {
    return arr * num;
}

Array operator*=(Array& arr, int num) {
    for(size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] *= num;
    }

    return arr;
}

Array operator*=(int num, Array& arr) {
    return arr * num;
}
