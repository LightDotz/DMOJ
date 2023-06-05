/*
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int flooring, rows, columns;
std::vector<std::vector<bool>> grid;
std::vector<std::vector<bool>> checked;
std::vector<std::vector<std::pair<int, int>>> rooms; // realistically i could've just stored the number of tiles in each room instead of the position

const int adj[4][2] = {
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1}
};

void resize(std::vector<std::vector<bool>> &grid)
{
	grid.resize(columns);
	for (int i = 0; i < columns; ++i)
	{
		grid[i].resize(rows);
	}
}

void discoverAdj(int x, int y, int roomNum)
{
	rooms[roomNum].push_back(std::make_pair(x, y));
	checked[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		int newX = x + adj[i][0];
		int newY = y + adj[i][1];

		if (newX < 0 || newY < 0 || newX > columns - 1 || newY > rows - 1 || checked[newX][newY] || !grid[newX][newY])
			continue;

		discoverAdj(newX, newY, roomNum);
	}
}

int main()
{
	std::cin >> flooring;
	std::cin >> rows;
	std::cin >> columns;

	resize(grid);
	resize(checked);
	rooms.resize(100); // random number

	for (int y = 0; y < rows; ++y)
	{
		std::string row;
		std::cin >> row;

		for (int x = 0; x < columns; ++x)
		{
			if (row.at(x) == '.')
			{
				grid[x][y] = true;
			}
		}
	}

	int currentRoom = 0;

	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < columns; ++x)
		{
			if (!grid[x][y] || checked[x][y]) // not a room or already checked
				continue;

			discoverAdj(x, y, currentRoom);
			currentRoom++;
		}
	}

	// sort list
	std::sort(rooms.begin(), rooms.end(), [](const std::vector<std::pair<int, int>>& a, const std::vector<std::pair<int, int>>& b) 
		{ 
			return a.size() > b.size(); 
		}
	);

	int roomsFloored = 0;

	for (int i = 0; i < rooms.size(); ++i)
	{
		int size = rooms[i].size(); //because rooms.size() is unsigned int, unable to check negative

		if (flooring - size < 0 || size == 0) // reached end of valid ones
		{
			break;
		}

		flooring -= size;
		roomsFloored++;
	}

	std::string roomsText = (roomsFloored == 1) ? "room" : "rooms";

	std::cout << roomsFloored << " " << roomsText << ", " << flooring << " square metre(s) left over" << std::endl;

	return 0;
}
*/