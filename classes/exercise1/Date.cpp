#include "Date.h"

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 0;
}

Date::Date(const int day, const int month, const int year) {
    if(!setYear(year) || !setMonth(month) || !setDay(day)) {
        throw (std::invalid_argument) "Invalid date";
    };
}

Date::Date(const Date& other) {
    try {
        copyFrom(other);
    } catch(...) {
        throw;
    }
}

Date& Date::operator=(const Date& other) {
    if(this != &other) {
        copyFrom(other);
    }

    return *this;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

bool Date::setDay(int day) {
    if(0 < day && day < 31) {
        switch(this->month) {
            case 1:
                this->day = day;
                return true;

            case 2:
                if(day <= 28 || (isLeapYear() && day <= 29)) {
                    this->day = day;
                }
                return true;

            case 3:
                this->day = day;
                return true;

            case 4:
                if(day <= 30) {
                    this->day = day;
                }
                return true;

            case 5:
                this->day = day;
                return true;

            case 6:
                if(day <= 30) {
                    this->day = day;
                }
                return true;

            case 7:
                this->day = day;
                return true;

            case 8:
                this->day = day;
                return true;

            case 9: 
                if(day <= 30) {
                    this->day = day;
                }
                return true;

            case 10:
                this->day = day;
                return true;

            case 11:
                if(day <= 30) {
                    this->day = day;
                }
                return true;

            case 12:
                this->day = day;
                return true;

            default:
                break;
        }
    }

    return false;
}

bool Date::setMonth(int month) {
    if(0 < month && month <= 12) {
        this->month = month;
        return true;
    }

    return false;
}

bool Date::setYear(int year) {
    this->year = year;
    return true;
}

bool Date::isLeapYear() const {
    if(this->year % 100 == 0) {
        if(this->year % 400 == 0) {
            return true;
        }

        return false;
    }

    else if(this->year % 4 == 0) {
        return true;
    }

    return false;
}

void Date::print() const {
    std::cout << "Date: " << this->day << "/" << this->month << "/" << this->year << '\n';
}

int Date::dayOfWeek() const {
    // Get the year code
    int yearCode = this->year % 100;
    yearCode += (yearCode / 4);

    bool leap = isLeapYear();
    if(leap) {
        yearCode--;
    }

    yearCode %= 7;

    yearCode += getCenturyCode(this->year);

    int result = this->day + yearCode;
    switch (this->month) {
        case 1:
            result = result + 6 - leap;
            break;

        case 2:
            result = result + 2 - leap;
            break;

        case 3:
            result += 2;
            break;
        
        case 4:
            result += 5;
            break;
        
        // May is + 0

        case 6:
            result += 3;
            break;
        
        case 7:
            result += 5;
            break;
        
        case 8:
            result += 1;
            break;
        
        case 9:
            result += 4;
            break;
        
        case 10:
            result += 6;
            break;
        
        case 11:
            result += 2;
            break;
        
        case 12:
            result += 4;
            break;
        
        default:
            break;
    }

    return result % 7;
}

//int Date::daysBetween(const Date& date1, const Date& date2) {}

void Date::copyFrom(const Date& other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

int Date::getCenturyCode(int year) const {
    switch((year / 100) % 4) {
        case 0: return 0;
        case 1: return 5;
        case 2: return 3;
        case 3: return 1;
        default: return -1;
    }
}
