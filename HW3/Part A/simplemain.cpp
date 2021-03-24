/*
Onuralp Avcı
21902364
Section-2
**/

#include "SimpleLibrarySystem.h"

int main(){
    LibrarySystem system;
    system.addStudent(1, "Onuralp");
    system.addStudent(2, "Ahmet");
    system.addStudent(3, "Burak");
    system.addStudent(4, "Melis");
    system.addStudent(5, "Cansu");

    system.showStudent(0);
    system.showStudent(1);
    system.showStudent(2);
    system.showStudent(3);
    system.showStudent(4);
    system.showStudent(5);

    system.deleteStudent(0);
    system.deleteStudent(1);
    system.deleteStudent(2);
    system.deleteStudent(3);
    system.deleteStudent(4);
    system.deleteStudent(5);

    system.showStudent(0);
    system.showStudent(1);
    system.showStudent(2);
    system.showStudent(3);
    system.showStudent(4);
    system.showStudent(5);
    return 0;
}