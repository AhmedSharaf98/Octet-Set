#include "pch.h"
#include "Arraybits.h"
#include <iostream>


using namespace std;
Arraybtis::Arraybtis(int size_param = 256) : size(size_param) {
	size_param = size_param / 8 + ((size_param % 8) ? 1 : 0);
	bits = new uint8_t[size_param];
	for (int i = 0; i < size_param; i++) {
		bits[i] = 0;
	}
}

Arraybtis::Arraybtis(const Arraybtis& ArrayToCopy) : size(ArrayToCopy.size) {
	bits = new uint8_t[size / 8 + ((size % 8) ? 0 : 1)];
	for (int i = 0; i < size / 8 + ((size % 8) ? 0 : 1); i++) {
		bits[i] = ArrayToCopy.bits[i];
	}
}

Arraybtis::Arraybtis(const Arraybtis&& ArrayToMove) : size(ArrayToMove.size), bits(ArrayToMove.bits) {
}

uint8_t* Arraybtis::getBits() {
	return bits;
}

size_t Arraybtis::getSize() {
	return size;
}

void Arraybtis::setElements(const uint8_t* src, int src_size) {
	if (size != src_size) {
		size = src_size;
		delete[] bits;
		bits = new uint8_t[size];
	}
	for (int i = 0; i < size; i++) {
		bits[i] = src[i];
	}
}

bool Arraybtis::check(int pos)  {
	bool result = bool(bits[pos / 8] & ((1 << 8) >> (pos % 8)));
	return result;
}

void Arraybtis::add(int pos) {
	bits[pos / 8] = bits[pos / 8] | ((1 << 8) >> (pos % 8));
}

void Arraybtis::remove(int pos) {
	bits[pos / 8] = bits[pos / 8] & ((1 << 8) - 1) - (128 >> (pos % 8));
}

void Arraybtis::Print() {
	for (int i = 0; i < size; ++i) {
		if (i % 8 == 0 && i) cout << ' ';
		cout << (check(i) ? '1' : '0');
	}
	cout << endl;
}


Arraybtis::~Arraybtis(){
	delete[] bits;
}
