#include<iostream>
#include <ctime>
#include <algorithm>

using namespace std; 

int*  mergeFirstAlgorithm(int* sortedArray1, int* sortedArray2, int sizeN) 
{ 
    int* resultArray = new int[2* sizeN];
    int count = sizeN; 

    for (int i = 0; i < sizeN; i++){
        resultArray[i] = sortedArray1[i];
    }

    for (int i = 0; i < sizeN; i++){
        int index = count;
        for (int j = 0; j < count; j++){
            if(sortedArray2[i] < resultArray[j]){
                index = j;
                j = count;
            }
        }

        //Move elements by one
        for (int k = 0; k < count - index; k++){
            resultArray[count- k] = resultArray[count - 1 - k];
        }
        resultArray[index] = sortedArray2[i];
        count++;
    }
    
    return resultArray;
}

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

// Driver code 
int main() 
{ 
    std::srand(std::time(0));
    int sizeN;
    int firstRange = 100;
    int secondRange = 100;
    int firstStart = 0;
    int secondStart = 100;
    int firstRepeatNumber = 1;
    int secondRepeatNumber = 400;

    int trialSize = 50;
    int trialStartIndex = 500;
    int trialInterval = 500;
    int allTrials[trialSize];

    bool testFirstAlgorithm = true;
    bool testSecondAlgorithm = true;

    cout<<"All the input size values"<<endl;
    for (int i = 0; i < trialSize ; i++)
    {
        allTrials[i] = trialStartIndex + i * trialInterval;
        cout<< allTrials[i]<<endl;
    }
    cout<<"*********"<<endl;


    if(testFirstAlgorithm){
        for (int i = 0; i < trialSize; i++)
        {
        sizeN = allTrials[i];
        int arr1[sizeN];
        int arr2[sizeN];

        for (int i = 0; i < sizeN; i++)
        {
            arr1[i] = (std::rand() * std::rand()) % firstRange + firstStart;
            arr2[i] = (std::rand() * std::rand()) % secondRange + secondStart;
        }

        sort(arr1, arr1 + sizeN);
        sort(arr2, arr2 + sizeN);
        //Store the starting time
        double duration;
        clock_t startTime = clock();
        //Code block
        for (int i = 0; i < firstRepeatNumber; i++)
        {
            mergeFirstAlgorithm(arr1, arr2, sizeN);
        }
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << duration/firstRepeatNumber << endl;
        }
    }

    cout<<"*********"<<endl;

    if(testSecondAlgorithm){
        for (int i = 0; i < trialSize; i++){
        sizeN = allTrials[i];
        int arr1[sizeN];
        int arr2[sizeN];

        for (int i = 0; i < sizeN; i++)
        {
            arr1[i] = (std::rand() * std::rand()) % firstRange + firstStart;
            arr2[i] = (std::rand() * std::rand()) % secondRange + secondStart;
        }

        sort(arr1, arr1 + sizeN);
        sort(arr2, arr2 + sizeN);
        //Store the starting time
        double duration;
        clock_t startTime = clock();
        //Code block
        for (int i = 0; i < secondRepeatNumber; i++)
        {
            mergeSecondAlgorithm(arr1, arr2, sizeN);
        }
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << duration/secondRepeatNumber <<  endl;
        }
    } 
}