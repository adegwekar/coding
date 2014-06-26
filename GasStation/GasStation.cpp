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

  // N >= 2
  if (strArr[0] < "2")
    return "impossible";

  while (1) {
    int pos = strArr[CurrentGasStation+1].find(":");
    string token = strArr[CurrentGasStation+1].substr(0, pos);
    int AvailableGas = atoi(token.c_str());
    int GasNeeded =
      atoi(strArr[CurrentGasStation+1].substr(pos+1,
                                  strArr[CurrentGasStation+1].size()).c_str());
    
    if (CurrentGasLevel+AvailableGas >= GasNeeded) {
      // Enough gas to proceed
      CurrentGasLevel += AvailableGas; // Filled up gas
      CurrentGasLevel -= GasNeeded; // Used up gas
      ++GasStationsVisited;
    } else {
      // Not enough gas to proceed, but we can always try the next stations
      // Unless...
      // We have already circled through all stations once, then return impossible
      if (GasStationsVisited >= CurrentGasStation &&
          StartingGasStation-1 > CurrentGasStation) {
        return "impossible";
      }
      GasStationsVisited = 0;
      CurrentGasLevel = 0;
      // Try the next station (extra +1 to align with array indices)
      StartingGasStation = CurrentGasStation+1+1;
    }
    ++CurrentGasStation; // Check next station
    
    if (GasStationsVisited == NumGasStations) {
      break; // Done
    }
    
    // Reached the end, should we circle back?
    if (CurrentGasStation >= NumGasStations) {
      if (GasStationsVisited == 0) {
        // No gas stations were able to satisfy the need
        return "impossible";
      } else {
        //Start back at the beginning, maybe we might have enough gas to circle
        CurrentGasStation = 0;
      }
    }
  }

  convert << StartingGasStation;
  return convert.str();      
}
