/*
Onuralp Avcı
21902364
Section-2
**/

#ifndef BOOK_H
#define BOOK_H

#include<string>

class Book{
    public:
        Book(int id, std::string title, int yead);
        ~Book();

        int id;
        std::string title;
        int year;
        Book* mainLink;
        Book* privateLink;
        bool checked;
        int owner;

        int getId();
        std::string getTitle();
        int getYear();
        void setMainLink(Book* link);
        Book* getMainLink();
        void setPrivateLink(Book* link);
        Book* getPrivateLink();
        void setStatus(bool checked);
        bool ifchecked();
        void setOwner(int owner);
        int getOwner();
};

#endif