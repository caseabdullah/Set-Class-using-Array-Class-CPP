#ifndef ARRAY_H
#define ARRAY_H

class Array
{
public:
	int* data;
	int capacity;
	bool isValidIndex(int index);
	Array(int = 0);
	~Array();
	Array(const Array&);
	int getsize();
	int& getSet(int index);
	void resize(int newCapacity);
};

#endif