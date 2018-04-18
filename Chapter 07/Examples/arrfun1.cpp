#include <iostream>

const int ARRAY_SIZE = 8;

int sumArr(int arr[], int n);

int main()
{
	int cookies[ARRAY_SIZE] = { 1, 2, 4, 8, 16, 32, 64, 128 };

	int sum = sumArr(cookies, ARRAY_SIZE);
	
	std::cout << "Total cookies eaten: " << sum << std::endl;

	std::cin.get();

	return 0;
}

// return the sum of an integer array
int sumArr(int arr[], int n) // could also be int sumArr(int* arr, int n)
{
	int total = 0;

	for (int i = 0; i < n; i++)
		total = total + arr[i]; // arr[i] == *(arr + i) 

	return total;
}