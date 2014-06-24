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
				int CostTo, int CostFrom)
{

}

void RemoveRoads(BitLandTowns *Towns, int n)
{
	for (int i = 0; i < n; ++i) {

	}
}

void PrintToll(BitLandTowns *Towns, int k)
{
	int Toll = 0;

	std::cout << Toll << std::endl;
}

int main(int argc, char *argv[])
{
	BitLandTowns *Towns;
	int n, m;

	std::cin >> n >> m;

	Towns = new BitLandTowns[n];

	for (int i = 0; i < m; ++i) {
		int TownFrom, TownTo, CostTo, CostFrom;

		std::cin >> TownFrom >> TownTo
				>> CostTo >> CostFrom;

		AddRoads(Towns, TownFrom-1, TownTo-1, CostTo, CostFrom);
	}

	int t, k;

	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> k;
		PrintToll(Towns, k);
	}

	RemoveRoads(Towns, n);
	delete [] Towns;

    return 0;
}

