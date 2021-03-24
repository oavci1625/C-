/*
Onuralp Avcı
21902364
Section-2
**/

#include "LibrarySystem.h"
#include <iostream>
using namespace std;


LibrarySystem::LibrarySystem(){
    studentHead = 0;
    bookHead = 0;
};

LibrarySystem::~LibrarySystem(){
    deleteAllBooks();
    deleteAllStudents();
};

void LibrarySystem::addBook(const int bookId, const std::string bookName, const int bookYear){
    if( bookHead == 0){
        bookHead = new Book( bookId, bookName, bookYear);
        cout<<"Book "<<bookId<<" has been added"<<endl;
    }
    else{
        if( findBook(bookId) == 0){
            Book* last = bookHead;
            while( last->getMainLink() != 0){
                last = last->getMainLink();
            }
            last->setMainLink( new Book( bookId, bookName, bookYear));
            cout<<"Book "<<bookId<<" has been added"<<endl;
        }
        else{
            cout<<"Book "<<bookId<<" already exists"<<endl;
        }
    }
};

void LibrarySystem::deleteBook(const int bookId){
    if(!bookHead){
        cout<<"Book "<<bookId<<" does not exist"<<endl;
    }
    else{
        if(bookHead->getId() == bookId){//If first one is to be deleted
            if(bookHead->checked){
                //First return
                Student* studentPtr = findStudent(bookHead->getOwner());
                studentPtr->removeBook(bookId);
                cout<<"Book "<<bookId<<" has been returned"<<endl;
            }
            else{
                cout<<"Book "<<bookId<<" has not been checked out"<<endl;
            }

            Book* tempHead = bookHead->getMainLink();
            delete bookHead;
            bookHead = tempHead;
            cout<<"Book "<<bookId<<" has been deleted"<<endl;
        }
        else{//Now checking for other elements
            Book* deletePtr = 0;
            Book* last = bookHead;
            while( last->getMainLink() != 0 && deletePtr == 0){
                if( last->getMainLink()->getId() == bookId){
                    deletePtr = last->getMainLink();
                }
                else{
                    last = last->getMainLink();
                }
            }

            if(deletePtr == 0)
                cout<<"Book "<<bookId<<" does not exist"<<endl;
            else{
                if(bookHead->checked){
                    //First return
                    Student* studentPtr = findStudent(bookHead->getOwner());
                    studentPtr->removeBook(bookId);
                    cout<<"Book "<<bookId<<" has been returned"<<endl;
                }
                else{
                    cout<<"Book "<<bookId<<" has not been checked out"<<endl;
                }
                last->setMainLink( deletePtr->getMainLink());
                delete deletePtr;
                cout<<"Book "<<bookId<<" has been deleted"<<endl;
            }
        }
    }
};

void LibrarySystem::addStudent(const int studentId, const std::string studentName){
    if( studentHead == 0){
        studentHead = new Student( studentId, studentName);
        studentHead->setLink(0);
        cout<<"Student "<<studentId<<" has been added"<<endl;
    }
    else{
        if( findStudent(studentId) == 0){
            Student* last = studentHead;
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
    if(!studentHead){
        cout<<"Student "<<studentId<<" does not exist"<<endl;
    }
    else{
        if(studentHead->getId() == studentId){//If first one is to be deleted
            studentHead->removeAllBooks();
            Student* tempHead = studentHead->getLink();
            delete studentHead;
            studentHead = tempHead;
            cout<<"Student "<<studentId<<" has been deleted"<<endl;
        }
        else{//Now checking for other elements
            Student* deletePtr = 0;
            Student* last = studentHead;
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
                deletePtr->removeAllBooks();
                last->setLink( deletePtr->getLink());
                delete deletePtr;
                cout<<"Student "<<studentId<<" has been deleted"<<endl;
            }
        }
    }
};

Student* LibrarySystem::findStudent(const int studentId) const{
    if(!studentHead){
        return 0; //No student in the list
    }
    else{
        Student* last = studentHead;
        while( last){
            if( last->getId() == studentId)
                return last; //Student already exists
            else
                last = last->getLink();
        }
        return 0; //Student is not found in the list
    }
};

Book* LibrarySystem::findBook(const int bookId) const{
    if(!bookHead){
        return 0; //No book in the list
    }
    else{
        Book* last = bookHead;
        while( last){
            if( last->getId() == bookId)
                return last; //Book already exists
            else
                last = last->getMainLink();
        }
        return 0; //Book is not found in the list
    }
};

void LibrarySystem::checkoutBook(const int bookId, const int studentId){
    Book* bookPtr = findBook(bookId);
    Student* studentPtr = findStudent(studentId);
    if( bookPtr != 0 ){
        if( studentPtr != 0 ){
            if(bookPtr->checked==false){
                studentPtr->addBook(bookPtr);
                bookPtr->setStatus(true);
                bookPtr->owner=studentPtr->id;
                bookPtr->setPrivateLink(0);
                cout<<"Book "<<bookId<<" has been checked out bu student "<<studentId<<endl;
            }
            else{
                cout<<"Book "<<bookId<<" has been already checked out by another student"<<endl;
            }
        }
        else{
            cout<<"Student "<<studentId<<" does not exist for checkout"<<endl;
        }
    }
    else{
        cout<<"Book "<<bookId<<" does not exist for checkout"<<endl;
    }
};

void LibrarySystem::returnBook(const int bookId){
    Book* bookPtr = findBook(bookId);
    if( bookPtr != 0){
        if(bookPtr -> checked == true){
            int owner = bookPtr->owner;
            Student* ownerPtr = findStudent(owner);
            ownerPtr->removeBook(bookId);
            cout<<"Book "<<bookId<<" has been returned"<<endl;
        }
        else{
            cout<<"Book "<<bookId<<" has not been checked out"<<endl;
        }
    }
    else{
        cout<<"Book "<<bookId<<" does not exist for return"<<endl;
    }
};

void LibrarySystem::showAllBooks() const{
    if(!bookHead){
        cout<<"No book in the library"<<endl;
    }
    else{
        cout<<"Book id     Book name      Year    Status"<<endl;
        Book* last = bookHead;
        while(last != 0){
            if(last->checked)
                cout<<last->getId()<<"   "<<last->getTitle()<<"        "<<last->getYear()<<"     Checked out by student "<<last->getOwner()<<endl;
            else
                cout<<last->getId()<<"   "<<last->getTitle()<<"        "<<last->getYear()<<"     Not checked out"<<endl;
        last = last->getMainLink();
        }
    }
};

void LibrarySystem::showBook(const int bookId) const{
    if(!bookHead){
        cout<<"No book in the library"<<endl;
    }
    else{
        Book* bookPtr = findBook(bookId);
        if(bookPtr == 0){
            cout<<"Book is not found"<<endl;
        }
        else{
            if( bookPtr->checked)
                cout<<bookPtr->getId()<<"    "<<bookPtr->getTitle()<<"    "<<bookPtr->getYear()<<"   Checked out by student "<<bookPtr->getOwner()<<endl;
            else
                cout<<bookPtr->getId()<<"    "<<bookPtr->getTitle()<<"    "<<bookPtr->getYear()<<"   Not checked out"<<endl;
        }
    }
};

void LibrarySystem::showStudent(const int studentId) const{
    if( !studentHead){
        cout<<"Student "<<studentId<<" does not exist"<<endl;
    }
    else{
        Student* studentPtr = findStudent(studentId);
        if( studentPtr == 0)
            cout<<"Student "<<studentId<<" does not exist"<<endl;
        else{
            cout<<"Student id: "<<studentPtr->getId()<<" student name: "<<studentPtr->getName()<<endl;
            if(studentPtr->head == 0){
                cout<<"Student "<<studentPtr->getId()<<" has no books"<<endl;
            }
            else{
                cout<<"Student "<<studentPtr->getId()<<" checked out the following books:"<<endl;
                studentPtr->showBooks();
            }
        }
    }
    
};

void LibrarySystem::deleteAllBooks(){
    if(!bookHead){
        return;
    }
    else{
        Book* deletePtr = bookHead;
        Book* nextPtr;
        do
        {
            nextPtr = deletePtr ->getMainLink();
            delete deletePtr;
            deletePtr = nextPtr;
        } while (deletePtr != 0);
    }
};

void LibrarySystem::deleteAllStudents(){
    if(!studentHead){
        return;
    }
    else{
        Student* deletePtr = studentHead;
        Student* nextPtr;
        do
        {
            nextPtr = deletePtr ->getLink();
            delete deletePtr;
            deletePtr = nextPtr;
        } while (deletePtr != 0);
    }
    
};