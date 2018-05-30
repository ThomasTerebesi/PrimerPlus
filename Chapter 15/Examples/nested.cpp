// copmpile with queuetp.h

#include <iostream>
#include <string>
#include "queuetp.h"

int main()
{
	QueueTP<std::string> cs(5);
	std::string temp;

	while (!cs.IsFull())
	{
		std::cout << "Please enter your name. You will be served in the order of arrival." << std::endl;
		std::cout << "Name: ";
		getline(std::cin, temp);
		cs.Enqueue(temp);
	}

	std::cout << "The queue is full. Processing begins." << std::endl;

	while (!cs.IsEmpty())
	{
		cs.Dequeue(temp);
		std::cout << "Now processing " << temp << "..." << std::endl;
	}

	std::cin.get();

	return 0;
}