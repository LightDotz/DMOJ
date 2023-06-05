/*
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <queue>

int bfs(std::vector<std::pair<int, int>> map[21][21], std::pair<int, int> end, bool star[21][21])
{
	if (end == std::make_pair(0, 0))
	{
		return 1;
	}
	
	bool visited[21][21] = { {false} };
	std::pair<int, int> previous[21][21];

	std::queue<std::pair<int, int>> q;

	q.push(std::make_pair(0, 0));
	visited[0][0] = true;

	bool found = false;

	while (!q.empty() && !found)
	{
		std::pair<int, int> pos = q.front();
		q.pop();

		for (auto it = map[pos.first][pos.second].begin(); it != map[pos.first][pos.second].end(); ++it)
		{
			std::pair<int, int> newPos = *it;

			if (!visited[newPos.first][newPos.second] && !star[newPos.first][newPos.second])
			{
				visited[newPos.first][newPos.second] = true;
				previous[newPos.first][newPos.second] = pos;
				q.push(newPos);

				if (newPos == end)
				{
					found = true;
					break;
				}
			}
		}
	}

	if (!found)
	{
		return -1;
	}

	int length = 1;
	std::pair<int, int> current = end;

	while (true)
	{
		current = previous[current.first][current.second];
		length++;

		if (current == std::make_pair(0, 0))
		{
			break;
		}
	}

	return length;
}

int main()
{
	int cases;
	std::cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		std::vector<std::pair<int, int>> map[21][21];
		bool star[21][21] = { {false} };

		int rows, columns;

		std::cin >> rows;
		std::cin >> columns;

		for (int row = 0; row < rows; row++)
		{
			std::string directions;
			std::cin >> directions;

			for (int column = 0; column < columns; column++)
			{
				char dir = directions.at(column);

				if (dir == '+' || dir == '|')
				{
					if (row + 1 < rows)
					{
						map[row][column].push_back(std::make_pair(row + 1, column));
					}
					
					if (row - 1 >= 0)
					{
						map[row][column].push_back(std::make_pair(row - 1, column));
					}
				}

				if (dir == '+' || dir == '-')
				{
					if (column + 1 < columns)
					{
						map[row][column].push_back(std::make_pair(row, column + 1));
					}

					if (column - 1 >= 0)
					{
						map[row][column].push_back(std::make_pair(row, column - 1));
					}
				}

				if (dir == '*')
				{
					star[row][column] = true;
				}
			}
		}

		std::cout << bfs(map, std::make_pair(rows - 1, columns - 1), star) << std::endl;
	}
	
	return 0;
}
*/