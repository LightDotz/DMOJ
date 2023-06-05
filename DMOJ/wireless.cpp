/*
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
	// [bitrate] = { {[x] = range} }
	std::unordered_map<int, std::vector<std::unordered_map<int, std::pair<int, int>>>> network;
	std::vector<std::pair<int, int>> coffeeShops;

	int M, N, K;
	std::cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x, y, R, B;
		std::cin >> x >> y >> R >> B;

		int newIndex = network[B].capacity();
		network[B].resize(newIndex + 1);

		for (int xInc = 0; xInc <= R; xInc++)
		{
			int newX = x + xInc;
			int newY = sqrt((R * R) - (xInc * xInc));

			int yFloor = (y - newY < 1) ? 1 : y - newY;
			int yCeil = (y + newY > N) ? N : y + newY;

			network[B][newIndex][newX] = std::make_pair(yFloor, yCeil);

			int newXNeg;

			if (xInc != 0 && x - xInc > 0)
			{
				int newXNeg = x - xInc;
				network[B][newIndex][newXNeg] = std::make_pair(y - newY, y + newY);
			}

			for (int j = yFloor; j <= yCeil; j++)
			{
				if (std::find(coffeeShops.begin(), coffeeShops.end(), std::make_pair(newX, j)) == coffeeShops.end())
				{
					if (xInc != 0 && x - xInc > 0)
						coffeeShops.push_back(std::make_pair(newXNeg, j));

					coffeeShops.push_back(std::make_pair(newX, j));
				}
			}
		}
	}

	int maxBitrate = 0;
	int amtMax = 0;

	for (auto shop = coffeeShops.begin(); shop != coffeeShops.end(); shop++)
	{
		int x = (*shop).first;
		int y = (*shop).second;

		int bitrate = 0;

		for (auto it = network.begin(); it != network.end(); it++)
		{
			for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
			{
				if (y >= (*it2)[x].first && y <= (*it2)[x].second)
				{
					bitrate += it->first;
				}
			}
		}

		if (bitrate > maxBitrate)
		{
			maxBitrate = bitrate;
			amtMax = 1;
		}
		else if (bitrate == maxBitrate)
		{
			amtMax++;
		}
	}

	std::cout << maxBitrate << std::endl;
	std::cout << amtMax << std::endl;

	return 0;
}
*/