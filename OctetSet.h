#pragma once
#ifndef OctetSet_Class
#define OctetSet_Class
#include "Arraybits.h"
class OctetSet
{
	int size;
	Arraybtis* arraybits;
public:
	OctetSet(int);
	OctetSet(const OctetSet& copy);
	OctetSet(const OctetSet&& move);
	bool check(int);
	void add(int);
	void remove(int);
	void Print();
	~OctetSet();
};
#endif

