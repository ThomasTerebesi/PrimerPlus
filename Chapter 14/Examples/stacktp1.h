#pragma once

template <class Type>
class Stack
{
private:
	enum { SIZE = 10 }; // default size
	int stacksize;
	Type * items; // holds stack items
	int top; // index for top stack item
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack & st);
	~Stack() { delete[] items; }
	bool IsEmpty() { return top == 0; }
	bool IsFull() { return top == stacksize; }
	bool Push(const Type & item); // add item to stack
	bool Pop(Type & item); // pop top into item
	Stack & operator=(const Stack & st);
};



template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0)
{
	items = new Type[stacksize];
}

template <class Type>
Stack<Type>::Stack(const Stack & st)
{
	stacksize = st.stacksize;
	top = st.top;

	items = new Type[stacksize];

	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template <class Type>
bool Stack<Type>::Push(const Type & item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Stack<Type>::Pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
	if (this == &st)
		return *this;

	delete[] items;

	stacksize = st.stacksize;
	top = st.top;

	items = new Type[stacksize];

	for (int i = 0; i < top; i++)
		items[i] = st.items[i];

	return *this;
}