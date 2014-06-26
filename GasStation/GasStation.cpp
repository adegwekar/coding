#include "GasStation.hpp"
#include <sstream>
#include <stdlib.h>

using namespace std;

string GasStation(vector<string> strArr)
{
  ostringstream convert;
  int CurrentGasLevel = 0;
  int CurrentGasStation = 0;
  int NumGasStations = atoi(strArr[0].c_str());
  int GasStationsVisited = 0;
  int StartingGasStation = 1;
  
  if (strArr[0] < "2")
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
    } else {
      if (GasStationsVisited >= CurrentGasStation &&
          StartingGasStation-1 > CurrentGasStation) {
        return "impossible";
      }
      GasStationsVisited = 0;
      CurrentGasLevel = 0;
      StartingGasStation = CurrentGasStation+1+1;
    }
    ++CurrentGasStation;
    
    if (GasStationsVisited == NumGasStations) {
      break;
    }
    
    // Reached the end, should we circle back?
    if (CurrentGasStation >= NumGasStations) {
      if (GasStationsVisited == 0) {
        return "impossible";
      } else {
        //Not done with all gas stations
        CurrentGasStation = 0;
      }
    }
  }

  convert << StartingGasStation;
  return convert.str();      
}
