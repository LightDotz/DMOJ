/*
#include <iostream>
#include <cmath>

bool find(int mag, int x, int y)
{
	int sizeOfFifth = pow(5, mag - 1);
	int newX = (int) x / sizeOfFifth;
	int newY = (int) y / sizeOfFifth;

	//outside
	if (newX == 0 || newX == 4)
		return false;
	//orig four squares
	if (newY == 0)
	{
		if (newX == 1 || newX == 2 || newX == 3)
			return true;
	}
	if (newY == 1 && newX == 2)
		return true;
	//unsure, zoom in to the smaller subsection with new positions relative to small part using mod, as powers of 5
	if (((newX == 1 && newY == 1) || (newX == 2 && newY == 2) || (newX == 3 && newY == 1)) && mag != 1)
		return find(mag - 1, x % sizeOfFifth, y % sizeOfFifth);

	return false;
}

int main()
{
	int T;
	scanf("%i", &T);

	for (int i = 0; i < T; i++)
	{
		int mag, x, y;
		scanf("%i %i %i", &mag, &x, &y);
		bool found = find(mag, x, y);

		if (found)
			printf("crystal\n");
		else
			printf("empty\n");
	}
}
*/