#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

// NO COMMAND ARGUMENTS

template <typename T>
void OpenFile(T & file, const std::string fileName);

int main()
{
	std::vector<std::string> matGuests;
	std::vector<std::string> patGuests;
	std::vector<std::string> combinedGuests;

	// open source files
	std::ifstream matIn;
	OpenFile(matIn, "mat.dat");
	std::ifstream patIn;
	OpenFile(patIn, "pat.dat");

	//
	std::string guest;

	while (getline(matIn, guest) && guest != "")
		matGuests.push_back(guest);

	if (matGuests.size() > 0)
	{
		if (matGuests.size() == 1)
		{
			std::cout << "\nMat's only guest:" << std::endl;
			std::cout << "\t" << matGuests[0] << std::endl;
		}
		else
		{
			std::cout << "\nMat's guest list (" << matGuests.size() << " entries):" << std::endl;
			for (auto entry : matGuests)
				std::cout << "\t" << entry << std::endl;
		}
	}
	else
		std::cout << "\nMat's guest list is empty." << std::endl;

	while (getline(patIn, guest) && guest != "")
		patGuests.push_back(guest);

	if (patGuests.size() > 0)
	{
		if (patGuests.size() == 1)
		{
			std::cout << "\nPat's only guest:" << std::endl;
			std::cout << "\t" << patGuests[0] << std::endl;
		}
		else
		{
			std::cout << "\nPat's guest list (" << patGuests.size() << " entries):" << std::endl;
			for (auto entry : patGuests)
				std::cout << "\t" << entry << std::endl;
		}
	}
	else
		std::cout << "\nPat's guest list is empty." << std::endl;

	// insert vectors' contents into the result vector, sort it and display its contents
	combinedGuests.reserve(matGuests.size() + patGuests.size());
	combinedGuests.insert(combinedGuests.end(), matGuests.begin(), matGuests.end());
	combinedGuests.insert(combinedGuests.end(), patGuests.begin(), patGuests.end());
	std::sort(combinedGuests.begin(), combinedGuests.end());

	
	if (combinedGuests.size() > 0)
	{
		if (combinedGuests.size() == 1)
		{
			std::cout << "\nThe only entry on the combined guest list:" << std::endl;
			std::cout << "\t" << combinedGuests[0] << std::endl;
		}
		else
		{
			std::cout << "\nCombined guest list (" << combinedGuests.size() << " entries):" << std::endl;
			for (auto entry : combinedGuests)
				std::cout << "\t" << entry << std::endl;
		}

		// if the combined guest list has any contents, open the destination file and write to it
		std::ofstream fout;
		std::cout << std::endl;
		OpenFile(fout, "matnpat.dat");

		for (auto entry : combinedGuests)
		{
			fout << entry << std::endl;
		}

		fout.close();
	}
	else
		std::cout << "\nThe combined guest list is empty." << std::endl;

	// cleanup and exit
	matIn.close();
	patIn.close();

	std::cout << "Operation successful: Combined guest list was saved in 'matnpat.dat'." << std::endl;

	std::cin.get();

	return 0;
}

template<typename T>
void OpenFile(T & file, const std::string fileName)
{
	std::cout << "Opening file '" << fileName << "'... ";
	file.open(fileName);

	if (!file.is_open())
	{
		std::cerr << "\n\aCould not open '" << fileName << "'. Execution terminated." << std::endl;
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	std::cout << "Done." << std::endl;
}
