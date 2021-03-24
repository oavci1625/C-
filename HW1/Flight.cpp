#include "Flight.h"
#include <iostream>
using namespace std;

Flight::Flight(){
    resNo = 0;
    resArr = 0;
    takenSeatColumn = 'Z';
    takenSeatRow = 0;
}
Flight::~Flight(){};

int Flight :: addReservation( const int numPassengers, const int *seatRow, const char *seatCol, int resCode){
    if( resNo == 0){
        resArr = new Reservation[1];
        resArr[0].Reservation::flightNo = flightNo;
        resArr[0].Reservation::numPassengers = numPassengers;
        resArr[0].Reservation::seatRow = seatRow;
        resArr[0].Reservation::seatCol = seatCol;
        resArr[0].Reservation::resCode = resCode;
        resNo ++;
        return 1;
    }
    else{
        //Check if seats are empty
        bool seatIsTaken = false;
        for (int i = 0; i < resNo; i++)
        {
            for (int j = 0; j < resArr[i].numPassengers; j++)
            {
                for (int k = 0; k < numPassengers; k++)
                {
                    if(resArr[i].seatRow[j] == seatRow[k] && resArr[i].seatCol[j] == seatCol[k]){
                        seatIsTaken = true;
                        takenSeatRow = seatRow[k];
                        takenSeatColumn = seatCol[k];
                        break;
                    }
                }   
            }
        }
        
        if(!seatIsTaken){
            Reservation* temp = new Reservation[resNo + 1];
            for(int i = 0; i < resNo; i++){
                temp[i] = resArr[i];
            }
            temp[resNo].flightNo = flightNo;
            temp[resNo].numPassengers = numPassengers;
            temp[resNo].seatRow = seatRow;
            temp[resNo].seatCol = seatCol;
            temp[resNo].resCode = resCode;

            delete[] resArr;
            resArr = temp;
            resNo++;
            return 1;
        }
        else{
            return -1;
        }
    }
};

int Flight::removeReservation( const int resCode ){
    int index = -1;
    for (int i = 0; i < resNo; i++)
    {
        if (resArr[i].resCode == resCode)
        {
            index = i;
            break;
        }
    }
    if( index == -1){
        return -1;
    }
    else{
        Reservation* temp = new Reservation[resNo - 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = resArr[i];
        }
        for (int i = 0; i < resNo-index-1 ; i++)
        {
           temp[index+i] = resArr[index+1+i];
        }
        
        delete[] resArr;
        resArr = temp;
        resNo--;
        return 1;
    }
};

int Flight::getEmptySeatNo(){
    int fullSeatNumber = 0;
    for (int i = 0; i < resNo; i++)
    {
        fullSeatNumber = fullSeatNumber + resArr[i].numPassengers;
    }
    return rowNo * seatNo - fullSeatNumber;
};


