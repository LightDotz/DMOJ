/*
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> memo;

int charToInt(char c)
{
	return static_cast<int>(c) - '0';
}

char intToChar(int i)
{
	return std::to_string(i)[0];
}

std::string add(std::string num1, std::string num2) // adding strings because unsigned long long is not big enough
{
	for (int i = 1; i <= num2.length(); i++) // num1 >= num2 always, so use lesser
	{
		int num1P = charToInt(num1.at(num1.length() - i));
		int num2P = charToInt(num2.at(num2.length() - i));

		if (num1P + num2P > 9)
		{
			std::string newNumS = std::to_string(num1P + num2P);
			num1[num1.length() - i] = newNumS.at(1);

			if (num1.length() - i == 0)
			{
				num1.insert(0, std::string(1, newNumS.at(0)));
			}
			else
			{
				int other1 = charToInt(num1.at(num1.length() - i - 1));
				int other2 = charToInt(newNumS.at(0));

				num1[num1.length() - i - 1] = intToChar(other1 + other2);
			}
		}
		else
		{
			num1[num1.length() - i] = intToChar(num1P + num2P);
		}
	}

	return num1;
}

std::string sub(std::string num1, int num2)
{
	int newNum = charToInt(num1.at(num1.length() - 1));

	if (newNum - num2 < 0)
	{
		num1[num1.length() - 1] = intToChar(10 + newNum - num2);
		num1[num1.length() - 2] = intToChar(charToInt(num1[num1.length() - 2]) - 1);

		if (num1.length() - 2 == 0 && num1[num1.length() - 2] == '0')
		{
			num1 = std::string(1, num1[num1.length() - 1]);
		}
	}
	else
	{
		num1[num1.length() - 1] = intToChar(newNum - num2);
	}

	return num1;
}

std::string fib(std::string num)
{
	if (num == "1" || num == "2")
		return "1";
	if (memo[num].length() > 0)
		return memo[num];

	std::string num1 = fib(sub(num, 1));
	std::string num2 = fib(sub(num, 2));

	if (num.compare("18"))
	{
		std::cout << num1 << std::endl;
		std::cout << num2 << std::endl;
	}

	std::string firstFib = add(num1, num2);

	memo[num] = firstFib;
	return memo[num];
}

int main()
{
	std::cout << add("600", "877") << std::endl;

	while (true)
	{
		std::string num;
		std::cin >> num;

		if (num == "0")
		{
			break;
		}

		std::cout << fib(num) << std::endl;
	}
	
	return 0;
}
*/