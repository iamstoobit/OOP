/*
Условие:
а)Напишете програма която прочита два текстови файла и създава трети със съдържанието на първия и втория.

б)Напишете програма която премахва всички празни редове от новополучения текстов файл.

в)Напишете програма, която променя текстов файл като - преобразува всички главни букви в малки и обратното, ако има такива.
*/

#include <iostream>
#include <cstring>
#include <fstream>

//a)
void copyTwoInOne(const char* first, const char* second, const char* newFile) {
    std::ifstream ifsFirst(first);
    std::ofstream ofs(newFile);

    if(!ifsFirst.is_open() || !ofs.is_open()) {
        std::cout << "Error opening file.";
        return;
    }

    std::string buffer;

    for(int i = 0; !ifsFirst.eof(); ++i) {
        buffer.push_back(ifsFirst.get());
    }

    ifsFirst.close();

    ofs << buffer;

    std::ifstream ifsSecond(second);

    if(!ifsSecond.is_open()) {
        std::cout << "Error opening file.";
        return;
    }

    buffer.clear();

    for(int i = 0; !ifsSecond.eof(); ++i) {
        buffer.push_back(ifsSecond.get());
    }

    ifsSecond.close();

    ofs << buffer;

    ofs.close();
}

//б)
void removeNewLines(const char* fileName) {
    std::ifstream ifs(fileName);

    if(!ifs.is_open()) {
        std::cout << "Error opening file.";
        return;
    }

    std::string buffer;

    for(int i = 0; !ifs.eof(); ++i) {
        buffer.push_back(ifs.get());
    }
    
    ifs.close();

    int pos = buffer.find('\n');
    while(pos != buffer.npos) {
        buffer.erase(pos, 1);
        pos = buffer.find('\n');
    }

    std::ofstream ofs(fileName);

    if(!ofs.is_open()) {
        std::cout << "Error opening file.";
        return;
    }

    ofs << buffer;
}

//в)
void changeLetters(const char* fileName) {
    std::ifstream ifs(fileName);

    if(!ifs.is_open()) {
        std::cout << "Error opening file.";
        return;
    }

    std::string buffer;

    for(int i = 0; !ifs.eof(); ++i) {
        buffer.push_back(ifs.get());
    }
    
    ifs.close();

    for(int i = 0; i < buffer.length(); ++i) {
        if(buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] -= 32;
        }

        else if(buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] += 32;
        }
    }

    std::ofstream ofs(fileName);

    if(!ofs.is_open()) {
        std::cout << "Error opening file.";
        return;
    }

    ofs << buffer;
}

int main() {
    changeLetters("blahblah.txt");

    return 0;
}