/*
#include <iostream>
#include <utility>
#include <limits>
#include <queue>
#include <vector>
#include <array>

class Triplet
{
public:
	int index, time, wear;

	Triplet(int b, int t, int h)
	{
		index = b;
		time = t;
		wear = h;
	}
};

class Compare // because of Triplet, need new Compare class for pq
{
public:
	bool operator() (Triplet a, Triplet b)
	{
		if (a.index > b.index)
			return true;
		else if (a.index == b.index && a.time > b.time)
			return true;

		return false;
	}
};

std::vector<std::vector<int>> dijkstra(std::vector<std::vector<Triplet>> adj,int start, int hull)
{
	std::vector<bool> visited;
	visited.resize(adj.size());
	std::fill(visited.begin(), visited.end(), false);

	std::vector<std::vector<int>> dist;
	dist.resize(adj.size());

	for (int i = 0; i < adj.size(); i++)
	{
		dist[i].resize(hull + 1);
		std::fill(dist[i].begin(), dist[i].end(), std::numeric_limits<int>::max());
	}

	dist[start][0] = 0;

	std::priority_queue<Triplet, std::vector<Triplet>, Compare> pq;
	pq.push({ start, 0, 0}); // start, time, wear

	while (pq.size() > 0)
	{
		Triplet node = pq.top();
		pq.pop();

		for (auto it = adj[node.index].begin(); it != adj[node.index].end(); it++)
		{
			int next = (*it).index;
			int weight = (*it).time;
			int wearDec = (*it).wear;

			int newDist = dist[node.index][node.wear] + weight;
			int newWear = node.wear + wearDec;

			if (newWear < hull && newDist < dist[next][newWear])
			{
				dist[next][newWear] = newDist;
				pq.push({ next, newDist, newWear });
			}
		}
	}
	return dist;
}

int main()
{
	int K, N, M, A, B;

	std::cin >> K;
	std::cin >> N;
	std::cin >> M;

	std::vector<std::vector<Triplet>> adj;
	adj.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, t, h;

		std::cin >> a;
		std::cin >> b;
		std::cin >> t;
		std::cin >> h;

		adj[a].push_back({ b, t, h });
		adj[b].push_back({ a, t, h });
	}

	std::cin >> A;
	std::cin >> B;

	std::vector<std::vector<int>> dist = dijkstra(adj, A, K);

	int least = std::numeric_limits<int>::max();

	for (auto it = dist[B].begin(); it != dist[B].end(); it++)
	{
		if (*it < least && *it > 0)
		{
			least = *it;
		}
	}

	if (least == std::numeric_limits<int>::max())
	{
		least = -1;
	}

	std::cout << least << std::endl;

	return 0;
}
*/