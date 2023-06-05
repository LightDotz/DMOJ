/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

std::vector<std::vector<int>> otherNum = {
	{1, 2},
	{0, 2},
	{0, 1}
};

std::vector<std::pair<int, int>> corners = {
	{0, 0},
	{0, 2},
	{2, 0},
	{2, 2}
};

std::vector<std::string> solve3(std::vector<std::string> nums)
{
	if (nums[0].compare("X") != 0 && nums[1].compare("X") != 0 && nums[2].compare("X") == 0) // N N X
	{
		nums[2] = std::to_string(std::stoi(nums[1]) + (std::stoi(nums[1]) - std::stoi(nums[0])));
	}
	else if (nums[1].compare("X") != 0 && nums[2].compare("X") != 0 && nums[0].compare("X") == 0) // X N N
	{
		nums[0] = std::to_string(std::stoi(nums[1]) - (std::stoi(nums[2]) - std::stoi(nums[1])));
	}
	else if (nums[0].compare("X") != 0 && nums[2].compare("X") != 0 && nums[1].compare("X") == 0) // N X N
	{
		nums[1] = std::to_string(std::stoi(nums[0]) + ((std::stoi(nums[2]) - std::stoi(nums[0])) / 2));
	}

	return nums;
}

void check0(std::vector<std::vector<std::string>>& square)
{
	bool solved1 = true; // solved at least one

	while (solved1)
	{
		solved1 = false;
		for (int i = 0; i < 3; i++)
		{
			std::vector<std::string> newNums = solve3(square[i]);
			
			if (newNums != square[i])
			{
				square[i] = solve3(square[i]);
				solved1 = true;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			std::vector<std::string> column = { square[0][i], square[1][i], square[2][i] };

			std::vector<std::string> newColumn = solve3(column);

			for (int j = 0; j < 3; j++)
			{
				if (square[j][i] != newColumn[j])
				{
					square[j][i] = newColumn[j];
					solved1 = true;
				}
			}
		}
	}
}

void check1(std::vector<std::vector<std::string>>& square)
{
	// because of the previous check, we can assume the remaining rows/columns either have either 2 or 3 Xs
	std::vector<int> xAmtR, xAmtC;

	int rFilled = 3, cFilled = 3;

	xAmtR.resize(3);
	xAmtC.resize(3);

	for (int i = 0; i < 3; i++)
	{
		bool doneR = false, doneC = false;

		for (int j = 0; j < 3; j++)
		{
			if (square[i][j].compare("X") == 0)
			{
				xAmtR[i]++;

				if (doneR == false)
				{
					doneR = true;
					rFilled--;
				}
			}

			if (square[j][i].compare("X") == 0)
			{
				xAmtC[i]++;

				if (doneC == false)
				{
					doneC = true;
					cFilled--;
				}
			}
		}
	}

	if (rFilled == 1 && cFilled == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int o = 0; o < 2; o++)
			{
				int other = otherNum[i][o];

				if (xAmtR[i] == 0 && xAmtR[other] == 2) // rows
				{
					for (int col = 0; col < 3; col++)
					{
						if (square[other][col].compare("X") != 0)
						{
							int other1_1 = otherNum[col][0];
							int other1_2 = otherNum[col][1];

							int diff = std::stoi(square[other][col]) - std::stoi(square[i][col]);

							square[other][other1_1] = std::to_string(std::stoi(square[i][other1_1]) + diff);
							square[other][other1_2] = std::to_string(std::stoi(square[i][other1_2]) + diff);
						}
					}
				}
			}
		}
	}
	else if (rFilled == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			int other1 = otherNum[i][0];
			int other2 = otherNum[i][1];

			if (xAmtR[i] == 0)
			{
				square[other1] = square[i];
				square[other2] = square[i];
			}
		}
	}
	else if (cFilled == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			int other1 = otherNum[i][0];
			int other2 = otherNum[i][1];

			if (xAmtC[i] == 0) // columns
			{
				square[0][other1] = square[0][i];
				square[1][other1] = square[1][i];
				square[2][other1] = square[2][i];

				square[0][other2] = square[0][i];
				square[1][other2] = square[1][i];
				square[2][other2] = square[2][i];
			}
		}
	}
}

void check2(std::vector<std::vector<std::string>>& square)
{
	std::vector<std::pair<int, int>> nonX;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (square[i][j].compare("X") != 0)
			{
				nonX.push_back(std::make_pair(i, j));
			}
		}
	}

	if (nonX.size() > 3)
		return;

	if (nonX.size() == 3)
	{
		if (square[1][1].compare("X") != 0) // b is in center
		{
			square[1][0] = square[1][1];
		}
		else if (square[0][1].compare("X") != 0) // b is top middle
		{
			square[1][1] = square[0][1];
		}
		else if (square[2][1].compare("X") != 0) // b is bottom middle
		{
			square[1][1] = square[2][1];
		}
	}
	else if (nonX.size() == 2)
	{
		if (square[1][1].compare("X") != 0) // b is in center
		{
			square[0][1] = square[1][1];
			square[1][0] = square[1][1];
		}
		else if (square[0][1].compare("X") != 0)
		{
			square[1][1] = square[0][1];
			square[1][0] = square[0][1];
		}
		else if (square[2][1].compare("X") != 0)
		{
			square[1][1] = square[2][1];
			square[1][0] = square[2][1];
		}
		else // no b
		{
			for (int i = 0; i < corners.size(); i++)
			{
				if (square[corners[i].first][corners[i].second].compare("X") != 0)
				{					
					if (corners[i].second == 0)
						square[corners[i].first][2] = square[corners[i].first][corners[i].second];
					else
						square[corners[i].first][0] = square[corners[i].first][corners[i].second];

					break;
				}
			}
		}
	}
	else if (nonX.size() == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				square[i][j] = square[nonX[0].first][nonX[0].second];
			}
		}
	}
}

int main()
{
	std::vector<std::vector<std::string>> square;
	square.resize(3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::string num;
			std::cin >> num;

			square[i].push_back(num);
		}
	}

	bool solved = false;

	while (!solved)
	{
		check0(square);
		check1(square);
		check2(square);

		solved = true;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (square[i][j].compare("X") == 0)
				{
					solved = false;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << square[i][j];

			if (j != 2)
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}
*/