/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

class Triplet
{
public:
	long from, to, cost, idx;
	Triplet(long f, long t, long c, long i)
	{
		from = f;
		to = t;
		cost = c;
		idx = i;
	}
	Triplet& operator=(Triplet const& t);
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

Triplet& Triplet::operator=(Triplet const& t)
{
	from = t.from;
	to = t.to;
	cost = t.cost;
	idx = t.idx;
	return *this;
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

int main()
{
	int N, M, D;
	std::cin >> N >> M >> D;

	std::vector<Triplet> edges;

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		scanf("%i", &A);
		scanf("%i", &B);
		scanf("%i", &C);
		edges.push_back({ A, B, C, i });
	}

	std::sort(edges.begin(), edges.end(), [](const Triplet& a, const Triplet& b) {
		if (a.cost == b.cost)
		{
			return a.idx < b.idx;
		}
		return a.cost < b.cost;
	});

	// first kruskals
	UnionFind uf1(N);
	int changed = 0;
	long biggest = 0;

	for (std::vector<Triplet>::iterator edge = edges.begin(); edge != edges.end(); edge++)
	{
		if (uf1.connected(edge->from, edge->to))
			continue;
		
		uf1.merge(edge->from, edge->to);
		
		if (edge->cost > biggest)
			biggest = edge->cost;

		if (edge->idx >= N - 1) // wasn't in origPlan
			changed++;
	}

	//second kruskals
	UnionFind uf2(N);

	for (std::vector<Triplet>::iterator edge = edges.begin(); edge != edges.end(); edge++)
	{
		if (uf2.connected(edge->from, edge->to))
			continue;

		if (edge->cost < biggest || (edge->cost == biggest && edge->idx < N - 1))
			uf2.merge(edge->from, edge->to);
		else if (edge->cost <= D && edge->idx < N - 1)
		{
			changed--;
			break;
		}
	}

	printf("%i", changed);
	return 0;
}
*/