#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include "Flight.h"
class ReservationSystem {
public:
    Flight* flightArr;
    int flNo;
    int uniqueResCode;

    ReservationSystem();
    ~ReservationSystem();
    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers,
    const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );
    // ...
    // you may define additional member functions and data members, if necessary.
};

#endif