/*
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	
	int pieces;
	int lengths[4001] = { 0 };
	
	std::cin >> pieces;

	while (pieces != 0)
	{
		int num;
		std::cin >> num;

		lengths[num]++;
		pieces--;
	}

	int possibleLengths[4001] = { 0 };

	int longest = 0;
	int longestAmt = 0;

	for (int i = 1; i <= 4000; i++)
	{
		// check all possible length combinations
		for (int j = 1; j <= i / 2; j++)
		{
			int amt = std::min(lengths[j], lengths[i - j]);

			if (j == i - j) // number of pieces is only half if same length
			{
				amt /= 2;
			}

			possibleLengths[i] += amt;
		}

		if (possibleLengths[i] > longest)
		{
			longest = possibleLengths[i];
			longestAmt = 1;
		}
		else if (possibleLengths[i] == longest)
		{
			longestAmt++;
		}
	}

	std::cout << longest << " " << longestAmt;

	return 0;
}
*/