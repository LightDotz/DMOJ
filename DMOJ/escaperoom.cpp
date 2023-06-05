/*
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <algorithm>

int rows, columns;
std::vector<std::pair<int, int>> factors[1000001];

bool bfs(std::pair<int, int> start, std::pair<int, int> end, std::vector<std::vector<int>> room)
{
	std::queue<std::pair<int, int>> next;
	next.push(start);

	std::vector<std::vector<bool>> visited;

	visited.resize(rows);

	for (int i = 0; i < rows; i++)
	{
		visited[i].resize(columns);
		std::fill(visited[i].begin(), visited[i].end(), false);
	}

	visited[start.first][start.second] = true;

	while (!next.empty())
	{
		std::pair<int, int> currPos = next.front();
		next.pop();

		int val = room[currPos.first][currPos.second];

		for (auto it = factors[val].begin(); it != factors[val].end(); ++it)
		{
			auto newPos = *it;

			if (!visited[newPos.first][newPos.second])
			{
				visited[newPos.first][newPos.second] = true;
				next.push(*it);

				if (newPos == end)
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	std::vector<std::vector<int>> room;

	std::cin >> rows;
	std::cin >> columns;

	room.resize(rows);

	for (int i = 0; i < rows; i++)
	{
		room[i].resize(columns);

		for (int j = 0; j < columns; j++)
		{
			int num;
			std::cin >> num;

			room[i][j] = num;

			if (factors[num].size() > 0)
				continue;

			for (int first = 1; first <= rows; first++)
			{
				float fNum = static_cast<float>(num);
				float other = fNum / first;

				if (first > rows || other > columns)
					continue;

				if (other == floor(other))
				{
					factors[num].push_back(std::make_pair(first - 1, other - 1));
				}
			}
		}
	}

	bool possible = bfs(std::make_pair(0, 0), std::make_pair(rows - 1, columns - 1), room);

	if (possible)
	{
		std::cout << "yes" << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}
	return 0;
}
*/