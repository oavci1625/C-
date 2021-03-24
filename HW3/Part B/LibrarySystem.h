/*
Onuralp Avcı
21902364
Section-2
**/

#include<string>
#include"Student.h"
#include"Book.h"

class LibrarySystem {
    public:
        Student* studentHead;
        Book* bookHead;
        LibrarySystem();
        ~LibrarySystem();
        void addBook(const int bookId, const std::string bookName, const int bookYear);
        void deleteBook(const int bookId);
        void addStudent(const int studentId, const std::string studentName);
        void deleteStudent(const int studentId);
        void checkoutBook(const int bookId, const int studentId);
        void returnBook(const int bookId);
        void showAllBooks() const;
        void showBook(const int bookId) const;
        void showStudent(const int studentId) const;
        Student* findStudent(const int studentId) const;
        Book* findBook(const int bookId) const;

        void deleteAllBooks();
        void deleteAllStudents();
};