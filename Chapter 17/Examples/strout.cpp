#include <iostream>
#include <sstream>
#include <string>

int main()
{
	std::ostringstream outstr;	// manages a string stream

	std::string hdisk;

	std::cout << "What's the name of your hard disk? ";
	getline(std::cin, hdisk);

	int cap;
	std::cout << "What's its capacity in gigabytes? ";
	std::cin >> cap;

	// write formatted information to string stream
	outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " gigabytes." << std::endl;

	std::string result = outstr.str();	// save result
	std::cout << result;				// show contents

	std::cin.get();
	std::cin.get();

	return 0;
}