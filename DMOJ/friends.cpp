/*
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

int bfs(std::unordered_map<int, std::vector<int>> connections, int start, int end)
{
	std::queue<int> nextStudents;
	nextStudents.push(start);

	std::unordered_map<int, int> previous;
	std::unordered_map<int, bool> visited;

	visited[start] = true;

	bool found = false;
	
	while (!nextStudents.empty() && !found)
	{
		int student = nextStudents.front();
		nextStudents.pop();

		for (auto it = connections[student].begin(); it != connections[student].end(); ++it)
		{
			if (!visited[*it])
			{
				previous[*it] = student;
				visited[*it] = true;
				nextStudents.push(*it);

				if (*it == end)
				{
					found = true;
					break;
				}
			}
		}
	}

	if (!found)
	{
		return -1;
	}

	int length = 0;
	int current = end;

	while (true)
	{
		try
		{
			current = previous.at(current);
		}
		catch (const std::out_of_range& oor) { // reached start
			break;
		}

		length++;
	}

	return length - 1;
}

int main()
{
	std::unordered_map<int, std::vector<int>> connections;
	
	int students;
	std::cin >> students;

	for (int i = 0; i < students; i++)
	{
		int student1, student2;
		std::cin >> student1;
		std::cin >> student2;

		connections[student1].push_back(student2);
	}
	
	int student1, student2;

	while (true)
	{
		std::cin >> student1;
		std::cin >> student2;

		if (student1 == 0 && student2 == 0)
		{
			break;
		}

		int sep = bfs(connections, student1, student2);
		
		if (sep == -1)
		{
			std::cout << "No" << std::endl;;
		}
		else
		{
			std::cout << "Yes " << sep << std::endl;
		}
	}

	return 0;
}
*/