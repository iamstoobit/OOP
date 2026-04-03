#include <iostream>
#include "Date.h"

int main() {
    Date d1;
    Date d2(d1);

    d1.print();
    d2.print();
    
    d2.setYear(2026);
    d2.setMonth(4);
    d2.setDay(5);

    d2.print();

    Date d3 = d2;

    d3.print();

    d3.setYear(1956);
    d3.setMonth(2);
    d3.setDay(8);

    std::cout << d3.dayOfWeek();
}