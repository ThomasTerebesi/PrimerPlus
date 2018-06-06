#include <iostream>
#include <string>
#include <vector>

struct Review
{
	std::string title;
	int rating;
};

bool FillReview(Review &rr);
void ShowReview(const Review &rr);

int main()
{
	std::vector<Review> books;
	Review temp;

	while (FillReview(temp))
	{
		std::cout << std::endl;
		books.push_back(temp);
	}

	int num = books.size();

	if (num > 0)
	{
		std::cout << "\nThank you. You entered the following:" << std::endl;
		std::cout << "Rating\tBook" << std::endl;
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);

		std::cout << "\nReprising:" << std::endl;
		std::cout << "Rating\tBook" << std::endl;
		std::vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);

		std::vector<Review> oldList(books);	// copy constructor used

		if (num > 3)
		{
			// remove 2 items
			books.erase(books.begin() + 1, books.begin() + 3);
			std::cout << "\nAfter erasure:" << std::endl;
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);

			// insert 1 item
			books.insert(books.begin(), oldList.begin() + 1, oldList.begin() + 2);
			std::cout << "\nAfter insertion:" << std::endl;
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}

		books.swap(oldList);
		std::cout << "\nSwapping oldList with books:" << std::endl;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		std::cout << "\nNothing entered, nothing gained." << std::endl;

	std::cin.get();

	return 0;
}

bool FillReview(Review & rr)
{
	std::cout << "Enter book title (type 'quit' to quit): ";
	std::getline(std::cin, rr.title);
	
	if (rr.title == "quit")
		return false;
	
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;

	if (!std::cin)
		return false;

	// get rest of input line
	while (std::cin.get() != '\n')
		continue;

	return true;
}

void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}
