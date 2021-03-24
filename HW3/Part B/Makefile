main: Book.o Student.o LibrarySystem.o main.o
	g++ -o main Book.o Student.o LibrarySystem.o main.o

Book.o: Book.cpp
	g++ -c Book.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

LibrarySystem.o: LibrarySystem.cpp
	g++ -c LibrarySystem.cpp

main.o: main.cpp
	g++ -c main.cpp