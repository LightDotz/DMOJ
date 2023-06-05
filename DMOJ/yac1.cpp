/*
#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
	int N;

	std::cin >> N;

	int moves = 0;
	bool impossible = false;

	int* bossBefore = new int[N + 1];
	int* bossAfter = new int[N + 1];
	
	for (int i = 1; i <= N; i++)
	{
		int boss;
		std::cin >> boss;

		bossBefore[i] = boss;
	}

	for (int i = 1; i <= N; i++)
	{
		int boss;
		std::cin >> boss;
		
		bossAfter[i] = boss;
	}

	for (int i = 1; i <= N; i++)
	{
		if (bossBefore[i] != bossAfter[i])
		{
			if (bossBefore[bossAfter[i]] == bossBefore[i])
			{
				moves++;
			}
			else
			{
				moves = -1;
				break;
			}
		}
	}

	std::cout << moves << std::endl;

	return 0;
}
*/