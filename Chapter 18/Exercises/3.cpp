#include <iostream>


// definition for 1 parameter
template<typename T>
long double sum_values(const T & value)
{
	return static_cast<long double>(value);
}

// definition for 2 or more parameters
template<typename T, typename... Args>
long double sum_values(const T & value, const Args &... args)
{
	return static_cast<long double>(value) + sum_values(args...);
}

int main()
{
	std::cout << sum_values(23.1, 2, 44.375, 'X', 'd', 11.1) << std::endl;
	std::cout << sum_values(2, 3, 1) << std::endl;

	std::cin.get();

	return 0;
}
