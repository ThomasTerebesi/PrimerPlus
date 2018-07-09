#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <list>

template<typename T>
T average_list(const std::initializer_list<T>& list)
{
	T result = 0;
	for (T entry : list)
		result += entry;

	result /= list.size();

	return result;
}

int main()
{
	using namespace std;
	// list of double deduced from list contents
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;
	// list of int deduced from list contents
	cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;
	// forced list of double
	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << endl;

	cin.get();

	return 0;
}