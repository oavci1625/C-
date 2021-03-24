//Onuralp Avci
//21902364

#include "Stack.h"

Stack::Stack(){
    count = 0;
    topPtr = 0;
    flightArray = 0;
}
Stack::~Stack(){
    while(!isEmpty()){
        pop();
    }
}

bool Stack::isEmpty() const{
    return topPtr == NULL;
}

bool Stack::push(int newItem){
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    count++;
    return true;
}

bool Stack::pop(){
    if(isEmpty()){
        return false;
    }else{
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
        count--;
        return true;
    }
}

bool Stack::pop(int& stackTop){
    if(isEmpty()){
        return false;
    }else{
        stackTop = topPtr->item;
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
        count--;
        return true;
    }
}

bool Stack::getTop(int& stackTop) const{
    if(isEmpty()){
        return false;
    }else{
        stackTop = topPtr->item;
        return true;
    }
}

int* Stack::arrayOfFlight(){
    flightArray = new int(count);
    StackNode* temp = topPtr;
    for (int i = 0; i < count; i++)
    {
        flightArray[count - i -1] = temp->item;
        temp = temp->next;
    }
    
    return flightArray;
}

int Stack::getSize(){
    return count;
}

