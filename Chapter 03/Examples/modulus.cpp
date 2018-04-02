#include <iostream>

int main()
{
	const int LbsPerStn = 14;
	int lbs;

	std::cout << "Enter your weight in pounds: ";
	std::cin >> lbs;
	int stone = lbs / LbsPerStn;
	int pounds = lbs % LbsPerStn;
	std::cout << lbs << " pounds are " << stone << " stone, " << pounds << " pound(s).\n";

	std::cin.get();
	std::cin.get();
	return 0;
}