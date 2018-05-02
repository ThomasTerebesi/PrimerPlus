#pragma once

namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS] = { 0, 0, 0, 0 }; // initialize all elements to 0
		double average = 0;
		double max = 0;
		double min = 0;
	};
	
	
	// copies the lesser of 4 or n items from the array ar
	// to the sales member of s and computes and stores the
	// average, maximum, and minimum values of the entered items;
	// remaining elements of sales, if any, set to 0
	void setSales(Sales & s, const double ar[], int n);
	
	
	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minimum values
	void setSales(Sales & s);
	
	
	// display all information in structure s
	void showSales(const Sales & s);
}