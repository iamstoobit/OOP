#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
public:
    Array();
    Array(const int length);
    Array(const Array& other);
    Array& operator=(const Array* other);
    ~Array();

    void print() const;
    bool changeElement(const int index, const int newData);
    int* pushBack(const int number);
    void removeElement(const int index);
    void sortAsc();
    void filter(bool (*pred)(int));
    void shrinkToFit();

    bool operator==(const Array& other) const;


private:
    void resize();
    bool isSorted() const;
    void copyFrom(const Array& other);

    int* data;
    size_t size; //current amount of elements
    size_t capacity; //max amount of elements
};

#endif
