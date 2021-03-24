/*
Onuralp Avcı
21902364
Section-2
**/

#include<string>
#include"SimpleStudent.h"
using namespace std;

Student::Student(int id, std::string name){
    Student::id = id;
    Student::name = name;
    Student::link = 0;
};

Student::~Student(){};

int Student::getId(){
    return id;
};
std::string Student::getName(){
    return name;
};
void Student::setLink(Student* link){
    Student::link = link;
};
Student* Student::getLink(){
    return Student::link;
};
