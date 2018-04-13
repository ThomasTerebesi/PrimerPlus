#include <iostream>

int main()
{
	using std::cin;
	using std::cout;

	char ch;
	int spaces = 0;
	int total = 0;

	cin.get(ch);
	while (ch != '.')
	{
		if (ch == ' ')
			++spaces;
		++total;
		cin.get(ch);
	}

	cout << spaces << " spaces, " << total << " characters total in sentence\n";

	cin.get();
	cin.get();
	return 0;
}