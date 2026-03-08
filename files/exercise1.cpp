/*
Условие:
Дефинирайте структура Person. Член данни: име – символен низ с дължина най-много 63 символа,
пол – булева стойност, години – неотрицателно число.

Създайте функция, която записва масив от Person в текстов файл. Всеки човек се записва на нов ред.
Член данните се разделят с интервал. Функцията приема като параметри масива, размера му и името на файла.

Дефинирайте функция за четене на Person от текстов файл
*/

#include <iostream>
#include <fstream>

struct Person {
    char name[63];
    bool sex;
    unsigned short age;
};

void writePeople(const Person* p, const int size, const char* fileName) {
    std::ofstream ofs(fileName, std::ios::app);

    if(!ofs.is_open()) {
        return;
    }

    for(size_t i = 0; i < size; ++i) {
        ofs << p[i].name << " " << p[i].sex << " " << p[i].age << '\n';
    }

    ofs.close();
}

Person readPerson() {
    Person result;
    std::ifstream ifs("People.txt");

    if(!ifs.is_open()) {
        return result;
    }

    ifs >> result.name;
    ifs >> result.sex;
    ifs >> result.age;

    return result;
}

int main() {
    Person p1{"Person1", 0, 13};
    Person p2{"Person2", 1, 25};
    Person arr[2] = {p1, p2};
    Person arr2[3] = {p2, p1, p1};
    
    writePeople(arr, 2, "People.txt");
    writePeople(arr2, 3, "People.txt");

    Person p3 = readPerson();

    return 0;
}
