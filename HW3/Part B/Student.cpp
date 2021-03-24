/*
Onuralp Avcı
21902364
Section-2
**/

#include<string>
#include"Student.h"
#include <iostream>
using namespace std;

Student::Student(int id, std::string name){
    Student::id = id;
    Student::name = name;
    Student::link = 0;
    Student::head = 0;
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

void Student::addBook( Book* bookPtr){ //Assuing that book exsist in the library and not checked out by any other student
    if( head == 0){
        head = bookPtr;
    }
    else{
        Book* last = head;
        while( last->getPrivateLink() != 0){
            last = last->getPrivateLink();
        }
        last->setPrivateLink( bookPtr);
    }
};

void Student::removeBook(const int bookId){
    if(!head){
        cout<<"No book is checked"<<endl;
    }
    else{
        if(head->getId() == bookId){//If first one is to be deleted
            Book* next = head->getPrivateLink();
            head->setOwner(0);
            head->setStatus(false);
            head->setPrivateLink(0);
            head = next;
        }
        else{//Now checking for other elements
            Book* removePtr = 0;
            Book* last = head;
            while( last->getPrivateLink() != 0 && removePtr == 0){
                if( last->getPrivateLink()->getId() == bookId){
                    removePtr = last->getPrivateLink();
                }
                else{
                    last = last->getPrivateLink();
                }
            }

            if(removePtr == 0)
                cout<<"No book to be returned"<<endl;
            else{
                Book* next = removePtr->getPrivateLink();
                removePtr->setOwner(0);
                removePtr->setStatus(false);
                removePtr->setPrivateLink(0);
                last->setPrivateLink( next);
            }
        }
    }
};

void Student::showBooks(){
    if(!head){
        cout<<"No book checked";
    }
    else{
        cout<<"Book id     Book Name     Year"<<endl;
        Book* last = head;
        do{
            cout<<last->getId()<<"     "<<last->getTitle()<<"      "<<last->getYear()<<endl;
            last=last->getPrivateLink();
        }while( last != 0);
    }
};

void Student::removeAllBooks(){
    Book* last = head;
    while(last){
        Book* temp = last->getPrivateLink();
        removeBook(last->getId());
        cout<<"Book "<<last->getId()<<" has been returned"<<endl;
        last=temp;
    }
};