/*
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

int main()
{
	int N, M;

	std::cin >> N;
	std::cin >> M;

	std::pair<int, int>* characters = new std::pair<int, int>[N];

	for (int i = 0; i < N; i++)
	{
		int a, b;
		std::cin >> a;
		std::cin >> b;
		
		characters[i] = std::make_pair(a, b);
	}

	int cost = 0;

	for (int i = 0; i < M; i++)
	{
		int min = -1;
		int pos = -1;

		for (int j = 0; j < N; j++)
		{
			if (characters[j].first == -1)
				continue;

			if (min == -1 || characters[j].first * i + characters[j].second < min)
			{
				min = characters[j].first * i + characters[j].second;
				pos = j;
			}
		}

		characters[pos] = std::make_pair(-1, -1);
		cost += min;
	}

	std::cout << cost << std::endl;

	return 0;
}
*/