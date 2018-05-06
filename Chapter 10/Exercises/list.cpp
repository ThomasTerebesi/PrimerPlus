#include <iostream>
#include "list.h"

List::List()
	: count(0)
{
}

void List::Add(const Item & item)
{
	items[count] = item;
	count++;
}

void List::Visit(void(*pf)(Item &item))
{
	for (int i = 0; i < count; i++)
		pf(items[i]);
}

void List::PrintList() const
{
	for (int i = 0; i < count; i++)
		std::cout << "ITEM #" << (i + 1) << ": " << items[i] << std::endl;
}
