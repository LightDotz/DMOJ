/*
// https://dmoj.ca/problem/dpa
// i give up i dont want to re implement recursion or some other crap

#include <iostream>
#include <iterator>
#include <vector>
#include <string>

//int main() {
int dpa() {
	int stones;
	std::cin >> stones;

	std::string costsInput;
	std::vector<int> costs;

	std::cin.ignore(100, '\n');
	std::getline(std::cin, costsInput);

	for (int i = 0; i < costsInput.size(); ++i) {
		std::string currentNum;

		for (int j = i; j < costsInput.size(); ++j) {
			char chr = costsInput.at(j);

			if (chr == ' ')
			{
				break;
			}

			currentNum.push_back(chr);
		}

		int num = atoi(currentNum.c_str());

		if (num != 0)
		{
			costs.push_back(num);
		}
	}

	int currentPos = 0;
	int totalCost = 0;

	while (true) {
		int current = costs[currentPos];

		if (currentPos + 1 == stones - 1) { // if theres only one option to jump to
			totalCost += abs(current - costs[currentPos + 1]);
			break;
		}

		int option1 = costs[currentPos + 1];
		int option2 = costs[currentPos + 2];

		int cost1 = abs(current - option1);
		int cost2 = abs(current - option2);

		if (cost1 < cost2) {
			currentPos++;
			totalCost += cost1;
		}
		else {
			currentPos += 2;
			totalCost += cost2;
		}

		if (currentPos == stones - 1)
			break;
	}

	std::cout << totalCost << std::endl;

	return 0;
}
*/