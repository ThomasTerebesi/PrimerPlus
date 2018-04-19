#include <iostream>

const int LEN = 66;
const int DIVS = 6;

void Subdivide(char ar[], int low, int high, int level);

int main()
{
	char ruler[LEN];
	int i;

	for (i = 1; i < LEN - 2; i++)
		ruler[i] = ' ';

	ruler[LEN - 1] = '\0';

	int max = LEN - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';

	std::cout << ruler << std::endl;

	for (i = 1; i <= DIVS; i++)
	{
		Subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < LEN - 2; j++)
			ruler[j] = ' ';
	}

	std::cin.get();
	
	return 0;
}

void Subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;

	int mid = (high + low) / 2;

	ar[mid] = '|';
	Subdivide(ar, low, mid, level - 1);
	Subdivide(ar, mid, high, level - 1);
}
