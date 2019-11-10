#pragma once
#ifndef _Arraybtis
#define _Arraybtis
#include <cstdint>

class Arraybtis
{
	uint8_t *bits;
	size_t  size;
public:
	Arraybtis(int);
	Arraybtis(const Arraybtis&);
	Arraybtis(const Arraybtis&&);
	bool check(int);
	void add(int);
	void remove(int);
	void setElements(const uint8_t*, int);
	uint8_t* getBits();
	size_t getSize();
	void Print();
	~Arraybtis();
};

#endif


