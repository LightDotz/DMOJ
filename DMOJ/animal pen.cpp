/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

class Triplet
{
public:
	int from, to, cost;
	Triplet(int f, int t, int c)
	{
		from = f;
		to = t;
		cost = c;
	}
	friend bool operator== (Triplet a, Triplet b);
};

bool operator== (Triplet a, Triplet b)
{
	if (a.from == b.from && a.to == b.to)
		return true;
	else if (a.from == b.to && b.from == a.to)
		return true;
	return false;
}

struct Compare
{
	bool operator() (Triplet& a, Triplet& b)
	{
		if (a.cost < b.cost)
			return true;
		return false;
	}
}; // because of Triplet, need new Compare struct

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

int done[1001][1001];

int main()
{
	int M;
	scanf("%i", &M);

	std::vector<Triplet> edges;
	std::vector<Triplet> outer;

	for (int i = 0; i < 1001; i++)
	{
		std::fill(done[i], done[i] + 1001, -1);
	}

	for (int i = 1; i < M + 1; i++) // 0 is outside
	{
		int e;
		std::cin >> e;

		std::vector<int> tempInput;

		for (int j = 0; j < e * 2; j++)
		{
			int num;
			scanf("%i", &num);

			tempInput.push_back(num);
		}

		for (int j = 0; j < e; j++)
		{
			int from, to, cost;

			from = tempInput[j];
			cost = tempInput[j + e];

			if (j == e - 1) // to is the first
				to = tempInput[0];
			else
				to = tempInput[j + 1];

			if (done[from][to] == -1 && done[to][from] == -1)
			{
				done[from][to] = i; // store pen num
				done[to][from] = i;
				outer.push_back(Triplet(from, to, cost));
				continue;
			}

			auto it = std::find(outer.begin(), outer.end(), Triplet(from, to, cost));
			if (it != outer.end())
				outer.erase(it);
			edges.push_back(Triplet(done[from][to], i, cost));
		}
	}

	// 1 cluster

	std::sort(edges.begin(), edges.end(), [](const Triplet& a, const Triplet& b) {
		return a.cost < b.cost;
	});

	UnionFind uf1(M);
	int cost1 = 0;

	for (auto edge = edges.begin(); edge != edges.end(); edge++)
	{
		if (uf1.connected(edge->from, edge->to))
			continue;

		uf1.merge(edge->from, edge->to);
		cost1 += edge->cost;
	}

	// 2+ clusters
	for (auto trp = outer.begin(); trp != outer.end(); trp++)
	{
		int pen = done[trp->from][trp->to];
		edges.push_back(Triplet(pen, 0, trp->cost));
	}

	std::sort(edges.begin(), edges.end(), [](const Triplet& a, const Triplet& b) {
		return a.cost < b.cost;
	});

	UnionFind uf2(M);
	int cost2 = 0;

	for (auto edge = edges.begin(); edge != edges.end(); edge++)
	{
		if (uf2.connected(edge->from, edge->to))
			continue;

		uf2.merge(edge->from, edge->to);
		cost2 += edge->cost;
	}

	printf("%i\n", std::min(cost1, cost2));

	return 0;
}
*/