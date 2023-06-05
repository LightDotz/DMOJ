/*
#include <iostream>
#include <string>
#include <vector>

int main()
{
	int days;
	std::string change;

	std::vector<std::vector<char>> matrix(200, std::vector<char>(200, '.'));

	std::cin >> days;
	std::cin >> change;

	int row = 100;
	int highest = 100;
	int lowest = 100;
	char lastAction = '=';

	for (int i = 0; i < days; i++)
	{
		if (change.at(i) == '+')
		{
			if (lastAction == '+')
			{
				row++;
			}
			matrix[i][row] = '/';
		}
		else if (change.at(i) == '-')
		{
			if ((lastAction == '-' || lastAction == '=') && i != 0 )
			{
				row--;
			}
			matrix[i][row] = '\\';
		}
		else if (change.at(i) == '=')
		{
			if (lastAction == '+')
			{
				row++;
			}

			matrix[i][row] = '_';
		}

		if (row > highest)
		{
			highest = row;
		}
		else if (row < lowest)
		{
			lowest = row;
		}

		lastAction = change.at(i);
	}

	for (int i = highest; i >= lowest; i--)
	{
		for (int j = 0; j < days; j++)
		{
			std::cout << matrix[j][i];
		}

		std::cout << "\n";
	}
	
	return 0;
}
*/