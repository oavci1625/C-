/*
Onuralp Avcı
21902364
Section-2
**/

#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H

#include<string>

class Student{
    public:
        Student(int id, std::string name);
        ~Student();

        int id;
        std::string name;
        Student* link;

        int getId();
        std::string getName();
        void setLink(Student* link);
        Student* getLink();
};

#endif