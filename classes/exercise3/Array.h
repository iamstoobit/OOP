#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <fstream>

class Array {
public:
    Array();
    Array(const int length);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    void print() const;
    bool changeElement(const int index, const int newData);
    int* pushBack(const int number);
    bool removeElement(const int index);
    void sortAsc();
    void filter(bool (*pred)(int));
    void shrinkToFit();

    int getSize() const;
    int getCap() const;

    Array operator+(const Array& other) const;
    Array& operator+=(const Array& other);
    Array operator-(const Array& other) const;
    Array& operator-=(const Array& other);
    Array operator*(const Array& other) const;
    Array& operator*=(const Array& other);
    Array& operator++();
    Array operator++(int);
    Array& operator--();
    Array operator--(int);
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    bool operator>(const Array& other) const;
    bool operator<(const Array& other) const;
    bool operator>=(const Array& other) const;
    bool operator<=(const Array& other) const;
    int& operator[](int index);
    int operator[](int index) const;
    int& at(int index);
    int at(int index) const;
    /*operator()*/
    friend std::istream& operator>>(std::istream is, Array& arr);
    friend std::ostream& operator<<(std::ostream& os, Array& arr);


private:
    void resize();
    bool isSorted() const;
    void copyFrom(const Array& other);

    int* data;
    size_t size; //current amount of elements
    size_t capacity; //max amount of elements
};

Array operator+(Array& arr, int num);
Array operator+(int num, Array& arr);
Array operator-(Array& arr, int num);
Array operator-(int num, Array& arr);
Array operator-=(Array& arr, int num);
Array operator-=(int num, Array& arr);
Array operator*(Array& arr, int num);
Array operator*(int num, Array& arr);
Array operator*=(Array& arr, int num);
Array operator*=(int num, Array& arr);

#endif
