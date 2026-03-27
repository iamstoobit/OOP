/*Условие:
Задача 1.
Реализирайте структура, която описва плод. Един плод се характеризира с:
 - име (символен низ с максимална дължина 16)
 - цвят - една от стойностите brown, pink, green, orange, red, yellow, other
 - информация за наличие на следните свойства (истина или лъжа):
	= едногодишен плод 
	= тропически
	= сладък
	= с костилка
	= расте на дърво
 - енергийност (калории на 100г) - цяло число

Напишете функции за:
а) прочитане на данни за плод от подаден текстов поток (използвайте типа istream). Валидирайте входа за всякакви грешки.

б) записване на данни за плод в подаден текстов поток (използвайте типа оstream). Важно - форматът на изход трябва да
е валиден за последващ вход (каквото е записано трябва да може да се прочете коректно).

в) записване на данни за плод в подаден двоичен файл (използвайте типа ofstream).

г) прочитане на данни за плод от подаден двоичен файл (използвайте типа ifstream).

д) сравнение на два плода за равенство - като критерии за равенство използвайте името и свойствата.
Приемаме, че може да имате например две ябълки, които са с различен цвят и енергийност, но ще ги считаме за равни.

е) функция, която подрежда (сортира) масив от плодове по азбучен ред на името им.
Ако имат равни имена, нека по-малък е плода с по-ниска енергийност.

ж) функция, която по подаден текстов файл със записи за плодове извежда на екрана всички с определен цвят.

з) функция, която по подаден двоичен файл със записи за плодове премахва от него повтарящите се плодове.

и) функция, която по подаден текстов файл със записи за плодове и подадени старо и ново име заменя името
на всеки плод със старото име на новото. Реализирайте версия на същата функция, работеща със двоичен файл.

Напишете програма, която демонстрира работата на всяка от функциите.
Програмата трябва да позволява на потребителя да въвежда данни от клавиатурата и да ги записва във текстов или двоичен файл.
Трябва да може също да работи с вече съхранени в текстов или двоичен файл данни или да добавя нови към тях.
*/

#include <iostream>
#include <cstring>
#include <fstream>

enum Colour {
    BROWN,
    PINK,
    GREEN,
    ORANGE,
    RED,
    YELLOW,
    OTHER = -1
};

struct Fruit{
    char name[16];
    Colour colour;
    bool oneYear;
    bool tropical;
    bool sweet;
    bool withBone;
    bool growsOnTrees;
    unsigned short kcal;
};

bool readInt(std::istream& is, short& number) {
    is >> number;
    if(is.good()) {
        is.get();
        return true;
    }

    else {
        return false;
    }
}

//a)
Fruit readFromTxt(std::istream& is) {
    int curPos = is.tellg();
    Fruit result;
    char name[16];
    short colour;
    bool oneYear;
    bool tropical;
    bool sweet;
    bool withBone;
    bool growsOnTrees;
    unsigned short kcal;

    is.getline(name, sizeof(name), ',');

    if(is.good()) {
        strcpy(result.name, name);
    }

    else {
        if(is.eof()) {
            if(!is.fail()) {
                is.seekg(curPos);
                is.clear();
                strcpy(result.name, name);
                return result;
            }
        }

        else if(is.fail()) {
            return result;
        }
    }

    if(readInt(is, colour)) {
        result.colour = (Colour)colour;
    }

    else {
        is.seekg(curPos);
        return result;
    }

    short stats[6];
    for(int i = 0; i < 6; ++i) {
        if(!readInt(is, stats[i])) {
            is.seekg(curPos);
            return result;
        }
    }

    result.oneYear = (bool)stats[0];
    result.tropical = (bool)stats[1];
    result.sweet = (bool)stats[2];
    result.withBone = (bool)stats[3];
    result.growsOnTrees = (bool)stats[4];
    result.kcal = stats[5];

    is.seekg(curPos);

    return result;
}
//б)
void writeInTxt(std::ostream& os, const Fruit& fruit) {
    int curPos = os.tellp();
    os << fruit.name << ',' << fruit.colour << ',' << fruit.oneYear << ',' <<
        fruit.tropical << ',' << fruit.sweet << ',' << fruit.withBone << ',' <<
        fruit.growsOnTrees << ',' << fruit.kcal << '\n';
}
//в)
bool writeInBin(const char* file, const Fruit& fruit) {
    std::ofstream ofs(file, std::ios::binary | std::ios::app);

    if(!ofs.is_open()) {
        return false;
    }

    ofs.write((const char*)&fruit, sizeof(Fruit));

    if(!ofs.good()) {
        return false;
    }

    ofs.close();
    return true;
}
//г) прочитане на данни за плод от подаден двоичен файл (използвайте типа ifstream).
bool readFromBin(std::ifstream& ifs, Fruit& destination) {
    ifs.read((char*)&destination, sizeof(Fruit));

    if(ifs.gcount() == sizeof(Fruit)) {
        return true;
    }

    return false;
}

int compare(const Fruit& lhs, const Fruit& rhs);

void sortFruits(Fruit*& arr);

void printFromFile(const char* file);

void removeDoubledFromBin(const char* file);

void changeNameInTxt(const char* file, const char* oldName, const char* newName);

int main() {
    Fruit a{"apple", Colour::RED, true, false, true, false, true, 30};
    Fruit b(a);
    Fruit c{"banana", Colour::YELLOW, true, true, true, false, true, 57};

    std::cout << std::boolalpha;
    std::cout << writeInBin("fruits.bin", a) << '\n';
    std::cout << writeInBin("fruits.bin", b) << '\n';
    std::cout << writeInBin("fruits.bin", c) << '\n';

    std::ifstream ifs("fruits.bin", std::ios::binary);

    Fruit d;
    std::cout << readFromBin(ifs, d) << '\n';
    std::cout << d.colour << ' ' << d.oneYear << ' ' << d.kcal << '\n';
    
    Fruit e;
    readFromBin(ifs, e);
    std::cout << e.colour << ' ' << e.oneYear << ' ' << e.kcal << '\n';

    Fruit f;
    readFromBin(ifs, f);
    std::cout << f.colour << ' ' << f.oneYear << ' ' << f.kcal;




    ifs.close();

    return 0;
}