#include "4stack.h"

Stack::Stack(int n)
{
	top = 0;
}

Stack::Stack(const Stack & st)
{
	// TODO: Write copy constructor
}

Stack::~Stack()
{
	delete[] items;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

Stack & Stack::operator=(const Stack & st)
{
	// TODO: insert return statement here
}
