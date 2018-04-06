#include <iostream>

struct AntarcticaYearsEnd
{
	int year;
};

int main()
{
	AntarcticaYearsEnd s01, s02, s03;
	s01.year = 1998;
	
	AntarcticaYearsEnd * pa = &s02;
	pa->year = 1999;
	
	AntarcticaYearsEnd trio[3];
	trio[0].year = 2003;
	std::cout << trio->year << std::endl;
	
	const AntarcticaYearsEnd * arp[3] = { &s01, &s02, &s03 };
	std::cout << arp[1]->year << std::endl;

	const AntarcticaYearsEnd ** ppa = arp; 
	auto ppb = arp; // const AntarcticaYearsEnd ** ppb = arp;
	std::cout << (*ppa)->year << std::endl;
	std::cout << (*(ppb + 1))->year << std::endl;

	std::cin.get();
	return 0;
}