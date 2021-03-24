/*
Onuralp Avcı
21902364
Section-2
**/

#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include "Book.h"

class Student{
    public:
        Student(int id, std::string name);
        ~Student();

        int id;
        std::string name;
        Student* link;
        Book* head;

        int getId();
        std::string getName();
        void setLink(Student* link);
        Student* getLink();
        void addBook( Book* bookPtr);
        void removeBook(const int bookId);
        void showBooks();
        void removeAllBooks();
};

#endif