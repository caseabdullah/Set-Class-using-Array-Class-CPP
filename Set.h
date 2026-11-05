#include "Array.h"
#ifndef SET_H
#define SET_H
class Set
{
	int capacity;
	int numberOfEelements;
	Array elements;

public:
	Set(int i=0);
	Set(const Set&);
	~Set();
	bool isFull();
	bool isEmpty();
	int searchElementPos(int elem);
	bool searchElement(int elem);
	bool addElement(int elem);
	bool removeElement(int elem);
	void displaySet();
	bool isSubset(Set b);
	void displayCrossProduct(Set b);
	Set calcUnion(Set b);
	Set calcIntersection(Set b);
	Set calcDifference(Set b);
};

#endif