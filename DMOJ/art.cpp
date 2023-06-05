/*
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string rows, columns, choices;

	std::getline(std::cin, rows);
	std::getline(std::cin, columns);
	std::getline(std::cin, choices);

	int rowNum = atoi(rows.c_str());
	int columnNum = atoi(columns.c_str());
	int choiceNum = atoi(choices.c_str());
	
	int* rowsPainted = new int[rowNum];
	int* columnsPainted = new int[columnNum];

	std::fill(rowsPainted, rowsPainted + rowNum, 0);
	std::fill(columnsPainted, columnsPainted + columnNum, 0);

	for (int i = 0; i < choiceNum; ++i)
	{
		std::string choice;
		std::getline(std::cin, choice);

		int val = atoi(choice.substr(2).c_str()) - 1;

		if (choice.at(0) == 'R')
		{
			rowsPainted[val]++;
		}
		else if (choice.at(0) == 'C')
		{
			columnsPainted[val]++;
		}
	}

	int gold = 0;

	for (int i = 0; i < rowNum; ++i) {
		for (int j = 0; j < columnNum; ++j)
		{
			if ((rowsPainted[i] % 2 != 0 && columnsPainted[j] % 2 == 0) || (rowsPainted[i] % 2 == 0 && columnsPainted[j] % 2 != 0))
			{
				gold++;
			}
		}
	}

	std::cout << gold << std::endl;

	return 0;
}
*/