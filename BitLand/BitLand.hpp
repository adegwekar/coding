#ifndef __BITLAND_HPP__
#define __BITLAND_HPP__

#include <iostream>

struct RoadCost {
	int Town;
	int Cost;
	RoadCost *next;
};

struct BitLandTowns {
	RoadCost *Cheapest;
	RoadCost *Costliest;
};

void AddRoads(BitLandTowns *Towns, int TownFrom, int TownTo,
				int CostTo, int CostFrom);

void RemoveRoads(BitLandTowns *Towns, int n);

int PrintToll(BitLandTowns *Towns, int k);

#endif