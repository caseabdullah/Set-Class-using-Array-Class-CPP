#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(int cap):elements(cap)
{	
	if (cap<0)
		capacity = 0;
	else
		capacity = cap;

	numberOfEelements = 0;
}

Set::Set(const Set&b):capacity(b.capacity),numberOfEelements(b.numberOfEelements),elements(b.elements)
{
	//nothing
}

Set::~Set()
{
	numberOfEelements = 0;
	capacity = 0;
}

bool Set::isFull()
{
	return capacity==numberOfEelements?true:false;
}

bool Set::isEmpty()
{
	return numberOfEelements == 0 ? true : false;
}

int Set::searchElementPos(int elem)
{
	if (isEmpty())
	{
		return -1;
	}
	for (int i = 0; i < numberOfEelements; i++)
	{
		if (elements.getSet(i)==elem)
		{
			return i;
		}
	}
	return -1;
}

bool Set::searchElement(int elem)
{
	return searchElementPos(elem)==-1 ? false : true;
}

bool Set::addElement(int elem)
{
	if (isFull())
	{
		elements.resize((capacity * 2) + 1);
		capacity = elements.getsize();
	}
	if (searchElement(elem))
	{
		return false;
	}
	elements.getSet(numberOfEelements) = elem;
	numberOfEelements++;
	return true;
}

bool Set::removeElement(int elem)
{
	int pos = searchElementPos(elem);
	if (pos==-1)
	{
		return false;
	}
	elements.getSet(pos) = elements.getSet(numberOfEelements - 1);
	numberOfEelements--;
	return true;
}

void Set::displaySet()
{
	if (isEmpty())
	{
		cout << "{}" << endl;
	}
	else {
		cout << "{";
		for (int i = 0; i < numberOfEelements; i++)
		{
			cout << elements.getSet(i) ;
			if (!(i==numberOfEelements-1))
			{
				cout << ",";
			}
		}
		cout << "}"<< endl;
	}
}

bool Set::isSubset(Set b)
{
	if ((b.isEmpty()&&this->isEmpty()) || this->isEmpty())
	{
		return true;
	}
	if ((b.isEmpty()&& !this->isEmpty())||(numberOfEelements>b.numberOfEelements))
	{
		return false;
	}
	for (int i = 0; i < numberOfEelements; i++)
	{
		if (!b.searchElement(elements.getSet(i)))
		{
			return false;
		}
	}
	return true;
}

void Set::displayCrossProduct(Set b)
{	
	if (b.isEmpty()||this->isEmpty())
	{
		cout << "{}" << endl;
		return;
	}

	cout << "{";
	for (int i = 0; i < numberOfEelements; i++)
	{
		for (int j = 0; j < b.numberOfEelements; j++)
		{
			cout << "(" << elements.getSet(i) << "," << b.elements.getSet(j) << ")";
			if (!(i == numberOfEelements - 1&& j == b.numberOfEelements - 1))
			{
				cout << ",";
			}
		}
	}
	cout << "}" << endl;
}

Set Set::calcUnion(Set b)
{
	Set unionSet{ b.numberOfEelements + numberOfEelements };

	for (int i = 0; i < numberOfEelements; i++)
	{
		unionSet.addElement(elements.getSet(i));
	}
	for (int j = 0; j < b.numberOfEelements; j++)
	{
		unionSet.addElement(b.elements.getSet(j));
	}
	return unionSet;
}

Set Set::calcIntersection(Set b)
{
	Set intersectionSet{ (numberOfEelements > b.numberOfEelements) ? b.numberOfEelements : numberOfEelements };

	if (b.isEmpty() || this->isEmpty())
	{
		return intersectionSet;
	}

	for (int i = 0; i < numberOfEelements; i++)
	{
		if (b.searchElement(elements.getSet(i)))
		{
			intersectionSet.addElement(elements.getSet(i));
		}
	}
	return intersectionSet;
}

Set Set::calcDifference(Set b)
{
	Set differenceSet{capacity};
	if (isEmpty())
	{
		return differenceSet;
	}
	for (int i = 0; i < numberOfEelements; i++)
	{
		if (b.isEmpty() || !b.searchElement(elements.getSet(i)))
		{
			differenceSet.addElement(elements.getSet(i));
		}
	}
	return differenceSet;
}
