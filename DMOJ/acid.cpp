/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	int readings[1001] = { 0 };

	int sensors;
	std::cin >> sensors;
	
	int highestFrequency = 0;
	int secondHighestFrequency = 0;

	std::vector<int> highestFrequencyNum; // [index] = reading
	std::vector<int> secondHighestFrequencyNum;

	for (int i = 0; i < sensors; ++i)
	{
		int reading;
		std::cin >> reading;

		readings[reading]++;

		if (readings[reading] > highestFrequency)
		{
			highestFrequency = readings[reading];
			highestFrequencyNum.resize(1);
			highestFrequencyNum[0] = reading;
		}
		else if (readings[reading] == highestFrequency)
		{
			highestFrequencyNum.push_back(reading);
		}
	}

	for (int i = 0; i < 1000; ++i)
	{
		if (readings[i] == highestFrequency)
			continue;

		if (readings[i] > secondHighestFrequency)
		{
			secondHighestFrequency = readings[i];
			secondHighestFrequencyNum.resize(1);
			secondHighestFrequencyNum[0] = i;
		}
		else if (readings[i] == secondHighestFrequency)
		{
			secondHighestFrequencyNum.push_back(i);
		}
	}

	int diff = 0;

	if (highestFrequencyNum.size() > 1)
	{
		for (auto it = highestFrequencyNum.begin(); it != highestFrequencyNum.end(); ++it)
		{
			for (auto it2 = highestFrequencyNum.begin(); it2 != highestFrequencyNum.end(); ++it2)
			{
				diff = std::max(diff, abs(*it - *it2));
			}
		}
	}
	else if (secondHighestFrequencyNum.size() > 1)
	{
		for (auto it = secondHighestFrequencyNum.begin(); it != secondHighestFrequencyNum.end(); ++it)
		{
			diff = std::max(diff, abs(highestFrequencyNum[0] - *it));
		}
	}
	else
	{
		diff = abs(highestFrequencyNum[0] - secondHighestFrequencyNum[0]);
	}

	std::cout << diff << std::endl;

	return 0;
}
*/