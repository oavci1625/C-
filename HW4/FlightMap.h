//Onuralp Avci
//21902364

#include <iostream>
using namespace std;

class FlightMap {
public:
    FlightMap( const string cityFile, const string flightFile );
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity ) const;
    void findLeastCostFlight( const string deptCity, const string destCity ) const;
    void runFlightRequests( const string requestFile ) const;
    int findIndexOfCity(string city) const;

    //variables
    string* cityArray;
    bool* visitedArray;
    int* flightIdArray;
    int** flightMap;
    int cityNo;
};