/*
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> intPair;

int main()
{
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	std::unordered_map<char, intPair> moves = {
		{'L', {0, -1}},
		{'R', {0, 1}},
		{'U', {-1, 0}},
		{'D', {1, 0}}
	};

	int rows, columns;
	// potentailly use normal vector / create unordred maps
	std::vector<std::vector<char>> map;
	std::vector<std::vector<int>> steps;
	std::vector<std::vector<bool>> invalid, visited;

	std::vector<intPair> empty;

	intPair start;
	std::vector<intPair> cameras;

	std::cin >> rows >> columns;

	map.resize(rows);
	invalid.resize(rows);
	visited.resize(rows);
	steps.resize(rows);

	for (int i = 0; i < rows; i++)
	{
		std::string line;
		std::cin >> line;

		map[i].resize(columns);
		invalid[i].resize(columns);
		visited[i].resize(columns);
		steps[i].resize(columns);

		std::fill(steps[i].begin(), steps[i].end(), -1);

		for (int j = 0; j < columns; j++)
		{
			char c = line.at(j);

			map[i][j] = c;

			if (c == 'S')
			{
				start = std::make_pair(i, j);
			}
			else if (c == 'C')
			{
				cameras.push_back(std::make_pair(i, j));
			}
			else if (c == '.')
			{
				empty.push_back(std::make_pair(i, j));
			}
		}
	}

	// calculate invalid squares
	for (auto it = cameras.begin(); it != cameras.end(); it++)
	{
		intPair pos = *it;

		invalid[pos.first][pos.second] = true;

		// right
		for (int i = pos.second; i < columns; i++)
		{
			if (map[pos.first][i] == '.' || map[pos.first][i] == 'S')
				invalid[pos.first][i] = true;
			else if (map[pos.first][i] == 'W')
				break;
		}

		//left
		for (int i = pos.second; i >= 0; i--)
		{
			if (map[pos.first][i] == '.' || map[pos.first][i] == 'S')
				invalid[pos.first][i] = true;
			else if (map[pos.first][i] == 'W')
				break;
		}

		//up
		for (int i = pos.first; i >= 0; i--)
		{
			if (map[i][pos.second] == '.' || map[i][pos.second] == 'S')
				invalid[i][pos.second] = true;
			else if (map[i][pos.second] == 'W')
				break;
		}

		//down
		for (int i = pos.first; i < rows; i++)
		{
			if (map[i][pos.second] == '.' || map[i][pos.second] == 'S')
				invalid[i][pos.second] = true;
			else if (map[i][pos.second] == 'W')
				break;
		}
	}

	if (invalid[start.first][start.second]) // spawn beside camera
	{
		for (auto it = empty.begin(); it != empty.end(); it++)
		{
			std::cout << -1 << std::endl;
		}

		return 0;
	}

	std::queue<intPair> q;
	visited[start.first][start.second] = true;
	steps[start.first][start.second] = 0;
	q.push(start);

	while (!q.empty())
	{
		intPair pos = q.front();
		q.pop();

		for (auto it = moves.begin(); it != moves.end(); it++)
		{
			intPair move = it->second;
			intPair newPos = std::make_pair(pos.first + move.first, pos.second + move.second);

			if (newPos.first > rows - 1 || newPos.first < 0 || newPos.second > columns - 1 || newPos.second < 0)
				continue;

			if (invalid[newPos.first][newPos.second] == true || visited[newPos.first][newPos.second] == true)
				continue;

			char c = map[newPos.first][newPos.second];

			if (c == '.')
			{
				visited[newPos.first][newPos.second] = true;
				steps[newPos.first][newPos.second] = steps[pos.first][pos.second] + 1;
				q.push(newPos);
			}
			else if (c == 'L' || c == 'R' || c == 'U' || c == 'D')
			{
				visited[newPos.first][newPos.second] = true;
				newPos = std::make_pair(newPos.first + moves[c].first, newPos.second + moves[c].second); // conveyer auto move

				char nextC = map[newPos.first][newPos.second];
				if (nextC == 'W')
					continue;

				if (invalid[newPos.first][newPos.second] == true || visited[newPos.first][newPos.second] == true)
					continue;
				visited[newPos.first][newPos.second] = true;

				bool vis = false;

				while (nextC != '.' && nextC != 'W')
				{
					newPos = std::make_pair(newPos.first + moves[nextC].first, newPos.second + moves[nextC].second); // conveyer auto move
					if (visited[newPos.first][newPos.second] == true || invalid[newPos.first][newPos.second] == true)
					{
						vis = true;
						break;
					}
					visited[newPos.first][newPos.second] = true;
					nextC = map[newPos.first][newPos.second];
				}

				if (nextC == 'W' || vis)
					continue;

				steps[newPos.first][newPos.second] = steps[pos.first][pos.second] + 1;

				q.push(newPos);
			}
		}
	}

	for (auto it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << steps[it->first][it->second] << std::endl;
	}

	return 0;
}
*/