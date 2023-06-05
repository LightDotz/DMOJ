/*
#include <iostream>
#include <utility>
#include <vector>

int main()
{
	int numPeople;
	std::cin >> numPeople;

	std::vector<std::pair<int, int>> people;
	bool* dead = new bool[numPeople];
	std::fill(dead, dead + numPeople, false);

	for (int i = 0; i < numPeople; i++)
	{
		int before = (i == 0) ? numPeople - 1 : i - 1;
		int after = (i == numPeople - 1) ? 0 : i + 1;
		
		people.push_back(std::make_pair(before, after));
	}

	for (int i = 0; i < numPeople; i++)
	{
		int before = people[i].first;
		int after = people[i].second;
		if (dead[before] == false && dead[after] == false)
		{
			dead[after] = true;
		}
	}

	std::string scenario;
	int alive = 0;

	for (int i = 0; i < numPeople; i++)
	{
		if (dead[i])
		{
			scenario.push_back('_');
		}
		else
		{
			scenario.push_back('M');
			alive++;
		}
	}

	std::cout << alive << "\n" << scenario << std::endl;
	
	delete[] dead;

	return 0;
}
*/