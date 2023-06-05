/*
#include <iostream>
#include <utility>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> intPair;

int main()
{
	int N, M;

	cin >> N;
	cin >> M;

	vector<vector<intPair>> adj;
	adj.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v, w;

		cin >> u;
		cin >> v;
		cin >> w;

		// the below could be optimized and only loop once since it's a bidirectional edge, but i dont want to do the work to access u from v

		bool existU = false, existV = false;

		for (auto it = adj[u].begin(); it != adj[u].end(); it++)
		{
			if (it->first == v && w <= it->second)
			{
				*it = make_pair(v, w);
				existU = true;
			}
		}

		for (auto it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if (it->first == u && w <= it->second)
			{
				*it = make_pair(u, w);
				existV = true;
			}
		}

		if (!existU)
			adj[u].push_back(make_pair(v, w));

		if (!existV)
			adj[v].push_back(make_pair(u, w));
	}

	vector<int> dist;
	dist.resize(N + 1);
	std::fill(dist.begin(), dist.end(), numeric_limits<int>::max());
	dist[1] = 0;

	priority_queue<intPair, vector<intPair>, greater<intPair>> pq;
	pq.push(make_pair(1, 0));

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
				pq.push(make_pair(next, newDist));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == numeric_limits<int>::max())
		{
			cout << -1 << endl;
		}
		else
		{
			cout << dist[i] << endl;
		}
	}

	return 0;
}
*/