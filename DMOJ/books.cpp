/*
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <utility>

int main()
{
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	std::string books;
	std::cin >> books;

	int mNum = 0, lNum = 0, sNum = 0; // since m is in the middle, just switch as many times as m's there are
	int swaps = 0;

	std::stack<int> lStack;
	std::queue<int> sQueue;

	int lastL = -1, lastS = -1;

	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i] == 'S')
		{
			sQueue.push(i);
			sNum++;
		}
		else if (books[i] == 'L')
		{
			lStack.push(i);
			lNum++;
		}
		else if (books[i] == 'M')
		{
			mNum++;
		}
	}

	int shorter = (sQueue.size() < lStack.size()) ? sQueue.size() : lStack.size();

	for (int i = 0; i < shorter; ++i)
	{
		int sIndex = sQueue.front();
		int lIndex = lStack.top();

		if (sIndex < lIndex)
		{
			books.erase(sIndex, 1);
			books.insert(sIndex, "L");

			books.erase(lIndex, 1);
			books.insert(lIndex, "S");

			swaps++;
		}
		else
		{
			break;
		}

		sQueue.pop();
		lStack.pop();
	}

	int endM = 0, endL = 0, endS = 0; // how many m's at the end
	int startM = 0; // how many m's at the start
	int stopM = false; // if already counted all of m's at the start


	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i] == 'L')
		{
			lastL = i;
			stopM = true;
			endM = 0;
			endL++;
			endS = 0;
		}
		else if (books[i] == 'S' && lastS == -1)
		{
			lastS = i;
			stopM = true;
			endM = 0;
			endS++;
			endL = 0;
		}
		else if (books[i] == 'M')
		{
			if (!stopM)
			{
				startM++;
			}
			
			endM++;

			endL = 0;
			endS = 0;
		}
	}

	if (mNum)
	{
		if (lastL != -1 && lastS != -1)
		{
			swaps += mNum - (lastS - lastL - 1); // subtract how many m's are in the right place and dont need to be swapped
		}
		else if (lastL == -1) // no L
		{
			if (sNum - endS < mNum - endM)
			{
				swaps += sNum - endS;
			}
			else
			{
				swaps += mNum - endM;
			}

			swaps += mNum - startM;
		}
		else if (lastS == -1) // no S
		{
			if (lNum - endL < mNum - endM)
			{
				swaps += lNum - endL;
			}
			else
			{
				swaps += mNum - endM;
			}
		}
	}

	std::cout << swaps << std::endl;

	return 0;
}
*/