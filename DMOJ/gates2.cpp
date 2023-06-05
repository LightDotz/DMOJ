/*
#include <set>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::set<int, std::greater<int>> gates;
std::vector<int> possibleDocks;

int main()
{
	int gateNum, planeNum;
	std::cin >> gateNum;
	std::cin >> planeNum;

	int landedPlanes = 0;

	for (int i = 1; i <= gateNum; i++)
	{
		gates.insert(i);
	}
	
	bool stop = false;

	for (int i = 0; i < planeNum; i++)
	{
		int possibleDock;
		std::cin >> possibleDock;
		
		if (stop)
		{
			continue;
		}

		auto it = gates.lower_bound(possibleDock);
		
		if (it == gates.end())
		{
			stop = true;
			continue;
		}
		
		gates.erase(it);

		landedPlanes++;
	}

	std::cout << landedPlanes << std::endl;
	
	return 0;
}
*/