/*
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, M, K;
	std::vector<int> A;
	std::vector<int> gaps;

	std::cin >> N >> M >> K;

	int lastNum = 0;
	int biggestGap = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;
		A.push_back(num);

		int currGapSize = num - lastNum - 1;

		int back = currGapSize + K;
		int fwd = currGapSize + K;
		if (num - K < 0)
		{
			back = currGapSize + num;
		}
		
		if (num + K > M)
		{
			fwd = currGapSize + num;
		}

		int potential = std::min(back, fwd);

		if (potential > biggestGap)
		{
			biggestGap = potential;
		}

		lastNum = num;
	}

	std::cout << biggestGap << std::endl;
	
	return 0;
}*/