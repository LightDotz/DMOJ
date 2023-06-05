/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> people[51] = {
	{}, 
	{6}, 
	{6}, 
	{4, 5, 6, 15}, 
	{3, 5, 6}, 
	{3, 4, 6}, 
	{1, 2, 3, 4, 5, 7}, 
	{6, 8}, 
	{7, 9}, 
	{8, 10, 12}, 
	{9, 11}, 
	{10, 12}, 
	{9, 11, 13}, 
	{12, 14, 15}, 
	{13}, 
	{3, 13}, 
	{17, 18}, 
	{16, 18},
	{16, 17} 
};

int main()
{
	while (true)
	{
		std::string input;
		std::cin >> input;

		if (input == "i")
		{
			int person1, person2;

			std::cin >> person1;
			std::cin >> person2;

			auto it = std::find(people[person1].begin(), people[person1].end(), person2);

			if (it == people[person1].end())
			{
				people[person1].push_back(person2);
				people[person2].push_back(person1);
			}
		}
		else if (input == "d")
		{
			int person1, person2;

			std::cin >> person1;
			std::cin >> person2;

			auto it1 = std::find(people[person1].begin(), people[person1].end(), person2);
			auto it2 = std::find(people[person2].begin(), people[person2].end(), person1);

			if (it1 != people[person1].end())
			{
				people[person1].erase(it1);
				people[person2].erase(it2);
			}
		}
		else if (input == "n")
		{
			int person;
			std::cin >> person;

			std::cout << people[person].size() << std::endl;
		}
		else if (input == "f")
		{
			int person;
			std::cin >> person;

			std::vector<int> friends;

			for (auto it = people[person].begin(); it != people[person].end(); ++it)
			{
				for (auto it2 = people[*it].begin(); it2 != people[*it].end(); ++it2)
				{
					auto found1 = std::find(people[person].begin(), people[person].end(), *it2);
					auto found2 = std::find(friends.begin(), friends.end(), *it2);

					if (found1 == people[person].end() && found2 == friends.end() && *it2 != person)
					{
						friends.push_back(*it2);
					}
				}
			}

			std::cout << friends.size() << std::endl;
		}
		else if (input == "s")
		{
			bool visited[51] = { false };
			int previous[51];
			std::queue<int> q;

			int start, end;
			std::cin >> start;
			std::cin >> end;

			q.push(start);
			visited[start] = true;
			previous[start] = -1;

			bool found = false;

			while (!q.empty() && !found)
			{
				int person = q.front();
				q.pop();

				for (auto frd = people[person].begin(); frd != people[person].end(); ++frd)
				{
					if (!visited[*frd])
					{
						previous[*frd] = person;
						visited[*frd] = true;
						q.push(*frd);

						if (*frd == end)
						{
							found = true;
							break;
						}
					}
				}
			}

			if (!found)
			{
				std::cout << "Not connected" << std::endl;
				continue;
			}

			int length = 0;
			int current = end;

			while (current != -1)
			{				
				current = previous[current];
				length++;
			}

			std::cout << length - 1 << std::endl;
		}
		else if (input == "q")
		{
			break;
		}
	}
	
	return 0;
}
*/