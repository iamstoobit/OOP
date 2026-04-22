#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>
#include <fstream>

class Book {
public:
    Book();
    Book(const char* name, const char* author, int pages);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book();

    char* getName() const;
    char* getAuthor() const;
    int getPages() const;
    const char* getID() const;

    void setName(const char* newName);
    void setAuthor(const char* newAuthor);
    void setPages(int newPages);

    void print(std::ostream& os) const;
    bool readFromIS(std::istream& is);

private:
    void free();
    void setID(int ID);

    const char* ID;
    char* name;
    char* author;
    unsigned int pages;
    static int nextID;
};

#endif
