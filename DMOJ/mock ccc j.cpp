/*
#include <iostream>
#include <string>

int main()
{
	int expected;
	std::string s;

	std::cin >> expected >> s;

	int origSize = s.size();

	int ast = 0;
	int currVal = 0;

	for (auto it = s.begin(); it != s.end(); it++)
	{
		if (*it == '*')
		{
			ast++;
		}
		else
		{
			currVal = (*it) - 96;
		}
	}

	int expectedNow = expected - currVal;

	if (ast < expectedNow)
	{
		if (ast * 26 < expectedNow) // if even max val isn't enough, its impossible
		{
			s = "Impossible";
		}
		else
		{
			int fitMax = expectedNow / 26; // how many z you can fit
			int otherLetterNum = (expectedNow - ast - fitMax);

			if (otherLetterNum < 0)
			{
				fitMax--;
				otherLetterNum = (expectedNow - ast - fitMax);
			}

			otherLetterNum += 97;

			for (int i = 0; i < s.size(); i++)
			{
				int index = s.size() - 1 - i;

				if (s[index] == '*')
				{
					if (fitMax > 0)
					{
						s[index] = 'z';
						fitMax--;
					}
					else if (fitMax == 0)
					{
						s[index] = otherLetterNum;
						fitMax--;
					}
					else
					{
						s[index] = 'a';
					}
				}
			}
		}
	}
	else // ast >= expectedNow
	{
		if (ast > expectedNow) // if even the min val is too much, its impossible
		{
			s = "Impossible";
		}
		else
		{
			int fitMax = expectedNow / 26; // how many z you can fit
			int otherLetterNum = (expectedNow - ast - fitMax);

			if (otherLetterNum < 0)
			{
				fitMax--;
				otherLetterNum = (expectedNow - ast - fitMax);
			}

			otherLetterNum += 97;

			for (int i = 0; i < s.size(); i++)
			{
				int index = s.size() - 1 - i;

				if (s[index] == '*')
				{
					if (fitMax > 0)
					{
						s[index] = 'z';
						fitMax--;
					}
					else if (fitMax == 0)
					{
						s[index] = otherLetterNum;
						fitMax--;
					}
					else
					{
						s[index] = 'a';
					}
				}
			}
		}
	}

	std::cout << s << std::endl;
}
*/