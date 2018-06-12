#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iomanip>

struct Review
{
	std::string title;
	int rating;
	float price;
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool WorseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool CheaperThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool FillReview(Review & rr);
void ShowReview(const std::shared_ptr<Review> & rp);
void DisplayOptions();

int main()
{
	std::vector<std::shared_ptr<Review>> books;
	Review temp;

	while (FillReview(temp))
	{
		std::cout << std::endl;
		books.push_back(std::shared_ptr<Review>(new Review(temp)));
	}

	int num = books.size();

	if (num == 0)
		std::cout << "\nNo entries." << std::endl;
	else if (num == 1)
	{
		std::cout << "\nYou have one entry:" << std::endl;
		std::cout << "Rating\tPrice\tTitle" << std::endl;
	}
	if (num > 1)
	{
		std::cout << "\nThank you. You entered the " << books.size() << " reviews." << std::endl;
		DisplayOptions();

		// new vector with entries sorted alphabetically
		std::vector<std::shared_ptr<Review>> booksAlphabetical(books.begin(), books.end());
		sort(booksAlphabetical.begin(), booksAlphabetical.end());

		// new vector with entries sorted in order of increasing ratings
		std::vector<std::shared_ptr<Review>> booksRatings(books.begin(), books.end());
		sort(booksRatings.begin(), booksRatings.end(), WorseThan);

		// new vector with entries sorted in order of increasing prices
		std::vector<std::shared_ptr<Review>> booksPrices(books.begin(), books.end());
		sort(booksPrices.begin(), booksPrices.end(), CheaperThan);

		short choice;

		while (std::cin >> choice)
		{
			switch (choice)
			{
			case 1:	// original order
				std::cout << "\nRating\tPrice\tTitle" << std::endl;
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 2:	// alphabetical order
				std::cout << "\nRating\tPrice\tTitle" << std::endl;
				for_each(booksAlphabetical.begin(), booksAlphabetical.end(), ShowReview);
				break;
			case 3: // order of increasing ratings
				std::cout << "\nRating\tPrice\tTitle" << std::endl;
				for_each(booksRatings.begin(), booksRatings.end(), ShowReview);
				break;
			case 4:	// order of decreasing ratings
				std::cout << "\nRating\tPrice\tTitle" << std::endl;
				for_each(booksRatings.rbegin(), booksRatings.rend(), ShowReview);
				break;
			case 5:	// order of increasing prices
				std::cout << "\nRating\tPrice\tTitle" << std::endl;
				for_each(booksPrices.begin(), booksPrices.end(), ShowReview);
				break;
			case 6: // order of decreasing prices
				std::cout << "\nRating\tPrice\tTitle" << std::endl;
				for_each(booksPrices.rbegin(), booksPrices.rend(), ShowReview);
				break;
			default:
				std::cout << "Invalid input." << std::endl;
				break;
			}

			DisplayOptions();
		}
	}

	std::cin.get();
	std::cin.get();

	return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool WorseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool CheaperThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
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

	std::cout << "Enter book price: ";
	std::cin >> rr.price;

	if (!std::cin)
		return false;

	// get rest of input line
	while (std::cin.get() != '\n')
		continue;

	return true;
}

void ShowReview(const std::shared_ptr<Review> & rp)
{
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << rp->rating << "\t" << rp->price << "\t" << rp->title << std::endl;
}

void DisplayOptions()
{
	std::cout << "\nDisplay options ('q' to quit):" << std::endl;
	std::cout << "\t1 - Original order" << std::endl;
	std::cout << "\t2 - Alphabetical order" << std::endl;
	std::cout << "\t3 - Order of increasing ratings" << std::endl;
	std::cout << "\t4 - Order of decreasing ratings" << std::endl;
	std::cout << "\t5 - Order of increasing prices" << std::endl;
	std::cout << "\t6 - Order of decreasing prices" << std::endl;

	std::cout << "\n>> ";
}