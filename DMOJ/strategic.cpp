/*
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

bool connected(std::unordered_map<char, std::vector<char>> roads)
{
	std::queue<char> q;
	std::unordered_map<char, bool> visited;

	visited['A'] = true;
	q.push('A');

	while (!q.empty())
	{
		char next = q.front();
		q.pop();

		for (auto it = roads[next].begin(); it != roads[next].end(); ++it)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);

				if (*it == 'B')
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	std::unordered_map<char, std::vector<char>> roads;
	std::string input;
	
	std::vector<std::string> pairs;

	while (true)
	{
		std::cin >> input;

		if (input == "**")
		{
			break;
		}

		pairs.push_back(input);

		char first = input.at(0);
		char second = input.at(1);

		roads[first].push_back(second);
		roads[second].push_back(first);
	}

	int disconnected = 0;

	for (auto pair = pairs.begin(); pair != pairs.end(); pair++)
	{
		char letter1 = (*pair).at(0);
		char letter2 = (*pair).at(1);

		auto editedRoads = roads;

		auto it1 = std::find(editedRoads[letter2].begin(), editedRoads[letter2].end(), letter1);
		auto it2 = std::find(editedRoads[letter1].begin(), editedRoads[letter1].end(), letter2);
		
		editedRoads[letter1].erase(it2);
		editedRoads[letter2].erase(it1);

		if (!connected(editedRoads))
		{
			std::cout << *pair << std::endl;
			disconnected++;
		}
	}

	std::cout << "There are " << disconnected << " disconnecting roads." << std::endl;

	return 0;
}
*/