/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

std::unordered_map<int, bool> phoList;
std::unordered_map<int, std::vector<int>> adj;

int currLongest = 0;
int longestPos;

void dfs(int start)
{
	std::unordered_map<int, bool> visited;
	std::unordered_map<int, int> lengths;
	std::stack<int> s;

	visited[start] = true;
	lengths[start] = 0;
	s.push(start);

	while (!s.empty())
	{
		int newPos = s.top();
		s.pop();

		for (auto it = adj[newPos].begin(); it != adj[newPos].end(); it++)
		{
			int checkPos = *it;

			if (adj[newPos].size() == 1 && visited[checkPos] && lengths[newPos] > currLongest) {// reached end
				currLongest = lengths[newPos];
				longestPos = newPos;
			}

			if (visited[checkPos] == false)
			{
				lengths[checkPos] = lengths[newPos] + 1;
				visited[checkPos] = true;
				s.push(checkPos);
			}
		}
	}
}

void bfs(int N)
{
	std::unordered_map<int, bool> visited;
	std::queue<int> q;

	for (int i = 0; i < adj.size(); i++)
	{
		if (adj[i].size() == 1 && phoList[i] == false) // leaf
		{
			visited[i] = true;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int newPos = q.front();
		q.pop();

		//cleanup from adj
		for (int i = 0; i < adj[newPos].size(); i++) // prune from adj arr
		{
			int otherNum = adj[newPos][i];
			auto it = std::find(adj[otherNum].begin(), adj[otherNum].end(), newPos);
			adj[otherNum].erase(it);
		}

		for (auto it = adj[newPos].begin(); it != adj[newPos].end(); it++)
		{
			int checkPos = *it;

			if (visited[checkPos] == false && phoList[checkPos] == false && adj[checkPos].size() == 1)
			{
				visited[checkPos] = true;
				q.push(checkPos);
			}
		}

		//final cleanup
		adj.erase(newPos);
	}
}

int main()
{
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	int N, M;
	int startingPho;

	std::cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int pos;
		std::cin >> pos;
		startingPho = pos;
		phoList[pos] = true;
	}

	for (int i = 0; i < N - 1; i++)
	{
		int num1, num2;
		std::cin >> num1 >> num2;

		adj[num1].push_back(num2);
		adj[num2].push_back(num1);
	}

	// pruning
	bfs(N);

	// find diameter of tree
	dfs(startingPho);
	dfs(longestPos);

	int minPath = (adj.size() - (currLongest + 1)) * 2 + currLongest;

	std::cout << minPath << std::endl;

	return 0;
}
*/