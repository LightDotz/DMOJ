#include <iostream>
#include <vector>
#include <utility>

int T, G;
std::vector<std::pair<int, int>> toPlay;

int calcPossible(std::vector<int> score, std::vector<std::pair<int, int>>::iterator currIt, int won = 0)
{
	if (currIt == toPlay.end())
	{
		int largestAmt = 0, team;
		bool unique = true;
		for (int i = 1; i <= 4; i++)
		{
			if (score[i] > largestAmt)
			{
				team = i;
				largestAmt = score[i];
				unique = true;
			}
			else if (score[i] == largestAmt)
				unique = false;
		}

		if (team == T && unique)
		{
			return won + 1;
		}

		return won;
	}

	for (int i = 0; i < 3; i++) // three possible optiosn
	{
		std::vector<int> newScore = score;
		if (i == 0)
		{
			newScore[currIt->first] += 3;
		}
		else if (i == 1)
		{
			newScore[currIt->second] += 3;
		}
		else
		{
			newScore[currIt->first]++;
			newScore[currIt->second]++;
		}

		won = calcPossible(newScore, currIt + 1, won);
	}

	return won;
}

int main()
{
	std::vector<std::pair<int, int>> possible = {
		{1, 2},
		{1, 3},
		{1, 4},
		{2, 3},
		{2, 4},
		{3, 4}
	};

	std::vector<int> score(5);
	std::vector<std::vector<bool>> played(5);

	for (int i = 1; i <= 4; i++)
	{
		played[i].resize(5);
	}

	scanf("%i %i", &T, &G);
	for (int i = 0; i < G; i++)
	{
		int A, B, sA, sB;
		scanf("%i %i %i %i", &A, &B, &sA, &sB);

		played[A][B] = true;
		played[B][A] = true;

		if (sA > sB)
			score[A] += 3;
		else if (sA < sB)
			score[B] += 3;
		else
		{
			score[A]++;
			score[B]++;
		}
	}


	for (auto it = possible.begin(); it != possible.end(); it++)
	{
		if (played[it->first][it->second] == false && played[it->first][it->second] == false)
		{
			toPlay.push_back(*it);
		}
	}

	int won = calcPossible(score, toPlay.begin());
	printf("%i\n", won);

	return 0;
}