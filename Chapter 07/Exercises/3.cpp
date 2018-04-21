#include <iostream>

struct Box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

Box CreateBox();
void DisplayBoxValues(Box b);
void CalculateBoxVolume(Box* b);

int main()
{
	Box myBox = CreateBox();
	DisplayBoxValues(myBox);

	std::cin.get();
	std::cin.get();

	return 0;
}

Box CreateBox()
{
	Box newBox;
	
	std::cout << "Enter name of the manufacturer: ";
	std::cin >> newBox.maker;

	std::cout << "Enter box height: ";
	std::cin >> newBox.height;

	std::cout << "Enter box width: ";
	std::cin >> newBox.width;

	std::cout << "Enter box length: ";
	std::cin >> newBox.length;

	CalculateBoxVolume(&newBox);

	return newBox;
}

void DisplayBoxValues(Box b)
{
	std::cout << "\nManufacturer name: " << b.maker << std::endl;
	std::cout << "Height: " << b.height << std::endl;
	std::cout << "Width: " << b.width << std::endl;
	std::cout << "Length: " << b.length << std::endl;
	std::cout << "Volume: " << b.volume << std::endl;
}

void CalculateBoxVolume(Box * b)
{
	b->volume = b->height * b->width * b->length;
}
