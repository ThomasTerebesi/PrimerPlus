#include <cstdlib> // for rand()
#include "5queue.h"

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random range value in the rang 1 - 3
void Customer::set(long when)
{
	processtime = rand() % 3 + 1;
	arrive = when;
}

Queue::Queue(int qs)
	: qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while (front != NULL)		// while queue is not yet empty
	{
		temp = front;			// save address of front item
		front = front->next;	// reset pointer to next imem
		delete temp;			// delete former front
	}
}

bool Queue::isEmpty() const
{
	return items == 0;
}

bool Queue::isFull() const
{
	return items == qsize;
}

int Queue::queueCount() const
{
	return items;
}

// add item to queue
bool Queue::enqueue(const Item & item)
{
	if (isFull())
		return false;
	
	Node * add = new Node;	// create node
	// on failure, new throws std::bad_alloc exception
	add->item = item;		// set node pointers
	add->next = nullptr;	// or nullptr
	items++;
	
	if (front == nullptr)	// if queue is empty
		front = add;		// place item at front
	else
		rear->next = add;	// else place at rear
	rear = add;				// have rear point to new node
	
	return true;
}

bool Queue::dequeue(Item & item)
{
	if (front == nullptr)
		return false;
	
	item = front->item;		// set item to first item in queue
	items--;
	Node * temp = front;	// save location of first item
	front = front->next;	// reset front to next item
	delete temp;			// delete former first item
	
	if (items == 0)
		rear = nullptr;
	
	return true;
}
