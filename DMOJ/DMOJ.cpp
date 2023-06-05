#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

std::unordered_map<int, bool> visited;
std::unordered_map<int, bool> isPho;
std::unordered_map<int, std::vector<int>> adj;

int currLongest = 0;
int longestPos;

void dfs(int pos, int length)
{
	length++;
	visited[pos] = true;

	for (auto it = adj[pos].begin(); it != adj[pos].end(); it++)
	{
		if (adj[pos].size() == 1 && visited[*it] && length > currLongest) {// reached end
			currLongest = length;
			longestPos = pos;
		}

		if (!visited[*it])
			dfs(*it, length);
	}
}

int main()
{
	int N, M;

	std::cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int pos;
		std::cin >> pos;
		isPho[pos] = true;
	}

	for (int i = 0; i < N - 1; i++)
	{
		int num1, num2;
		std::cin >> num1 >> num2;

		adj[num1].push_back(num2);
		adj[num2].push_back(num1);
	}

	// pruning

	std::vector<bool> pruVisited;
	std::queue<int> q;

	pruVisited.resize(N);

	for (int i = 0; i < adj.size(); i++)
	{
		if (adj[i].size() == 1 && !isPho[i]) // leaf
		{
			pruVisited[i] = true;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int newPos = q.front();
		q.pop();

		for (auto it = adj[newPos].begin(); it != adj[newPos].end(); it++)
		{
			int checkPos = *it;

			if (!pruVisited[checkPos] && !isPho[checkPos] && adj[checkPos].size() == 1)
			{
				pruVisited[checkPos] = true;
				q.push(checkPos);

				if (checkPos == N - 1)
				{
					break;
				}
			}
		}

		//cleanup from adj
		for (int i = 0; i < adj[newPos].size(); i++) // prune from adj arr
		{
			int otherNum = adj[newPos][i];
			auto it = std::find(adj[otherNum].begin(), adj[otherNum].end(), newPos);
			adj[otherNum].erase(it);
		}
		adj.erase(newPos);
	}

	// find diameter of tree

	dfs(isPho[0], 0);
	dfs(longestPos, 0);

	int minPath = (adj.size() - (currLongest + 1)) * 2 + currLongest;

	std::cout << minPath << std::endl;

	return 0;
}
