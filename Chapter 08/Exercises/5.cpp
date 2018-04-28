#include <iostream>

const int ARRAY_SIZE = 5;

template<typename T>
T Max5(T arr[ARRAY_SIZE])
{
	T largest = arr[0];

	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}

	return largest;
}

int main()
{
	int intArr[ARRAY_SIZE] = { 12, 69, 98, 33, 420 };
	double doubleArr[ARRAY_SIZE] = { 43.24, 56.1, 19.73, 25.3, 90.11 };
	
	std::cout << "Max5(intArr) = " << Max5(intArr) << std::endl;
	std::cout << "Max5(doubleArr) = " << Max5(doubleArr) << std::endl;

	std::cin.get();

	return 0;
}