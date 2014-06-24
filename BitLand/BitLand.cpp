#include "BitLand.hpp"

void AddRoads(BitLandTowns *Towns, int TownFrom, int TownTo,
				int CostTo, int CostFrom)
{
	if (!Towns[TownFrom].Cheapest) {
		Towns[TownFrom].Cheapest = new RoadCost;
		Towns[TownFrom].Cheapest->Town = TownTo;
		Towns[TownFrom].Cheapest->Cost = CostTo;
		Towns[TownFrom].Cheapest->next = 0;

		Towns[TownFrom].Costliest = Towns[TownFrom].Cheapest;
	} else {
		RoadCost *temp = new RoadCost;
		temp->Town = TownTo;
		temp->Cost = CostTo;
		if (CostTo <= Towns[TownFrom].Cheapest->Cost) {
			// Insert as Cheapest
			temp->next = Towns[TownFrom].Cheapest;
			Towns[TownFrom].Cheapest = temp;
		} else if (CostTo >= Towns[TownFrom].Costliest->Cost) {
			//Insert as Costliest
			temp->next = 0;
			Towns[TownFrom].Costliest->next = temp;
			Towns[TownFrom].Costliest = Towns[TownFrom].Costliest->next;
		} else {
			//Insert anywhere after Cheapest, doesn't matter where
			temp->next = Towns[TownFrom].Cheapest->next;
			Towns[TownFrom].Cheapest->next = temp;
		}
	}

	if (!Towns[TownTo].Cheapest) {
		Towns[TownTo].Cheapest = new RoadCost;
		Towns[TownTo].Cheapest->Town = TownFrom;
		Towns[TownTo].Cheapest->Cost = CostFrom;
		Towns[TownTo].Cheapest->next = 0;

		Towns[TownTo].Costliest = Towns[TownTo].Cheapest;
	} else {
		RoadCost *temp = new RoadCost;
		temp->Town = TownFrom;
		temp->Cost = CostFrom;
		if (CostFrom <= Towns[TownTo].Cheapest->Cost) {
			// Insert as Cheapest
			temp->next = Towns[TownTo].Cheapest;
			Towns[TownTo].Cheapest = temp;
		} else if (CostFrom >= Towns[TownTo].Costliest->Cost) {
			//Insert as Costliest
			temp->next = 0;
			Towns[TownTo].Costliest->next = temp;
			Towns[TownTo].Costliest = Towns[TownTo].Costliest->next;
		} else {
			//Insert anywhere after Cheapest, doesn't matter where
			temp->next = Towns[TownTo].Cheapest->next;
			Towns[TownTo].Cheapest->next = temp;
		}
	}
}

void RemoveRoads(BitLandTowns *Towns, int n)
{
	for (int i = 0; i < n; ++i) {

	}
}

static void AdjustTolls(BitLandTowns *Towns, int CurrentTown)
{
}

void PrintToll(BitLandTowns *Towns, int k)
{
	int Toll = 0;
	int CurrentTown = 0; //First road is always from town A

	for (int CurrentRoad = 0; CurrentRoad < k; ++CurrentRoad) {
		Toll = Towns[CurrentTown].Cheapest->Cost;
		CurrentTown = Towns[CurrentTown].Cheapest->Town; //Reached next town

		//Toll Trolls, do your job
		AdjustTolls(Towns, 0);
	}

	std::cout << Toll << std::endl;
}
