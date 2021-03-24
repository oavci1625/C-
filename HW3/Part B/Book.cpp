/*
Onuralp Avcı
21902364
Section-2
**/

#include<string>
#include"Book.h"
using namespace std;

Book::Book(int id, std::string title, int year){
    Book::id = id;
    Book::title = title;
    Book::year = year;
    Book::mainLink = 0;
    Book::privateLink = 0;
    Book::checked = false;
    Book::owner = 0;
};

Book::~Book(){};

int Book::getId(){
    return id;
};
std::string Book::getTitle(){
    return title;
};
int Book::getYear(){
    return year;
};
void Book::setMainLink(Book* link){
    Book::mainLink = link;
};
Book* Book::getMainLink(){
    return mainLink;
};
void Book::setPrivateLink(Book* link){
    Book::privateLink = link;
};
Book* Book::getPrivateLink(){
    return privateLink;
};
void Book::setStatus(bool checked){
    Book::checked = checked;
};
bool Book::ifchecked(){
    return checked;
};
void Book::setOwner(int owner){
    Book::owner = owner;
};
int Book::getOwner(){
    return owner;
};
