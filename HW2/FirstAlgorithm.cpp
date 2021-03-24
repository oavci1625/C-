using namespace std;
#include "FirstAlgorithm.h"
#include<iostream>


int*  mergeFirstAlgorithm(int* sortedArray1, int* sortedArray2, int sizeN) 
{ 
    int* resultArray = new int[2* sizeN];
    int count = sizeN; 

    for (int i = 0; i < sizeN; i++)
    {
        resultArray[i] = sortedArray1[i];
    }

    for (int i = 0; i < sizeN; i++)
    {
        int index = count;
        for (int j = 0; j < count; j++)
        {
            if(sortedArray2[i] < resultArray[j]){
                index = j;
                j = count;
            }
        }

        //Move elements by one
        for (int k = 0; k < count - index; k++)
        {
            resultArray[count- k] = resultArray[count - 1 - k];
        }
        resultArray[index] = sortedArray2[i];
        count++;
    }
    
    return resultArray;
} 