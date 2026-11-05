#include "Array.h"
#include <stdlib.h>

bool Array::isValidIndex(int index)
{
	return index >= 0 && index < capacity ? true : false;
}

Array::Array(int cap)
{
	if (cap <= 0)
	{
		capacity = 0;
		data = nullptr;
		return;
	}
	capacity = cap;
	data = new int[capacity];
}

Array::~Array()
{
	delete[]data;
	data = nullptr;
	capacity = 0;
}

Array::Array(const Array& deepCopy) :Array()
{
	if (deepCopy.data == nullptr) {
		return;
	}
	resize(deepCopy.capacity);
	//capacity = deepCopy.capacity; resize funtion does that
	for (int i = 0; i < deepCopy.capacity; i++)
	{
		data[i] = deepCopy.data[i];
	}

}

int Array::getsize()
{
	return capacity;
}

int& Array::getSet(int index)
{
	if (!isValidIndex(index)) {
		exit(0);
	}
	return data[index];
}

void Array::resize(int newCapacity)
{
	if (newCapacity <= 0) {
		delete[]data;
		data = nullptr;
		capacity = 0;
		return;
	}
	int* temp = new int[newCapacity];
	for (int i = 0; i < (capacity < newCapacity ? capacity : newCapacity); i++)
	{
		temp[i] = data[i];
	}
	this->~Array();
	capacity = newCapacity;
	data = temp;
}