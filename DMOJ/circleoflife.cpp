/*
#include <iostream>
#include <cstring>
#include <string>

char oldCells[100001];
char newCells[100001];

long long exponent(long long base, long long maximum)
{
	long long curr = 1;
	while (true)
	{
		if (curr * base > maximum)
			break;
		curr *= base;
	}

	return curr;
}

int main()
{
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	long long T = 0;
	int N = 0;

	std::cin >> N >> T;

	std::string input;
	std::getline(std::cin, input);
	std::getline(std::cin, input);

	strcpy(oldCells, input.c_str());

	while (true)
	{
		long long curr = exponent(2, T);
		T -= curr;
		curr = curr % N;

		for (int i = 0; i < N; i++)
		{
			int num1, num2;
			if (i - curr < 0)
				num1 = oldCells[N - (curr - i)];
			else
				num1 = oldCells[i - curr];

			if (i + curr > N - 1)
				num2 = oldCells[curr - (N - i)];
			else
				num2 = oldCells[i + curr];

			newCells[i] = ((num1 - 48) ^ (num2 - 48)) + 48;
		}

		if (T == 0)
		{
			break;
		}
		strcpy(oldCells, newCells);
	}

	printf("%s\n", newCells);

	return 0;
}
*/