#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {
public:
    int flightNo;
    int numPassengers;
    const int *seatRow;
    const char *seatCol;
    int resCode;
    
    Reservation();
    ~Reservation();
};

#endif