/*
#include <set>
#include <iostream>
#include <iterator>
#include <cmath>

using namespace std;

*/
/*
int binarySearch(int target, int start, int end)
{
	int pos = ceil((end - start) / 2);
	auto it = gates.begin();
	std::advance(it, pos);

	if (start > end)
	{
		return -1;
	}

	if (*it == target)
	{
		return pos;
	}
	else if (*it > target)
	{
		binarySearch(target, start, pos - 1);
	}
	else
	{
		binarySearch(target, pos + 1, end);
	}
}


int main()
{
	int gateNum, planeNum;
	std::cin >> gateNum;
	std::cin >> planeNum;

	int landedPlanes = 0;

	for (int i = 1; i <= gateNum; i++)
	{
		gates.insert(i);
	}

	bool stopped = false;

	for (int i = 0; i < planeNum; i++)
	{
		int possibleDock;
		std::cin >> possibleDock;

		if (stopped)
		{
			continue;
		}

		bool foundGate = false;
		auto it = gates.find(possibleDock);
		gates.erase(it);

		if (!foundGate)
		{
			stopped = true;
		}
		else
		{
			landedPlanes++;
		}
	}

	std::cout << landedPlanes << std::endl;

	return 0;
}
*/