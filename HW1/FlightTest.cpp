#include <iostream>
using namespace std;
#include "Flight.h"

int main() {
    int rowRes1[4] = {3, 3, 1, 1};
    char colRes1[4] = {'A', 'B', 'B', 'C'};
    int rowRes2[1] = {5};
    char colRes2[1] = {'A'};
    int rowRes3[1] = {6};
    char colRes3[1] = {'A'};
    Flight flight;

    flight.addReservation( 4, rowRes1, colRes1, 1);
    flight.addReservation( 1, rowRes2, colRes2, 2);
    flight.addReservation( 1, rowRes3, colRes3, 3);
    
    cout<<flight.resArr[1].seatRow[0]<< flight.resArr[0].seatCol[0]<<endl;
    Reservation* a = &(flight.resArr[0]);
    Reservation* b = &(flight.resArr[1]);
    Reservation* c = &(flight.resArr[2]);
    cout<< (*a).resCode <<endl;
    cout<< b->resCode <<endl;
    cout<< c->resCode <<endl;

    cout<< a <<endl;
    cout<< b <<endl;
    cout<< c <<endl;

}