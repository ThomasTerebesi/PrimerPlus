#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long SIZE = 390000L;

int main()
{
	std::vector<int> numbers(SIZE);

	srand(static_cast<int>(time(0)));

	std::generate(numbers.begin(), numbers.end(), rand);

	std::cout << "Sample size = " << SIZE << std::endl;

	// USING LAMBDAS
	std::cout << "\nUSING LAMBDAS:" << std::endl;
	int count3 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 3 == 0; });
	std::cout << "Count of numbers divisible by 3: " << count3 << '\n';

	int count13 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 13 == 0; });
	std::cout << "Count of numbers divisible by 13: " << count13 << '\n';


	// USING A SINGLE LAMBDA
	std::cout << "\nUSING A SINGLE LAMBDA:" << std::endl;
	count3 = count13 = 0;

	std::for_each(numbers.begin(), numbers.end(),
		[&](int x) { count3 += x % 3 == 0; count13 += x % 13 == 0; });

	std::cout << "Count of numbers divisible by 3: " << count3 << '\n';
	std::cout << "Count of numbers divisible by 13: " << count13 << '\n';

	std::cin.get();

	return 0;
}