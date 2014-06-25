/* Using the C++ language, have the function GasStation(strArr) take strArr
which will be an an array consisting of the following elements: N which will
be the number of gas stations in a circular route and each subsequent element
will be the string g:c where g is the amount of gas in gallons at that gas
station and c will be the amount of gallons of gas needed to get to the
following gas station. For example strArr may be:
["4","3:1","2:2","1:2","0:1"]. Your goal is to return the index of the
starting gas station that will allow you to travel around the whole route
once, otherwise return the string impossible. For the example above, there are
4 gas stations, and your program should return the string 1 because starting
at station 1 you receive 3 gallons of gas and spend 1 getting to the next
station. Then you have 2 gallons + 2 more at the next station and you spend 2
so you have 2 gallons when you get to the 3rd station. You then have 3 but you
spend 2 getting to the final station, and at the final station you receive 0
gallons and you spend your final gallon getting to your starting point.
Starting at any other gas station would make getting around the route
impossible, so the answer is 1. If there are multiple gas stations that are
possible to start at, return the smallest index (of the gas station). N will
be >= 2.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

string GasStation(string strArr[])
{
  ostringstream convert;
  int CurrentGasLevel = 0;
  int CurrentGasStation = 0;
  int NumGasStations = atoi(strArr[0].c_str());
  int GasStationsVisited = 0;
  
  if (strArr[0] <= "2")
    return "impossible";

  while (GasStationsVisited < NumGasStations) {
    int pos = strArr[CurrentGasStation+1].find(":");
    string token = strArr[CurrentGasStation+1].substr(0, pos);
    int AvailableGas = atoi(token.c_str());
    int GasNeeded = atoi(strArr[CurrentGasStation+1].substr(pos+1,strArr[CurrentGasStation+1].size()).c_str());
    
    if (CurrentGasLevel+AvailableGas >= GasNeeded) {
      CurrentGasLevel += AvailableGas;
      CurrentGasLevel -= GasNeeded;
      ++GasStationsVisited;
    }
    ++CurrentGasStation;
    
    if (GasStationsVisited == NumGasStations) {
      break;
    }
    
    // Reached the end, should we circle back?
    if (CurrentGasStation >= NumGasStations) {
      if (GasStationsVisited < NumGasStations) {
        return "impossible";
      } else {
        //Not done with all gas stations
        CurrentGasStation = 0;
      }
    }
  }

  convert << CurrentGasStation;
  return convert.str();      
}

int main()
{   
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. 
     To see how to enter arrays as arguments in C++ scroll down */
     
  string A[] = gets(stdin);
  cout << GasStation(A);
  return 0;
} 
