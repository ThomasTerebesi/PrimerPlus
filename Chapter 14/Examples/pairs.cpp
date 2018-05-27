#include <iostream>
#include <string>

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & First();
	T2 & Second();
	T1 First() const { return a; }
	T2 Second() const { return b; }
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
	Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1, T2>::First()
{
	return a;
}

template<class T1, class T2>
T2 & Pair<T1, T2>::Second()
{
	return b;
}

int main()
{
	Pair<std::string, int> ratings[4] = {
		Pair<std::string, int>("The Purpled Duck", 5),
		Pair<std::string, int>("Jaquie's Firsco Al Fresco", 4),
		Pair<std::string, int>("Cafe Souffle", 5),
		Pair<std::string, int>("Bertie's Eats", 3)
	};

	short joints = sizeof(ratings) / sizeof(Pair<std::string, int>);
	
	std::cout << "Rating:\tEatery" << std::endl;

	for (int i = 0; i < joints; i++)
		std::cout << ratings[i].Second() << ":\t" << ratings[i].First() << std::endl;

	std::cout << "Oops! Revised rating:" << std::endl;

	ratings[3].First() = "Bertie's Fab Eats";
	ratings[3].Second() = 6;

	std::cout << ratings[3].Second() << ":\t" << ratings[3].First() << std::endl;

	std::cin.get();

	return 0;
}
