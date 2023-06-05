/*
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <utility>

int scoresAdd1[3] = { 3, 1, 0 };
int scoresAdd2[3] = { 0, 1, 3 };

std::array<std::array<int, 5>, 4> completedGames = { {0} };

std::vector<std::array<int, 5>> wins(std::array<int, 5> score, std::array<std::array<int, 5>, 4> &potentialGames, std::vector<std::array<int, 5>> endScore)
{
	bool found = false;

	int team1 = 1;
	int team2 = 1;

	for (int team1 = 1; team1 <= 3; team1++)
	{
		for (int team2 = 1; team2 <= 4; team2++)
		{
			if (potentialGames[team1][team2] == 0)
				continue;

			for (int i = 0; i < 3; i++)
			{
				std::cout << team1 << "\t" << team2 << std::endl;
				auto newScore = score;
				auto newGames = potentialGames;

				newScore[team1] += scoresAdd1[i];
				newScore[team2] += scoresAdd2[i];

				newGames[team1][team2] = 0;

				auto scoreVec = wins(newScore, newGames, endScore);

				for (auto it = scoreVec.begin(); it != scoreVec.end(); ++it)
				{
					endScore.push_back(*it);
				}
			}
		}

	}

	// no more potential games
	endScore.push_back(score);
	return endScore;
}

int main()
{
	std::vector<> potentialGames = { {0} };

	// idk why the index is the number but it was only the number before, no index == number
	potentialGames[1] = { 0, 0, 2, 3, 4 };
	potentialGames[2] = { 0, 0, 0, 3, 4 };
	potentialGames[3] = { 0, 0, 0, 0, 4 };
	
	int myTeam, gamesPlayed;

	std::cin >> myTeam;
	std::cin >> gamesPlayed;
	
	std::array<int, 5> score = { 0 };

	for (int i = 0; i < gamesPlayed; i++)
	{
		int team1, team2, score1, score2;

		std::cin >> team1;
		std::cin >> team2;
		std::cin >> score1;
		std::cin >> score2;

		int key = std::min(team1, team2);

		potentialGames[key][std::max(team1, team2)] = 0;

		if (score1 > score2)
		{
			score[team1] += 3;
		}
		else if (score1 < score2)
		{
			score[team2] += 3;
		}
		else
		{
			score[team1]++;
			score[team2]++;
		}
	}

	auto newGames = potentialGames;

	auto scoreVec = wins(score, newGames, std::vector<std::array<int, 5>>());
	int wins = 0;

	for (auto it = scoreVec.begin(); it != scoreVec.end(); ++it)
	{
		bool won = true;
		for (int otherTeam = 1; otherTeam <= 4; otherTeam++)
		{
			if (otherTeam == myTeam)
				continue;

			if ((*it)[myTeam] < (*it)[otherTeam])
			{
				won = false;
				break;
			}

			if (won)
				wins++;
		}
	}

	std::cout << wins << std::endl;

	return 0;
}
*/