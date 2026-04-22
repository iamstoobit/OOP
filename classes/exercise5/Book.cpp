#include "Book.h"

int Book::nextID = 0;

Book::Book() : name(nullptr), author(nullptr) {
    try {
        setName("Unknown");
        setAuthor("Unknown");
        setPages(1);
        setID(Book::nextID);
    } catch(std::bad_alloc& ba) {
        free();
        throw "Bad alloc";
    } catch(std::invalid_argument& ia) {
        free();
        throw "Invalid argument";
    }

    Book::nextID++;
}

Book::Book(const char* name, const char* author, int pages) : name(nullptr), author(nullptr), ID(nullptr) {
    try {
        setName(name);
        setAuthor(author);
        setPages(pages);
        setID(Book::nextID);
    } catch(std::bad_alloc& ba) {
        free();
        throw "Bad alloc";
    } catch(std::invalid_argument& ia) {
        free();
        throw "Invalid argument";
    } catch(...) {
        throw "Something went wrong";
    }

    Book::nextID++;
}

Book::Book(const Book& other) : name(nullptr), author(nullptr) {
    try {
        setID(Book::nextID);
        setName(other.name);
        setAuthor(other.author);
        setPages(other.pages);
    } catch(std::bad_alloc& ba) {
        throw "Bad alloc";
    } catch(...) {
        throw "Something went wrong";
    }

    Book::nextID++;
}

Book& Book::operator=(const Book& other) {
    if(this != &other) {
        Book cpy(other);
        free();
        this->name = cpy.name;
        this->author = cpy.author;
        this->pages = cpy.pages;
    }

    return *this;
}

Book::~Book() {
    free();
}

char* Book::getName() const {
    return this->name;
}

char* Book::getAuthor() const {
    return this->author;
}

int Book::getPages() const {
    return this->pages;
}

const char* Book::getID() const {
    return this->ID;
}

void Book::setName(const char* newName) {
    if(!newName) {
        throw (std::invalid_argument) "No book name";
    }

    char* temp = new char(strlen(newName) + 1);
    strcpy(temp, newName);
    delete[] this->name;
    this->name = temp;
}

void Book::setAuthor(const char* newAuthor) {
    if(!newAuthor) {
        throw (std::invalid_argument) "No author";
    }

    char* temp = new char(strlen(newAuthor) + 1);
    strcpy(temp, newAuthor);
    delete[] this->author;
    this->author = temp;
}

void Book::setPages(int newPages) {
    if(newPages <= 0) {
        throw (std::invalid_argument) "Less than one pages";
    }

    this->pages = newPages;
}

void Book::print(std::ostream& os) const {
    os << this->name << " by " << this->author << " | " << this->pages << " pages | ID: " << this->ID << '\n';
}

bool Book::readFromIS(std::istream& is) {
    try {
        char* newName = new char[1024];
        char* newAuthor = new char[1024];
        
        is.getline(newName, 1024, ' ');
        is.getline(newAuthor, 1024, ' ');

        free();
        setName(newName);
        setAuthor(newAuthor);

        int newPages;
        is >> newPages;

        setPages(newPages);
    } catch(...) {
        return false;
    }

    return true;
}

void Book::free() {
    delete[] this->name;
    this->name = nullptr;

    delete[] this->author;
    this->author = nullptr;
}

void Book::setID(int ID) {
    try{
        char* temp = new char[12];
        strcpy(temp, "IS-INF-");
        temp[7] = (ID / 1000) + '0';
        temp[8] = ((ID / 100) % 10) + '0';
        temp[9] = ((ID % 100) / 10) + '0';
        temp[10] = (ID % 10) + '0';
        temp[11] = '\0';
        this->ID = temp;
    } catch(std::bad_alloc& ba) {
        this->ID = nullptr;
        throw;
    }
}
