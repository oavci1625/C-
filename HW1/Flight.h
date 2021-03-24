#ifndef FLIGHT_H
#define FLIGHT_H
#include "Reservation.h"

class Flight {
public:
    Reservation* resArr;
    int resNo;
    int flightNo;
    int rowNo;
    int seatNo;
    char takenSeatColumn;
    int takenSeatRow;
    Flight();
    ~Flight();
    int addReservation( const int numPassengers, const int *seatRow, const char *seatCol, int resCode);
    int removeReservation( const int resCode );
    int getEmptySeatNo();
};

#endif