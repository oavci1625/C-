/*
Onuralp Avcı
21902364
Section-2
**/

#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H

#include<string>
#include"SimpleStudent.h"

class LibrarySystem {
    public:
        Student* head;
        LibrarySystem();
        ~LibrarySystem();
        void addStudent(const int studentId, const std::string studentName);
        void deleteStudent(const int studentId);
        void showStudent(const int studentId) const;
        int checkStudent(const int studentId);

        void deleteAllStudents();
};

#endif