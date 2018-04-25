#include <iostream>
#include <string>

std::string Version1(const std::string & s1, const std::string & s2);
const std::string & Version2(std::string & s1, const std::string & s2);
const std::string & Version3(std::string & s1, const std::string & s2);

int main()
{
	std::string input;
	std::string copy;
	std::string result;

	std::cout << "Enter a string: ";
	getline(std::cin, input);
	copy = input;

	std::cout << "Your string as entered: " << input << std::endl;
	
	result = Version1(input, "***");
	std::cout << "Your string enhanced: " << result << std::endl;
	std::cout << "Your original string: " << input << std::endl;

	result = Version2(input, "###");
	std::cout << "Your string enhanced: " << result << std::endl;
	std::cout << "Your original string: " << input << std::endl;

	std::cout << "Resetting original string." << std::endl;
	input = copy;
	
	// this will crash
	result = Version3(input, "@@@"); // program tries to refer to memory that's no longer in use
	std::cout << "Your string enhanced: " << result << std::endl;
	std::cout << "Your original string: " << input << std::endl;

	std::cin.get();

	return 0;
}

std::string Version1(const std::string & s1, const std::string & s2)
{
	std::string temp;

	temp = s2 + s1 + s2;

	return temp;
}

const std::string & Version2(std::string & s1, const std::string & s2)
{
	s1 = s2 + s1 + s2;

	return s1;
}

const std::string & Version3(std::string & s1, const std::string & s2)
{
	std::string temp;

	temp = s2 + s1 + s2;

	// unsafe to return reference to local variable
	return temp;
}
