/*
Условие:
Реализирайте функция със следната сигнатура:
void replace(const char* fileName, const char* find, const char* replace);
която да замества всички срещания на думата find с думата replace в текстов файл с име fileName.

Пример (извикваме функцията с параметри "princesa.txt", "princesa", "strandzhanka"):

Преди излълнение на програмата:

Prepechena filiq s kaima se naricha princesa i tova ne podlezhi na komentar.
Sinut na princesa Diana se kazva Harry.
Princ Karl i princesa Klara krali klarineti...

След излълнение на програмата:

Prepechena filiq s kaima se naricha strandzhanka i tova ne podlezhi na komentar.
Sinut na strandzhanka Diana se kazva Harry.
Princ Karl i strandzhanka Klara krali klarineti...
*/

#include <iostream>
#include <cstring>
#include <fstream>

void replace(const char* fileName, const char* find, const char* replace) {
    std::ifstream ifs(fileName);

    if(!ifs.is_open()) {
        std::cout << "File could not be opened for reading.";
        return;
    }

    std::string buffer;

    for(int i = 0; !ifs.eof(); ++i) {
        buffer.push_back(ifs.get());
    }

    int pos = buffer.find(find);
    while (pos != std::string::npos) {
        buffer.replace(pos, strlen(find), replace);
        pos = buffer.find(find, pos);
    }

    ifs.close();

    std::ofstream ofs(fileName);

    if(!ofs.is_open()) {
        std::cout << "File could not be opened for writing.";
        return;
    }

    ofs << buffer;
}

int main() {
    replace("princesa.txt", "princesa", "strandzhanka");

    return 0;
}