#include "ReservationSystem.h"
#include <iostream>
using namespace std;

ReservationSystem::ReservationSystem(){
    flightArr = 0;
    flNo = 0;
    uniqueResCode = 1;
};
ReservationSystem::~ReservationSystem(){};

void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo ){
    if( rowNo > 0 && seatNo > 0){
        if( flNo == 0){
            flightArr = new Flight[1];
            flightArr[0].Flight::flightNo = flightNo;
            flightArr[0].Flight::rowNo = rowNo;
            flightArr[0].Flight::seatNo = seatNo;
            flNo ++;
            cout<<"Flight "<<flightNo<< " has been added"<<endl;
        }
        else{
            //Check if flight number exist
            bool flightNoExist = false;
            for (int i = 0; i < flNo; i++)
            {
                if(flightArr[i].flightNo == flightNo){
                    flightNoExist = true;
                    break;
                }
            }
            
            if(!flightNoExist){
                Flight* temp = new Flight[flNo + 1];
                for(int i = 0; i < flNo; i++){
                    temp[i] = flightArr[i];
                }
                temp[flNo].flightNo = flightNo;
                temp[flNo].rowNo = rowNo;
                temp[flNo].seatNo = seatNo;

                delete[] flightArr;
                flightArr = temp;
                flNo++;
                cout<<"Flight "<<flightNo<< " has been added"<<endl;
            }
            else{
                cout<<"Flight "<<flightNo <<" already exists"<<endl;
            }
        }
    }
    else{
        cout<<"Enter positive seat and row number!"<<endl;
    }
};

void ReservationSystem::cancelFlight( const int flightNo ){
    int index = -1;
    for (int i = 0; i < flNo; i++)
    {
        if (flightArr[i].flightNo == flightNo)
        {
            index = i;
            break;
        }
    }

    if( index == -1){
        cout<<"Flight "<<flightNo<<" does not exist"<<endl;
    }
    else{

        //Now another flight array will be created without this flight
        Flight* temp = new Flight[flNo - 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = flightArr[i];
        }
        for (int i = 0; i < flNo-index-1 ; i++)
        {
           temp[index+i] = flightArr[index+1+i];
        }
        
        //Now before deleting flightArr, we will delete all reservation arrays in them
        for (int i = 0; i < flNo; i++)
        {
            delete[] flightArr[i].resArr;
        }
        
        //Now we can delete old flight array
        delete[] flightArr;
        flightArr = temp;
        flNo--;
        cout<<"Flight "<< flightNo <<" and all of its reservations are canceled"<<endl;
    }
};

void ReservationSystem::showAllFlights(){
    cout<<endl;
    if(flNo == 0){
        cout<<"No flight exists"<<endl;
    }
    else{
        cout<<"Flights currently operated:"<<endl;
        for (int i = 0; i < flNo; i++)
        {
            cout<<"Flight "<< flightArr[i].flightNo<< " (" << flightArr[i].getEmptySeatNo()<< " available seats)"<<endl;
        }   
    }
    cout<<endl;
};

void ReservationSystem::showFlight( const int flightNo ){
    cout<<endl;
    char columnNames[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

    int index = -1;
    for (int i = 0; i < flNo; i++)
    {
        if (flightArr[i].flightNo == flightNo)
        {
            index = i;
            break;
        }
    }
    if(index == -1){
        cout<<"Flight "<<flightNo<<" does not exist"<<endl;
    }
    else{
        cout<<"Flight "<< flightNo <<" has "<< flightArr[index].getEmptySeatNo()<<" available seats"<<endl;
        //Printing column names
        cout<<"  ";
        for (int i = 0; i < flightArr[index].seatNo; i++)
        {
            cout<<columnNames[i]<< " ";
        }
        cout<<endl; //end of colum names

        int totalSeatNumber = flightArr[index].rowNo * flightArr[index].seatNo;
        bool allSeats[totalSeatNumber];
        for (int i = 0; i < totalSeatNumber; i++)
        {
            allSeats[i] = false;
        }
        
        for (int i = 0; i < flightArr[index].resNo; i++)
        {
            for (int j = 0; j < flightArr[index].resArr[i].numPassengers; j++)
            {
                int row = flightArr[index].resArr[i].seatRow[j];
                char column = flightArr[index].resArr[i].seatCol[j];

                //calculate index of the reserved seat
                int columnIndex = -1;
                for (int k = 0; k < 12; k++)
                {
                    if( column == columnNames[k]){
                        columnIndex = k;
                        break;
                    }
                }//end of columnd index
                int position = flightArr[index].seatNo * ( row - 1) + columnIndex;
                allSeats[position] = true;
            }
        }

        int seatIndex = 0;
        for (int i = 0; i < flightArr[index].rowNo; i++)
        {
            cout<<i+1<<" ";
            for (int j = 0; j < flightArr[index].seatNo; j++)
            {
                if (allSeats[seatIndex] == false)
                {
                    cout<< "0 ";
                }
                else{
                    cout<<"X ";
                }
                seatIndex++;
            }cout<<endl;
        }        
    }
    cout<<endl;
};

int ReservationSystem::makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol ){
    int index = -1;
    for (int i = 0; i < flNo; i++)
    {
        if (flightArr[i].flightNo == flightNo)
        {
            index = i;
            break;
        }
    }
    if( index == -1){
        cout<<"There is no flight with number "<<flightNo<<endl;
        return -1;
    }
    else{
        int resCode = uniqueResCode;
        int result = flightArr[index].addReservation( numPassengers, seatRow, seatCol, resCode);
        if( result == 1){
            uniqueResCode++;
            return resCode;
        }
        else{
            cout<<flightArr[index].takenSeatRow<<flightArr[index].takenSeatColumn<< " is not available"<<endl<<endl;
            return -1;
        }
    }
};
void ReservationSystem::cancelReservation( const int resCode ){
    int result = -1;

    for (int i = 0; i < flNo; i++)
    {
        for (int j = 0; j < flightArr[i].resNo; j++)
        {
            if (flightArr[i].resArr[j].resCode == resCode)
            {
                int no = flightArr[i].resArr[j].numPassengers;
                int row[no];
                char col[no];
                for (int k = 0; k < no; k++)
                {
                    row[k] = flightArr[i].resArr[j].seatRow[k];
                    col[k] = flightArr[i].resArr[j].seatCol[k];
                }
                int flightNo = flightArr[i].flightNo;

                result = flightArr[i].removeReservation(resCode);
                if(result == 1){
                    cout<<"Reservation for the seats ";
                    for (int i = 0; i < no; i++)
                    {
                        cout<< row[i]<<col[i]<<" ";
                    }
                    
                    cout<<"is canceled in Flight "<<flightNo<<endl;
                    
                }
                else{
                    cout<<"Error! Reservation with code "<<resCode<<" is found but could not be canceled! "<<endl;
                }
                return;
            }
        }
    }
    cout<<"No reservations are found under code "<<resCode<<endl;
    
};
void ReservationSystem::showReservation( const int resCode ){
    const int* seatRow;
    const char* seatCol;
    int passengerNo;
    int flightNo;
    int result = -1;
    for (int i = 0; i < flNo; i++)
    {
        for (int j = 0; j < flightArr[i].resNo; j++)
        {
            if (flightArr[i].resArr[j].resCode == resCode)
            {
                seatRow = flightArr[i].resArr[j].seatRow;
                seatCol = flightArr[i].resArr[j].seatCol;
                passengerNo = flightArr[i].resArr[j].numPassengers;
                flightNo = flightArr[i].flightNo;
                result = 1;
                break;
            }
        }
    }
    if(result == -1){
        cout<<"No reservations under Code "<<resCode<<endl;
    }
    else{
        cout<<"Reservation uncer code "<<resCode<< " in Flight "<<flightNo<<": ";
        for (int i = 0; i < passengerNo; i++){
            cout<< *(seatRow+i)<<*(seatCol+i)<<" ";
        }
        cout<<endl;
    }
};
