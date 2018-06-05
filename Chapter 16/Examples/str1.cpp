#include <iostream>
#include <string>

int main()
{
	std::string one("Lottery Winner!");		// ctor #1
	std::cout << one << std::endl;			// overloaded <<

	std::string two(20, '$');				// ctor #2
	std::cout << two << std::endl;

	std::string three(one);					// ctor #3
	std::cout << three << std::endl;

	one += " Oops!";						// overloaded +=
	std::cout << one << std::endl;

	two = "Sorry! That was ";
	three[0] = 'P';

	std::string four;						// ctor #4
	four = two + three;
	std::cout << four << std::endl;
	
	char alls[] = "All's well that ends well";
	
	std::string five(alls, 20);				// ctor #5
	std::cout << five << "!\n";

	std::string six(alls + 6, alls + 10);	// ctor #6
	std::cout << six << ", ";

	std::string seven(&five[6], &five[10]);	// ctor #6 again
	std::cout << seven << "...\n";

	std::string eight(four, 7, 16);			// ctor #7
	std::cout << eight << " in motion!" << std::endl;

	std::cin.get();

	return 0;
}