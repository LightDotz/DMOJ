/*
#include <iostream>
#include <vector>
#include <algorithm>

int lsb(int n)
{
	return n & -n;
}

class FenwickTree
{
public:
	std::vector<int> bit;
	std::vector<int> orig;
	FenwickTree(std::vector<int> orig);
	FenwickTree(unsigned int size, int fill);
	void updateTree(int idx, long long val);
	long long getSum(int idx);
};

long long FenwickTree::getSum(int idx)
{
	long long sum = 0;

	idx++;
	while (idx > 0)
	{
		sum += bit[idx];
		idx -= lsb(idx);
	}

	return sum;
}

void FenwickTree::updateTree(int idx, long long val)
{
	idx++;
	while (idx < bit.size())
	{
		bit[idx] += val;
		idx += lsb(idx);
	}
}

FenwickTree::FenwickTree(std::vector<int> o)
{
	orig = o;
	bit.resize(orig.size() + 1);
	std::fill(bit.begin(), bit.end(), 0);

	for (int i = 0; i < orig.size(); i++)
		updateTree(i, orig[i]);
}

FenwickTree::FenwickTree(unsigned int size, int fill)
{
	bit.resize(orig.size() + 1);
	std::fill(bit.begin(), bit.end(), fill);
}

int main()
{
	int N, M;
	scanf("%i", &N);
	scanf("%i", &M);

	std::vector<int> orig;

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%i", &num);
		orig.push_back(num);
	}

	FenwickTree ft(orig);
	FenwickTree lessOrEqual(orig.size() + 1, 1);

	for (int i = 0; i < M; i++)
	{
		char c;
		scanf(" %c", &c);

		if (c == 'C')
		{
			int x, v;
			scanf("%i", &x);
			scanf("%i", &v);

			ft.updateTree(x - 1, v - ft.orig[x - 1]);
			ft.orig[x - 1] = v;
			lessOrEqual.updateTree(ft.orig[x - 1], -1);
			lessOrEqual.updateTree(v, 1);
		}
		else if (c == 'S')
		{
			int l, r;
			scanf("%i", &l);
			scanf("%i", &r);
			
			long long sum1 = ft.getSum(l - 2);
			long long sum2 = ft.getSum(r - 1);

			printf("%lld\n", sum2 - sum1);
		}
		else if (c == 'Q')
		{
			int v;
			scanf("%i", &v);

			printf("%lld\n", lessOrEqual.getSum(v - 1));
		}
	}

	return 0;
}
*/