#include <iostream>

const int ARRAY_SIZE = 8;

int sumArr(int arr[], int n);

int main()
{
	int cookies[ARRAY_SIZE] = { 1, 2, 4, 8, 16, 32, 64, 128 };

	

	std::cout << cookies << " = array address, " << sizeof(cookies) << " = sizeof(cookies)" << std::endl;

	int sum = sumArr(cookies, ARRAY_SIZE); 
	std::cout << "Total cookies eaten: " << sum << std::endl;

	sum = sumArr(cookies, 3); // a lie
	std::cout << "First three eaters ate " << sum << " cookies." << std::endl;

	sum = sumArr(cookies + 4, 4); // another lie
	std::cout << "Last four eaters ate " << sum << " cookies." << std::endl;

	std::cin.get();

	return 0;
}

// return the sum of an integer array
int sumArr(int arr[], int n)
{
	int total = 0;

	std::cout << arr << " = arr, ";
	std::cout << sizeof(arr) << " = sizeof(arr)" << std::endl;

	for (int i = 0; i < n; i++)
		total = total + arr[i]; 

	return total;
}