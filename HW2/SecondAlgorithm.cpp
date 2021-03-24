using namespace std;
#include "SecondAlgorithm.h"
  

int*  mergeSecondAlgorithm(int* sortedArray1, int* sortedArray2, int sizeN) 
{ 
    int* resultArray = new int[2* sizeN];

    int i =0;
    int j = 0;
    int k = 0;
    for (k = 0; i<sizeN && j <sizeN; k++)
    {
        if (sortedArray1[i] < sortedArray2[j]){
            resultArray[k] = sortedArray1[i];
            i++; 
        }
        else{
            resultArray[k] = sortedArray2[j];
            j++;
        }
    }
    
  
    if(i < sizeN){
        while (i < sizeN){
            resultArray[k] = sortedArray1[i];
            k++;
            i++;
        }
            
    }
    else{
        while (j < sizeN){
            resultArray[k] = sortedArray2[j];
            k++;
            j++;
        }
    }
    
    return resultArray;
} 