/*
#include <iostream>
#include <utility>
#include <limits>
#include <queue>
#include <vector>

typedef std::pair<int, int> intPair;

std::vector<int> dijkstra(std::vector<std::vector<intPair>> adj, int start)
{
	std::vector<int> dist;
	dist.resize(adj.size());
	std::fill(dist.begin(), dist.end(), std::numeric_limits<int>::max());
	dist[start] = 0;

	std::priority_queue<intPair, std::vector<intPair>, std::greater<intPair>> pq;
	pq.push(std::make_pair(start, 0));

	while (pq.size() > 0)
	{
		intPair node = pq.top();
		pq.pop();

		if (dist[node.first] < node.second) // if it's been replaced
			continue;

		for (auto it = adj[node.first].begin(); it != adj[node.first].end(); it++)
		{
			int next = it->first;
			int weight = it->second;

			int newDist = dist[node.first] + weight;

			if (newDist < dist[next])
			{
				dist[next] = newDist;
				pq.push(std::make_pair(next, newDist));
			}
		}
	}
	return dist;
}

int main()
{
	int N, M;

	std::cin >> N;
	std::cin >> M;

	std::vector<std::vector<intPair>> adj;
	adj.resize(N);

	for (int i = 0; i < M; i++)
	{
		int a, b, t;

		std::cin >> a;
		std::cin >> b;
		std::cin >> t;

		adj[a].push_back(std::make_pair(b, t));
		adj[b].push_back(std::make_pair(a, t));
	}

	std::vector<int> dist1 = dijkstra(adj, 0);
	std::vector<int> dist2 = dijkstra(adj, N - 1);

	int longest = 0;

	for (int i = 0; i < N; i++)
	{
		if (dist1[i] + dist2[i] > longest)
		{
			longest = dist1[i] + dist2[i];
		}
	}

	std::cout << longest << std::endl;

	return 0;
}
*/