#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 80;

int main()
{
	char filename[SIZE];
	std::ifstream inFile;

	std::cout << "Enter a name of a data file: ";
	std::cin.getline(filename, SIZE);
	
	inFile.open(filename);	// associate inFile with a file
	if (!inFile.is_open())	// failed to open the file
	{
		std::cout << "Could not open the file " << filename << std::endl;
		std::cout << "Program terminating." << std::endl;
		
		std::cin.get();

		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())	// can be replaced by (inFile >> value)
	{
		++count;
		sum += value;
		inFile >> value;	// can be omitted if condition above is replaced
	}

	if (inFile.eof())
	{
		// while loop above quits before count and sum are updated one last time
		++count;
		sum += value;
		std::cout << "End of file reached." << std::endl;
	}
	else if (inFile.fail())
		std::cout << "Input terminated by data mismatch." << std::endl;
	else
		std::cout << "Input terminated for unknown reason." << std::endl;

	if (count == 0)
		std::cout << "No data processed." << std::endl;
	else
	{
		std::cout << "Items read: " << count << std::endl;
		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Average: " << sum / count << std::endl;
	}

	inFile.close();

	std::cin.get();
	
	return 0;
}