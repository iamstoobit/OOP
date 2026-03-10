/*
Условие:
Напишете програма, която записва и чете данни в текстов файл масиви от
обекти на структура, която съдържа следната информация за един студент:

firstName (char array)
lastName (char array)
facultyNumber(char array)
takenCourses(int)
averageGrade(double)
hasTakenAllCourses(bool)
*/

#include <iostream>
#include <fstream>

constexpr int MAX_NAME_LENGTH = 32;
constexpr int MAX_FN_LENGTH = 10;
constexpr int BUFF_SIZE = 1024;

struct Student {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char facultyNumber[MAX_FN_LENGTH];
    int takenCourses;
    double averageGrade;
    bool hasTakenAllCourses;
};

void writeStudents(const Student* arr, const int size) {
    std::ofstream ofs("Students.txt", std::ios::app);

    if(!ofs.is_open()) {
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        ofs << arr[i].firstName << " " << arr[i].lastName << " " << arr[i].facultyNumber << " "
            << arr[i].takenCourses << " " << arr[i].averageGrade << " " << arr[i].hasTakenAllCourses << '\n';
    }

    ofs.close();
}

Student* readStudents(const int size) {
    std::ifstream ifs("Students.txt");

    if(!ifs.is_open()) {
        return nullptr;
    }

    char* buffer = new char[BUFF_SIZE];

    Student* result = new Student[size];

    for(size_t i = 0; i < size; ++i) {
        ifs >> result[i].firstName >> result[i].lastName >> result[i].facultyNumber >> result[i].takenCourses >> result[i].averageGrade >> result[i].hasTakenAllCourses;
    }

    return result;
}

int main() {
    Student s1{"Steven", "He", "FA1L1UR3", 15, 5.9, 0};
    Student s2{"Heven", "Ste", "3M0T10NAL", 13, 5.98, 0};
    Student s3{"He", "Steven", "DAMA63", 11, 5.97, 0};

    Student students[3] = {s1, s2, s3};

    writeStudents(students, 3);

    Student* arr = readStudents(3);

    for(int i = 0; i < 3; i++) {
        std::cout << arr[i].firstName << arr[i].lastName << arr[i].facultyNumber << '\n';
    }
    
    return 0;
}
