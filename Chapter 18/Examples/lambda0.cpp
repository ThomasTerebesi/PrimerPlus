#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long SIZE1 = 39L;
const long SIZE2 = 100 * SIZE1;
const long SIZE3 = 100 * SIZE2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main()
{
	std::vector<int> numbers(SIZE1);

	std::srand(static_cast<int>(time(0)));
	std::generate(numbers.begin(), numbers.end(), rand);
	std::cout << "Sample size = " << SIZE1 << '\n';

	// USING FUNCTION POINTERS
	int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	std::cout << "Count of numbers divisible by 3: " << count3 << '\n';

	int count13 = std::count_if(numbers.begin(), numbers.end(), f13);
	std::cout << "Count of numbers divisible by 13: " << count13 << '\n';


	// increase number of numbers
	numbers.resize(SIZE2);
	std::generate(numbers.begin(), numbers.end(), rand);
	std::cout << "\nSample size = " << SIZE2 << '\n';

	// USING A FUNCTOR
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) : dv(d) {}
		bool operator()(int x) { return x % dv == 0; }
	};

	count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
	std::cout << "Count of numbers divisible by 3: " << count3 << '\n';

	count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
	std::cout << "Count of numbers divisible by 13: " << count13 << '\n';


	// increase number of numbers again
	numbers.resize(SIZE3);
	std::generate(numbers.begin(), numbers.end(), rand);
	std::cout << "\nSample size = " << SIZE3 << '\n';


	// USING LAMBDAS
	count3 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 3 == 0; });
	std::cout << "Count of numbers divisible by 3: " << count3 << '\n';

	count13 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 13 == 0; });
	std::cout << "Count of numbers divisible by 13: " << count13 << '\n';

	std::cin.get();

	return 0;
}