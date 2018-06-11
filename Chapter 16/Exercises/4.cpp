#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

const short ARRAY_SIZE = 10;

int Reduce(long ar[], int n);
void RandomFillArray(long ar[], int n);
void ShowArray(long ar[], int n);

int main()
{
	srand(static_cast<int>(time(0)));

	long testArray1[ARRAY_SIZE];
	
	RandomFillArray(testArray1, ARRAY_SIZE);
	std::cout << "Contents of testArray1 after random fill:" << std::endl;
	ShowArray(testArray1, ARRAY_SIZE);

	int testArray1Size = Reduce(testArray1, ARRAY_SIZE);
	std::cout << "\nContents of testArray1 after sorting and removing duplicates:" << std::endl;
	ShowArray(testArray1, testArray1Size);
	std::cout << "\t\tSize of testArray1: " << testArray1Size << std::endl;

	long testArray2[ARRAY_SIZE] = { 7, 23, 94, 37, 92, 23, 65, 37, 7, 92 };

	std::cout << "\nContents of testArray2 after initialization:" << std::endl;
	ShowArray(testArray2, ARRAY_SIZE);

	int testArray2Size = Reduce(testArray2, ARRAY_SIZE);
	std::cout << "\nContents of testArray2 after sorting and removing duplicates:" << std::endl;
	ShowArray(testArray2, testArray2Size);
	std::cout << "\t\tSize of testArray2: " << testArray2Size << std::endl;

	std::cin.get();

	return 0;
}

int Reduce(long ar[], int n)
{
	std::sort(ar, ar + n);
	
	auto arrayEnd = std::unique(ar, ar + n);

	return arrayEnd - ar;
}

void RandomFillArray(long ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] = (rand() % 10) + 1;
}

void ShowArray(long ar[], int n)
{
	std::cout << "\t\t";
	for (int i = 0; i < n; i++)
		std::cout << ar[i] << "  ";
	std::cout << std::endl;
}
