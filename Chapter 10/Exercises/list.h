#pragma once

typedef double Item;

class List
{
private:
	const static unsigned short MAX_ITEMS = 8;
	Item items[MAX_ITEMS];
	unsigned short count;
public:
	List();
	void Add(const Item & item);
	bool IsEmpty() const { return count == 0 ? true : false; }
	bool IsFull() const { return count == MAX_ITEMS ? true : false; }
	int ItemCount() const { return count; }
	void Visit(void(*pf)(Item & item));
	void PrintList() const;
	unsigned short GetMaxItems() { return MAX_ITEMS; }
};