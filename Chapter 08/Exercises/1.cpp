#include <iostream>
#include <string>

void PrintString(const std::string & string, int n = 0);

int main()
{

	std::cout << "Enter a string for our silly function: ";
	std::string inputArgument;
	getline(std::cin, inputArgument);

	std::cout << "\nHow many times do you want to call PrintString? ";
	int callTimes;
	std::cin >> callTimes;

	std::cout << std::endl;

	if (callTimes > 0)
	{
		for (int i = 0; i < callTimes; i++)
			PrintString(inputArgument, i);
	}
	else
	{
		std::cout << "\nInvalid argument. Here are three calls of PrintString:" << std::endl;
		PrintString(inputArgument);
		PrintString(inputArgument);
		PrintString(inputArgument);
	}

	std::cout << "\nDone." << std::endl;

	std::cin.get();
	std::cin.get();

	return 0;
}

void PrintString(const std::string & string, int n)
{
	static int counter = 0;
	counter++;

	if (n == 0)
	{
		std::cout << "(Call #" << counter << ")\t" << string << std::endl;
		return;
	}

	std::cout << "(Call #" << counter << ")\t";

	for (int i = 0; i < counter; i++)
		std::cout << string << " ";

	std::cout << std::endl;
}
