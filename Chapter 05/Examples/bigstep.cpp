#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter an integer: ";
	int by;
	cin >> by;
	cout << "Counting by " << by << "s:\n";
	for (int i = by; i <= (10 * by); i = i + by)
		cout << i << endl;
	
	cin.get();
	cin.get();
	return 0;
}