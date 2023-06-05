/*
#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, int>>> memo;

int givePie(int peopleLeft, int pieLeft, int lastGiven, int ways)
{
	if (memo[peopleLeft][pieLeft][lastGiven] != 0)
		return memo[peopleLeft][pieLeft][lastGiven];

	if (peopleLeft == 1 && pieLeft >= 0)
	{
		return ways + 1;
	}
	else if (pieLeft == 0 || peopleLeft == 0)
	{
		return ways;
	}

	int newWays = ways;

	for (int toGive = lastGiven; pieLeft - toGive >= (peopleLeft - 1) * toGive; toGive++)
	{
		newWays += givePie(peopleLeft - 1, pieLeft - toGive, toGive, ways);
	}

	memo[peopleLeft][pieLeft][lastGiven] = newWays;
	return newWays;
}

int main()
{
	int pie, people;
	std::cin >> pie >> people;

	int ways = givePie(people, pie, 1, 0);

	std::cout << ways << std::endl;

	return 0;
}
*/