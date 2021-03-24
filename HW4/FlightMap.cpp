//Onuralp Avci
//21902364

#include "FlightMap.h"
#include "Stack.h"
#include <fstream>

FlightMap::FlightMap( const string cityFile, const string flightFile ){

    ifstream MyFileForCity1(cityFile);
    string line;
    cityNo = 0;
    while (getline (MyFileForCity1, line)) {
        cityNo++;
    }
    MyFileForCity1.close();
    
    string temp1[cityNo];
    cityArray = new string[cityNo];
    visitedArray = new bool[cityNo];

    ifstream MyFileForCity2(cityFile);
    int index = 0;
    while (getline (MyFileForCity2, line)) {
        cityArray[index] = line;
        visitedArray[index] = false;
        index++;
    }
    MyFileForCity2.close();

    flightMap = new int*[cityNo];
    for (int i = 0; i < cityNo; i++)
    {
        flightMap[i] = new int[cityNo]();
    }

    //Declare variables
    string text;
    ifstream inputFile;

    //Open the stream for the input file
    inputFile.open( flightFile.c_str(), ios_base::in );

    int idIndex = 0;
    //Continue until the end of the file
    while ( inputFile.eof() == false ) {
        int depIndex;
        int desIndex;
        int cost;
        //Read until a comma
        getline( inputFile, text, ',' );
        depIndex = findIndexOfCity(text);

        //Read until a comma
        getline( inputFile, text, ',' );
        desIndex = findIndexOfCity(text);

        //Read until a comma
        getline( inputFile, text, ',' );
        idIndex++;

        //Read until a comma
        getline( inputFile, text, '\n' );
        cost = std::stoi(text);

        flightMap[depIndex][desIndex] = cost;
    }
    //Close the input file stream
    inputFile.close();
    
};

FlightMap::~FlightMap(){
    for (int i = 0; i < cityNo; i++)
    {
        int* temp = flightMap[i];
        delete temp;
    }
    delete flightMap;
    delete cityArray;
    delete visitedArray;
};

void FlightMap::displayAllCities()

 const{
    for (int i = 0; i < cityNo; i++)
    {
        cout<<cityArray[i]<<", ";
    }
    cout<<endl;
};


void FlightMap::displayAdjacentCities( const string cityName ) const{
    cout<<cityName<<" -> ";
    int cityIndex = findIndexOfCity(cityName);
    for (int i = 0; i < cityNo; i++)
    {
        if(flightMap[cityIndex][i] != 0){
            cout<<cityArray[i]<<", ";
        }
    }
    cout<<endl;
    
};

void FlightMap::displayFlightMap() const{
    for (int i = 0; i < cityNo; i++)
    {
        displayAdjacentCities(cityArray[i]);
    }
    
};

void FlightMap::findFlights( const string deptCity, const string destCity ) const{
    Stack stack;
    const int depIndex = findIndexOfCity(deptCity);
    const int desIndex = findIndexOfCity(destCity);
    stack.push(depIndex);
    visitedArray[depIndex] = true;

    int top = depIndex;
    bool afterFound = false;
    bool atLeastOneFlightIsFound = false;
    cout<<"Request  is to fly from  "<<cityArray[depIndex]<< " to "<<cityArray[desIndex]<<":"<<endl;
    while( !stack.isEmpty()){
        if( top != desIndex){
            if(!afterFound) visitedArray[desIndex] = false;

            for (int i = 0; i < cityNo + 1; i++)
            {
                if(i == cityNo){
                  stack.pop();
                } //if no available flight
                    

                else if( flightMap[top][i]!= 0 && visitedArray[i] == false){
                    stack.push(i);
                    visitedArray[i] = true;
                    i = cityNo + 10;
                }
            }
            stack.getTop(top);
            afterFound = false;
        }
        else{
            atLeastOneFlightIsFound = true;
            int* resultFlights = stack.arrayOfFlight();
            int size = stack.getSize();
            int totalCost = 0;
            for (int i = 0; i < size - 1; i++)
            {
                cout<<"Flight from "<< cityArray[resultFlights[i]] <<" to "<<cityArray[resultFlights[i+1]] <<"  Cost: "<< flightMap[resultFlights[i]][resultFlights[i+1]]<< " TL"<<endl;
                totalCost += flightMap[resultFlights[i]][resultFlights[i+1]];
            }
            cout<<"Total Cost .......... "<<totalCost<<" TL"<<endl<<endl;
            

            stack.pop();
            stack.getTop(top);
            afterFound = true;
            delete resultFlights;
        }
    }
    if(!atLeastOneFlightIsFound){
        cout<<"Sorry. HPAir does not fly from "<<cityArray[depIndex]<<" to "<<cityArray[desIndex]<<endl;
    }
};

void FlightMap::findLeastCostFlight( const string deptCity, const string destCity ) const{
    Stack stack;
    const int depIndex = findIndexOfCity(deptCity);
    const int desIndex = findIndexOfCity(destCity);
    stack.push(depIndex);
    visitedArray[depIndex] = true;
    int lastTotalCost = 0;

    int top = depIndex;
    bool afterFound = false;
    bool atLeastOneFlightIsFound = false;
    string leastCostString = "";
    while( !stack.isEmpty()){
        if( top != desIndex){
            if(!afterFound) visitedArray[desIndex] = false;

            for (int i = 0; i < cityNo + 1; i++)
            {
                if(i == cityNo){
                  stack.pop();
                } //if no available flight
                    

                else if( flightMap[top][i]!= 0 && visitedArray[i] == false){
                    stack.push(i);
                    visitedArray[i] = true;
                    i = cityNo + 10;
                }
            }
            stack.getTop(top);
            afterFound = false;
        }
        else{
            atLeastOneFlightIsFound = true;
            int* resultFlights = stack.arrayOfFlight();
            int size = stack.getSize();
            int totalCost = 0;
            string way = "" + cityArray[depIndex];
            for (int i = 0; i < size - 1; i++)
            {
                totalCost += flightMap[resultFlights[i]][resultFlights[i+1]];
                way = way + " -> " + cityArray[resultFlights[i + 1]];
            }

            if(lastTotalCost == 0 || totalCost < lastTotalCost){
                leastCostString = "At least cost path from " + cityArray[depIndex] + " to " + cityArray[desIndex] + " is " + way + " and its cost is " + to_string(totalCost) + " TL" + "\n";
                lastTotalCost = totalCost;
            }

            stack.pop();
            stack.getTop(top);
            afterFound = true;
            delete resultFlights;
        }
    }
    if(!atLeastOneFlightIsFound){
        cout<<"Sorry. HPAir does not fly from "<<cityArray[depIndex]<<" to "<<cityArray[desIndex]<<endl;
    }
    else
        cout<<leastCostString;
    
};

int FlightMap::findIndexOfCity(string city) const{
    for (int i = 0; i < cityNo; i++)
    {
        if(cityArray[i] == city)
            return i;
    }
    return -1;

};

int main() {
    FlightMap fm( "cityFile", "flightFile" );
    cout << "The list of the cities that HPAir serves is given below:" << endl;
    fm.displayAllCities();
    cout << endl;
    cout << "The cities adjacent to W are:" << endl;
    fm.displayAdjacentCities( "W" );
    cout << endl;
    cout << "The whole flight map is shown below:" << endl;
    fm.displayFlightMap();
    cout << endl;

    cout << endl;
    fm.findLeastCostFlight( "Y", "Z" );
    cout << endl;
    fm.findLeastCostFlight( "P", "X" );
    cout << endl;
    
return 0;
}