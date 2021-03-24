/*
Onuralp Avcı
21902364
Section-2
**/

#include "SimpleLibrarySystem.h"
#include <iostream>
using namespace std;


LibrarySystem::LibrarySystem(){
    head = 0;
};

LibrarySystem::~LibrarySystem(){
    deleteAllStudents();
};

void LibrarySystem::addStudent(const int studentId, const std::string studentName){
    if( checkStudent(studentId) == 0){
        delete head;
        head = new Student( studentId, studentName);
        head->setLink(0);
        cout<<"Student "<<studentId<<" has been added"<<endl;
    }
    else{
        if( checkStudent(studentId) == 2){
            Student* last = head;
            while( last->getLink() != 0){
                last = last->getLink();
            }
            last->setLink( new Student(studentId, studentName));
            cout<<"Student "<<studentId<<" has been added"<<endl;
        }
        else{
            cout<<"Student "<<studentId<<" already exists"<<endl;
        }
    }
};
void LibrarySystem::deleteStudent(const int studentId){
    if(!head){
        cout<<"Student "<<studentId<<" does not exist"<<endl;
    }
    else{
        if(head->getId() == studentId){//If first one is to be deleted
            Student* tempHead = head->getLink();
            delete head;
            head = tempHead;
            cout<<"Student "<<studentId<<" has been deleted"<<endl;
        }
        else{//Now checking for other elements
            Student* deletePtr = 0;
            Student* last = head;
            while( last->getLink() != 0 && deletePtr == 0){
                if( last->getLink()->getId() == studentId){
                    deletePtr = last->getLink();
                }
                else{
                    last = last->getLink();
                }
            }

            if(deletePtr == 0)
                cout<<"Student "<<studentId<<" does not exist"<<endl;
            else{
                last->setLink( deletePtr->getLink());
                delete deletePtr;
                cout<<"Student "<<studentId<<" has been deleted"<<endl;
            }
        }
    }

};
void LibrarySystem::showStudent(const int studentId)const{
    if(!head){
        cout<<"Student "<<studentId<<" does not exist"<<endl;
    }
    else{
        Student* last = head;
        while( last != 0){
            if( last->getId() == studentId){
                cout<<"Student id: "<<studentId<<" student name: "<<last->getName()<<endl;
                return;
            }
            else{
                last = last->getLink();
            }
        }
        cout<<"Student "<<studentId<<" does not exist"<<endl;
    }
};

int LibrarySystem::checkStudent(const int studentId){
    if(!head){
        return 0; //No student in the list
    }
    else{
        Student* last = head;
        while( last != 0){
            if( last->getId() == studentId)
                return 1; //Student already exists
            else
                last = last->getLink();
        }
        return 2; //Student is not found in the list
    }
};

void LibrarySystem::deleteAllStudents(){
    if(!head){
        return;
    }
    else{
        Student* deletePtr = head;
        Student* nextPtr;
        do
        {
            nextPtr = deletePtr ->getLink();
            delete deletePtr;
            deletePtr = nextPtr;
        } while (deletePtr != 0);
    }
    
};