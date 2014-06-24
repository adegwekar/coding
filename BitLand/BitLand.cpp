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
			Towns[TownFrom].Costliest = temp;
		} else {
			//Insert after Cheapest in sorted fashion
			RoadCost *iter = Towns[TownFrom].Cheapest;

			while (iter->next) {
				if (CostTo <= iter->next->Cost) {
					temp->next = iter->next;
					iter->next = temp;
					break;
				}
				iter = iter->next;
			}
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
			Towns[TownTo].Costliest = temp;
		} else {
			//Insert after Cheapest in sorted fashion
			RoadCost *iter = Towns[TownFrom].Cheapest;

			while (iter->next) {
				if (CostTo <= iter->next->Cost) {
					temp->next = iter->next;
					iter->next = temp;
					break;
				}
				iter = iter->next;
			}
		}
	}
}

void RemoveRoads(BitLandTowns *Towns, int n)
{
	for (int i = 0; i < n; ++i) {
		RoadCost *iter = Towns[i].Cheapest;

		while (iter) {
			RoadCost *temp = iter->next;
			delete iter;
			iter = temp;
		}
		Towns[i].Cheapest = 0;
		Towns[i].Costliest = 0;
	}
}

static void AdjustTolls(BitLandTowns *Towns, int CurrentTown)
{
	if (Towns[CurrentTown].Cheapest == Towns[CurrentTown].Costliest) {
		++Towns[CurrentTown].Cheapest->Cost;
	} else {
		RoadCost *temp = new RoadCost;

		temp->Town = Towns[CurrentTown].Cheapest->Town;
		temp->Cost = Towns[CurrentTown].Costliest->Cost + 1;
		temp->next = 0;

		//delete Towns[CurrentTown].Costliest;
		Towns[CurrentTown].Costliest->next = temp;
		Towns[CurrentTown].Costliest = temp;

		RoadCost *Cheapest = Towns[CurrentTown].Cheapest;
		Towns[CurrentTown].Cheapest = Towns[CurrentTown].Cheapest->next;
		delete Cheapest;
	}
}

int PrintToll(BitLandTowns *Towns, int k)
{
	int Toll = 0;
	static int CurrentTown = 0; //First road is always from town A
	static int CurrentRoad = 0;

	for (; CurrentRoad < k; ++CurrentRoad) {
		Toll = Towns[CurrentTown].Cheapest->Cost;

		int AdjustTown = CurrentTown;
		CurrentTown = Towns[CurrentTown].Cheapest->Town; //Reached next town

		//Toll Trolls, do your job
		AdjustTolls(Towns, AdjustTown);
	}

	return Toll;
}
