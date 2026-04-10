#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <exception>

class Date{
public:
    Date();
    Date(const int day, const int month, const int year);
    Date(const Date& other);
    Date& operator=(const Date& other);
    ~Date() = default;

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);

    bool isLeapYear() const;
    void print() const;
    int dayOfWeek() const;
    int daysBetween(const Date& date1, const Date& date2);

private:
    void copyFrom(const Date& other);
    int getCenturyCode(int year) const;

    int day;
    int month;
    int year;
};

#endif
