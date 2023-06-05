/*
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int change = 0;

std::vector<std::string> swap(std::vector<char> cData, std::vector<std::string> sData)
{
	for (auto c = sData[0].begin(); c != sData[0].end(); c++)
	{
		if (*c != cData[0])
		{
			change++;
			if (*c == cData[1])
			{
				int main = 1;
				int backup = 2;

				int idx = sData[main].find(cData[0]);
				if (idx != std::string::npos)
				{
					sData[main][idx] = cData[main];
					*c = cData[0];
				}
				else
				{
					idx = sData[main].find(cData[backup]);
					sData[main][idx] = cData[main];
					*c = cData[backup];
				}
			}
			else
			{
				int main = 2;
				int backup = 1;

				int idx = sData[main].find(cData[0]);
				if (idx != std::string::npos)
				{
					sData[main][idx] = cData[main];
					*c = cData[0];
				}
				else
				{
					idx = sData[main].find(cData[backup]);
					sData[main][idx] = cData[main];
					*c = cData[backup];
				}
			}
		}
	}

	return sData;
}

int main()
{
	std::string books;
	std::cin >> books;

	int L = 0, M = 0, S = 0;

	for (auto c = books.begin(); c != books.end(); c++)
	{
		switch (*c)
		{
		case 'L':
			L++;
			break;
		case 'M':
			M++;
			break;
		case 'S':
			S++;
			break;
		}
	}

	std::string lSec;
	lSec = books.substr(0, L);

	std::string mSec;
	mSec = books.substr(L, M);

	std::string sSec;
	sSec = books.substr(L + M, S);

	std::vector<std::string> sData = swap({ 'L', 'M', 'S' }, { lSec, mSec, sSec });
	lSec = sData[0], mSec = sData[1], sSec = sData[2];
	swap({ 'M', 'L', 'S' }, { mSec, lSec, sSec });
	lSec = sData[0], mSec = sData[1], sSec = sData[2];
	swap({ 'S', 'L', 'M' }, { sSec, lSec, mSec });
	lSec = sData[0], mSec = sData[1], sSec = sData[2];

	std::cout << change << std::endl;

	return 0;
}
*/