#include <iostream>
#include <ctime>

const float firstTaxTier = 0.0f;
const float secondTaxTier = 0.1f;
const float thirdTaxTier = 0.15f;
const float fourthTaxTier = 0.2f;

const 

int main()
{
	float tvarpIncome = 0;
	float taxesToPay = 0.0;
	

	std::cout << "Enter an income in tvarps to see what you owe the Kingdom of Neutronia in taxes." << std::endl;
	std::cout << "Enter a negative value or a non-numeric character to quit.\n" << std::endl;
	std::cin >> tvarpIncome;

	while (!(std::cin.fail()) && tvarpIncome >= 0)
	{
		if (tvarpIncome >= 35000)
		{
			taxesToPay =
				5000 * firstTaxTier +
				10000 * secondTaxTier +
				20000 * thirdTaxTier +
				(tvarpIncome - 35000) * fourthTaxTier;
		}
		else if (tvarpIncome >= 15000)
		{
			taxesToPay =
				5000 * firstTaxTier +
				10000 * secondTaxTier +
				(tvarpIncome - 15000) * thirdTaxTier;
		}
		else if (tvarpIncome > 5000)
		{
			taxesToPay =
				5000 * firstTaxTier +
				(tvarpIncome - 5000) * secondTaxTier;
		}
		else
			taxesToPay = 0.0f;
		
		std::cout << "With an income of " << tvarpIncome << " you owe the Kingdom of Neutronia " << taxesToPay << " tvarps in taxes.\n" << std::endl;
		std::cout << "Enter another income: ";

		std::cin >> tvarpIncome;
	}

	std::cout << "Bye!" << std::endl;

	float seconds = 3.0;
	clock_t delay = static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	clock_t start = clock();
	while (clock() - start < delay)
		;

	return 0;
}