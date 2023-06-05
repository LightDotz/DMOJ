/*
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <string>

int main()
{
	int segments;
	std::cin >> segments;

	int* topNumbers = new int[segments];
	int* bottomNumbers = new int[segments];

	for (int i = 0; i < segments; i++)
	{
		std::cin >> topNumbers[i];
		bottomNumbers[i] = i + 1;
	}

	int heights[3001][3001];
	std::vector<std::pair<int, int>> lines; // i, i + 1
	int highest = 0;

	for (int bottomIndex = 0; bottomIndex < segments; bottomIndex++)
	{
		int topIndex = -1;
		for (int j = 0; j < segments; j++)
		{
			if (topNumbers[j] == bottomNumbers[bottomIndex])
			{
				topIndex = j;
				break;
			}
		}

		if (topIndex == -1)
		{
			std::cout << -1 << std::endl;
			return 0;
		}

		int currHeight = 0;

		if (bottomIndex < topIndex)
		{
			for (int j = bottomIndex; j < topIndex; j++)
			{
				auto pair = std::make_pair(j, j + 1);
				auto it = std::find(lines.begin(), lines.end(), pair);

				if (it == lines.end() || heights[pair.first][pair.second] < currHeight) // not found
				{
					lines.push_back(pair);
					heights[pair.first][pair.second] = currHeight;
					currHeight++;
				}
				else
				{
					currHeight = heights[pair.first][pair.second];
				}

				if (currHeight > highest)
					highest = currHeight;
			}
		}
		else if (bottomIndex > topIndex)
		{
			for (int j = bottomIndex; j > topIndex; j--)
			{
				auto pair = std::make_pair(j - 1, j);
				auto it = std::find(lines.begin(), lines.end(), pair);

				if (it == lines.end() || heights[pair.first][pair.second] < currHeight) // not found
				{
					lines.push_back(pair);
					heights[pair.first][pair.second] = currHeight;
					currHeight++;
				}
				else
				{
					currHeight = heights[pair.first][pair.second];
				}

				if (currHeight > highest)
					highest = currHeight;
			}
		}
	}

	std::cout << lines.size() << std::endl;
	
	delete[] topNumbers;
	delete[] bottomNumbers;

	return 0;
}
*/