#include "Date.h"

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 0;
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

void Date::setDay(int day) {
    if(0 < day && day < 31) {
        switch(this->month) {
            case 1: {
                this->day = day;
                break;
            }
            case 2: {
                if(day <= 28 || (isLeapYear() && day <= 29)) {
                    this->day = day;
                }
                break;
            }
            case 3: {
                this->day = day;
                break;
            }
            case 4: {
                if(day <= 30) {
                    this->day = day;
                }
                break;
            }
            case 5: {
                this->day = day;
                break;
            }
            case 6: {
                if(day <= 30) {
                    this->day = day;
                }
                break;
            }
            case 7: {
                this->day = day;
                break;
            }
            case 8: {
                this->day = day;
                break;
            }
            case 9: {if(day <= 30) {
                    this->day = day;
                }
                break;
            }
            case 10: {
                this->day = day;
                break;
            }
            case 11: {
                if(day <= 30) {
                    this->day = day;
                }
                break;
            }
            case 12: {
                this->day = day;
                break;
            }
            default: break;
        }
    }
}

void Date::setMonth(int month) {
    if(0 < month && month <= 12) {
        this->month = month;
    }
}

void Date::setYear(int year) {
    this->year = year;
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
    int monthConstant = getMonthConstant();

    int result = this->year % 100 + ((this->year % 100) / 4) + monthConstant + this->day;

    if((this->month == 1 || this->month == 2) && this->isLeapYear()) {
        result -= 1;
    }

    return result % 7;
}

//int Date::daysBetween(const Date& date1, const Date& date2) {}

void Date::copyFrom(const Date& other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

int Date::getMonthConstant() const {
    if(this->month == 1 || this->month == 10) return 6;
    else if(this->month == 4 || this->month == 7) return 5;
    else if(this->month == 9 || this->month == 12) return 4;
    else if(this->month == 5) return 0;
    else if(this->month == 6) return 3;
    else if(this->month == 8) return 1;
    else return 2;
}
