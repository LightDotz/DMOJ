/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <limits>

typedef std::pair<long long, long long> llPair;

class Edge
{
public:
	int from, to, length, cost;
	Edge(int f, int t, int l, int c)
	{
		from = f;
		to = t;
		length = l;
		cost = c;
	}
	friend bool operator== (Edge a, Edge b);
};

bool operator== (Edge a, Edge b)
{
	if (a.from == b.from && a.to == b.to)
		return true;
	else if (a.from == b.to && b.from == a.to)
		return true;
	return false;
}

class Vertex
{
public:
	long long pos, length, cost;

	Vertex(long long p, long long l, long long c)
	{
		pos = p;
		length = l;
		cost = c;
	};
	friend bool operator== (Vertex a, Vertex b);
};

bool operator== (Vertex a, Vertex b)
{
	return a.pos == b.pos;
}

class Compare
{
public:
	bool operator() (Vertex a, Vertex b)
	{
		if (a.pos > b.pos)
			return true;
		else if (a.pos == b.pos)
		{
			if (a.length > b.length || (a.length == b.length && a.cost > b.cost))
				return true;
		}
		return false;
	}
};

class UnionFind
{
	std::vector<int> parent, sz;
public:
	UnionFind(int n)
	{
		parent.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			sz[i] = 1;
		}
	};
	int find(int pos);
	void merge(int pos1, int pos2);
	bool connected(int pos1, int pos2);
	int size(int pos);
};

int UnionFind::find(int pos)
{
	int root = pos;
	while (parent[root] != root)
	{
		root = parent[root];
	}
	while (pos != root) // compression
	{
		int next = parent[pos];
		parent[pos] = root;
		pos = next;
	}
	return root;
}

void UnionFind::merge(int pos1, int pos2)
{
	int root1 = find(pos1);
	int root2 = find(pos2);
	if (root1 == root2)
		return;
	sz[root2] += sz[root1];
	parent[root1] = root2;
}

bool UnionFind::connected(int pos1, int pos2)
{
	return find(pos1) == find(pos2);
}

int UnionFind::size(int pos)
{
	return sz[find(pos)];
}

std::vector<llPair> dijkstra(std::vector<std::vector<Vertex>> adj, Vertex start)
{	
	std::vector<llPair> dist;
	dist.resize(adj.size());
	std::fill(dist.begin(), dist.end(), std::make_pair( std::numeric_limits<long long>::max(), std::numeric_limits<long long>::max() ));
	dist[start.pos] = { 0, 0 };

	std::priority_queue<Vertex, std::vector<Vertex>, Compare> pq;
	pq.push(start);

	while (pq.size() > 0)
	{
		Vertex node = pq.top();
		pq.pop();

		if (dist[node.pos].first < node.length || (dist[node.pos].first == node.length && dist[node.pos].second < node.cost))
			continue;

		for (auto next = adj[node.pos].begin(); next != adj[node.pos].end(); next++)
		{
			llPair newDist = dist[node.pos];
			newDist.first += next->length;
			newDist.second += next->cost;

			if (newDist.first < dist[next->pos].first || (newDist.first == dist[next->pos].first && newDist.second < dist[next->pos].second))
			{
				dist[next->pos] = newDist;
				pq.push(Vertex(next->pos, newDist.first, newDist.second));
				//printf("%i, %i, %i\n", next->pos, newDist.first, newDist.second);
			}
		}
	}

	return dist;
}

int main()
{
	std::cin.sync_with_stdio(1);
	std::cin.tie(0);

	int N, M;

	std::cin >> N >> M;

	std::vector<Edge> edges;
	std::vector<std::vector<Vertex>> adj;
	adj.resize(2001);

	for (int i = 0; i < M; i++)
	{
		long long u, v, l, c;
		std::cin >> u >> v >> l >> c;

		auto found = std::find(edges.begin(), edges.end(), Edge(u, v, l, c));

		if (found != edges.end()) // for multi-edge, only compares u and v
		{
			if (found->length > l || (found->length == l && found->cost > c))
			{
				adj[u].erase(std::find(adj[u].begin(), adj[u].end(), Vertex(v, found->length, found->cost)));
				adj[v].erase(std::find(adj[v].begin(), adj[v].end(), Vertex(u, found->length, found->cost)));
				continue; // this edge is worse
			}
			
			edges.erase(found);
		}

		edges.push_back(Edge(u, v, l, c));
		adj[u].push_back(Vertex(v, l, c));
		adj[v].push_back(Vertex(u, l, c));
	}

	auto dist = dijkstra(adj, Vertex(edges[0].from, 0, 0));

	std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
		if (a.length == b.length)
			return a.length < b.length;
		return a.cost < b.cost;
	});

	UnionFind uf(N);
	long long cost = 0;

	for (auto it = edges.begin(); it != edges.end(); it++)
	{
		if (uf.connected(it->from, it->to))
			continue;
		uf.merge(it->from, it->to);

		long long l = std::abs(dist[it->to].first - dist[it->from].first);
		long long c = std::abs(dist[it->to].second - dist[it->from].second);
		if (l < it->length || (l == it->length && c < it->cost))
			it->cost = dist[it->to].second - dist[it->from].second;

		cost += it->cost;
		//printf("%i, %i\n", it->from, it->to);
	}

	std::cout << cost << std::endl;

	return 0;
}
*/