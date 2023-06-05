/*
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

const int BOARD_X = 8;
const int BOARD_Y = 8;

class Board
{
private:
	vector<vector<int>> possiblePaths[8][8]; // [x1][y2] = {{x2, y2}, {x3, y3}}

	int KNIGHT_MOVES[8][2] = {
		{2, -1},
		{2, 1},

		{-2, -1},
		{-2, 1},

		{1, -2},
		{1, 2},

		{-1, -2},
		{-1, 2},
	};
public:
	int BFS(vector<int> start, vector<int> finish);
	void FindPossiblePaths(vector<int> pos);
};

void Board::FindPossiblePaths(vector<int> pos)
{
	for (int i = 0; i < 8; ++i) // knight can only move to 8 possible positions
	{
		int xMove = KNIGHT_MOVES[i][0];
		int yMove = KNIGHT_MOVES[i][1];
		vector<int> newPos;

		newPos.push_back(pos[0] + xMove);
		newPos.push_back(pos[1] + yMove);

		if (newPos[0] < 0 || newPos[0] > BOARD_X - 1 || newPos[1] < 0 || newPos[1] > BOARD_Y - 1) // make sure move is valid
		{
			continue;
		}

		possiblePaths[pos[0]][pos[1]].push_back(newPos);

		if (possiblePaths[newPos[0]][newPos[1]].size() == 0) // haven't checked paths
		{
			FindPossiblePaths(newPos);
		}
	}
}

int Board::BFS(vector<int> start, vector<int> finish)
{
	// do a bfs search

	bool visited[BOARD_X][BOARD_Y] = { false };
	queue<vector<int>> posQueue;
	vector<int> previous[8][8]; // keep track of previous nodes, although idk if this will sometimes overwrite if a node maybe is used twice?

	visited[start[0]][start[1]] = true;
	previous[start[0]][start[1]] = vector<int>(); // source
	posQueue.push(start);

	bool found = false;

	while (!posQueue.empty() && !found)
	{
		vector<int> newPos = posQueue.front();
		posQueue.pop();

		for (vector<vector<int>>::iterator it = possiblePaths[newPos[0]][newPos[1]].begin(); it != possiblePaths[newPos[0]][newPos[1]].end(); ++it)
		{
			vector<int> checkPos = *it;

			if (!visited[checkPos[0]][checkPos[1]])
			{
				visited[checkPos[0]][checkPos[1]] = true;
				previous[checkPos[0]][checkPos[1]] = newPos;
				posQueue.push(checkPos);

				if (checkPos[0] == finish[0] && checkPos[1] == finish[1])
				{
					found = true;
					break;
				}
			}
		}
	}

	int length = 0;
	vector<int> currPos = finish;

	while (true)
	{
		currPos = previous[currPos[0]][currPos[1]];

		if (currPos.size() == 0) // reached start
		{
			break;
		}

		length++;
	}

	return length;
}

int main2()
{
	string start;
	string end;

	getline(cin, start);
	getline(cin, end);

	vector<int> startPos = { atoi(&start.at(0)) - 1, atoi(&start.at(1)) - 1 };
	vector<int> endPos = { atoi(&end.at(0)) - 1, atoi(&end.at(1)) - 1 };

	Board b;
	b.FindPossiblePaths(startPos);
	int length = b.BFS(startPos, endPos);

	std::cout << length << std::endl;

	return 0;
}
*/
