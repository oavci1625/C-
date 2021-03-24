#include "FlightMap.h"

int main(){
    FlightMap map("cityFile", "flightFile");
    map.displayAllCities();
    return 0;

}