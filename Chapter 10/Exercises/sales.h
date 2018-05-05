#pragma once

namespace SALES
{
	class Sales
	{
	private:
		const static int QUARTERS = 4;
		double sales[QUARTERS] = { 0, 0, 0, 0 };
		double average = 0;
		double max = 0;
		double min = 0;
	public:
		Sales();
		Sales(const double ar[], int n);
		void ShowSales() const;
	};
}