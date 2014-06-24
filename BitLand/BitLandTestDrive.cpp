#include <iostream>
#include "BitLand.hpp"

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
		std::cout << PrintToll(Towns, k) << std::endl;
	}

	RemoveRoads(Towns, n);
	delete [] Towns;

    return 0;
}
