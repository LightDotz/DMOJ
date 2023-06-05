/*
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findShortest(int target, std::vector<int> clubs, std::unordered_map<int, std::vector<int>>& memo)
{
	if (target < 0) return std::vector<int>{-1};
	if (target == 0) return std::vector<int>{};
	if (memo.find(target) != memo.end()) return memo[target];

	std::vector<int> currShortest = {-1};

	for (auto it = clubs.begin(); it != clubs.end(); it++)
	{
		int rest = target - *it;
		std::vector<int> bestCombo = findShortest(rest, clubs, memo);

		if (bestCombo.size() > 0 && bestCombo[0] == -1)
			continue;

		bestCombo.push_back(*it);

		if ((currShortest.size() > 0 && currShortest[0] == -1) || bestCombo.size() < currShortest.size())
		{
			currShortest = bestCombo;
		}
	}

	memo[target] = currShortest;
	return memo[target];
}

int main()
{
	int target, clubNum;
	std::vector<int> clubs;

	std::cin >> target;
	std::cin >> clubNum;

	for (int i = 0; i < clubNum; i++)
	{
		int dist;
		std::cin >> dist;

		clubs.push_back(dist);
	}

	std::unordered_map<int, std::vector<int>> memo;

	auto shortest = findShortest(target, clubs, memo);
	
	if (shortest[0] == -1)
	{
		std::cout << "Roberta acknowledges defeat." << std::endl;
	}
	else
	{
		std::cout << "Roberta wins in " << shortest.size() << " strokes." << std::endl;
	}

	return 0;
}
*/