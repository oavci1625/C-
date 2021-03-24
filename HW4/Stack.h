//Onuralp Avci
//21902364

#include <iostream>
#include <string>
using namespace std;
class Stack
{
public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    bool push(int newItem);
    bool pop();
    bool pop(int& stackTop);
    bool getTop(int& stackTop) const;
    int* arrayOfFlight();
    int getSize();
    int count;
    int* flightArray;

    struct StackNode{
        int item;
        StackNode* next;
    };
    StackNode* topPtr;
};

