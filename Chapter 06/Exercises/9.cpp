#include <iostream>
#include <string>
#include <fstream>


const double THRESHOLD = 10000.0;


struct Contribution
{
	std::string name = "";
	double contributionAmount = 0.0;
};


int main()
{
	std::cout << "Contribution tracker for the Society for the Preservation of Rightful Influence" << std::endl;
	
	std::string filename;
	std::ifstream inFile;


	std::cout << "Enter a name of a file containing contribution data: ";
	std::cin >> filename;


	inFile.open(filename);
	if (!inFile.is_open())
	{
		std::cout << "Could not open the file " << filename << std::endl;
		std::cout << "Program terminating." << std::endl;

		std::cin.get();

		exit(EXIT_FAILURE);
	}


	unsigned short contributorNumber;
	inFile >> contributorNumber;
	inFile.get();


	Contribution* contributions = new Contribution[contributorNumber];


	for (int i = 0; i < contributorNumber; i++)
	{
		getline(inFile, contributions[i].name);
		inFile >> contributions[i].contributionAmount;

		inFile.get();
	}


	if (inFile.eof())
	{
		std::cout << "\nEnd of file reached." << std::endl;
	}
	else if (inFile.fail())
		std::cout << "Input terminated by data mismatch." << std::endl;
	else
		std::cout << "Input terminated for unknown reason." << std::endl;

	inFile.close();


	std::cout.precision(2);

	// GRAND PATRONS WITH CONTRIBUTIONS GREATER THAN THRESHOLD'S VALUE
	bool contributionWasMade = false;

	std::cout << "\n\nGrand Patrons" << std::endl;
	std::cout << "=============" << std::endl;

	for (int i = 0; i < contributorNumber; i++)
	{
		if (contributions[i].contributionAmount > THRESHOLD)
		{
			contributionWasMade = true;
			std::cout << contributions[i].name << " - $" << std::fixed << contributions[i].contributionAmount << std::endl;
		}
	}

	if (!contributionWasMade)
		std::cout << "None." << std::endl;


	// PATRONS WITH CONTRIBUTIONS SMALLER THAN THRESHOLD'S VALUE
	contributionWasMade = false; // reuse variable

	std::cout << "\n\nPatrons" << std::endl;
	std::cout << "=======" << std::endl;

	for (int i = 0; i < contributorNumber; i++)
	{
		if (contributions[i].contributionAmount <= THRESHOLD)
		{
			contributionWasMade = true;
			std::cout << contributions[i].name << " - $" << std::fixed << contributions[i].contributionAmount << std::endl;
		}
	}

	if (!contributionWasMade)
		std::cout << "None." << std::endl;


	std::cin.get();
	std::cin.get();

	delete[] contributions;

	return 0;
}