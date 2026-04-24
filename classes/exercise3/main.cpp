#include <iostream>
#include "Array.h"

int main() {
    std::cout << "--------------- Constructors ---------------" << '\n';
    Array a(10);
    Array b = a;
    
    std::cout << "a: ";
    a.print();
    std::cout << "b: ";
    a.print();

    std::cout << '\n' << "--------------- pushBack ---------------" << '\n';

    std::cout << "a: ";
    a.print();

    a.pushBack(2);
    a.pushBack(4);
    a.pushBack(5);
    a.pushBack(8);
    a.pushBack(8);
    a.pushBack(5);
    a.pushBack(9);
    a.pushBack(7);

    b.pushBack(6);
    b.pushBack(1);
    b.pushBack(5);
    b.pushBack(6);
    b.pushBack(6);
    b.pushBack(2);
    b.pushBack(4);
    b.pushBack(4);
    
    std::cout << "\na: ";
    a.print();

    std::cout << '\n' << "--------------- pushBack + resize ---------------" << '\n';

    std::cout << "a: ";
    a.print();

    a.pushBack(1);
    a.pushBack(1);
    a.pushBack(1);
    
    std::cout << "\na: ";
    a.print();

    std::cout << '\n' << "--------------- changeElement ---------------" << '\n';

    std::cout << "a: ";
    a.print();

    a.changeElement(3, 7);
    a.changeElement(0, 1);
    a.changeElement(25, 2);
    
    std::cout << "\na: ";
    a.print();

    std::cout << '\n' << "--------------- removeElement ---------------" << '\n';

    std::cout << "a: ";
    a.print();
    
    a.removeElement(5);
    a.removeElement(7);
    a.removeElement(14);
    
    std::cout << "\na: ";
    a.print();

    std::cout << '\n' << "--------------- operator+ | operator+= ---------------" << '\n';

    Array c = a;
    a.pushBack(3);
    std::cout << "a: ";
    a.print();
    std::cout << "b: ";
    b.print();
    std::cout << "c: ";
    c.print();
    
    a = a + c;
    c += a;
    b += c;

    std::cout << "\na: ";
    a.print();
    std::cout << "b: ";
    b.print();
    std::cout << "c: ";
    c.print();

    std::cout << '\n' << "--------------- operator- | operator-= ---------------" << '\n';

    std::cout << "a: ";
    a.print();
    std::cout << "c: ";
    c.print();
    
    c -= a;
    a = c - a;
    
    std::cout << "\na: ";
    a.print();
    std::cout << "c: ";
    c.print();

    std::cout << '\n' << "--------------- operator* | operator*= ---------------" << '\n';

    std::cout << "a: ";
    a.print();
    std::cout << "b: ";
    b.print();
    std::cout << "c: ";
    c.print();
    
    c = a * b;
    a *= c;
    
    std::cout << "\na: ";
    a.print();
    std::cout << "b: ";
    b.print();
    std::cout << "c: ";
    c.print();

    std::cout << '\n' << "--------------- operator[] | at ---------------" << '\n';

    std::cout << "a: ";
    a.print();
    std::cout << "b: ";
    b.print();
    std::cout << "c: ";
    c.print();
    
    std::cout << a[5] << '\n';
    std::cout << b.at(6) << '\n';
    std::cout << c[30] << '\n';
    std::cout << c.at(20) << '\n';

    std::cout << '\n' << "--------------- operator[] | at ---------------" << '\n';

    return 0;
}
