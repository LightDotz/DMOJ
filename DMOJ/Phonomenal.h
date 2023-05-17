#pragma once

void phonomenal()
{
	int N, M;

	std::cin >> N >> M;

	std::unordered_map<int, bool> isPho;
	std::vector<std::vector<int>> adj;

	adj.resize(N);

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

	std::vector<bool> visited;
	std::queue<int> q;

	visited.resize(N);

	for (int i = 0; i < adj.size(); i++)
	{
		if (adj[i].size() == 1 && !isPho[i]) // leaf
		{
			visited[i] = true;
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int newPos = q.front();
		q.pop();

		std::cout << newPos << std::endl;

		for (int i = 0; i < adj[newPos].size(); i++) // prune from adj arr
		{
			int otherNum = adj[newPos][i];
			auto it = std::find(adj[otherNum].begin(), adj[otherNum].end(), newPos);
			adj[otherNum].erase(it);
		}

		for (auto it = adj[newPos].begin(); it != adj[newPos].end(); it++)
		{
			int checkPos = *it;

			if (!visited[checkPos] && !isPho[checkPos] && adj[checkPos].size() == 1)
			{
				visited[checkPos] = true;
				q.push(checkPos);

				if (checkPos == N - 1)
				{
					break;
				}
			}
		}
	}
}