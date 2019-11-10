#include "pch.h"
#include "OctetSet.h"


OctetSet::OctetSet(int size_param = 256) : size(size_param)
{
	arraybits = new Arraybtis(size_param);
}

OctetSet::OctetSet(const OctetSet& ToCopy) : size(ToCopy.size) {
	arraybits->setElements(ToCopy.arraybits->getBits(), ToCopy.arraybits->getSize());
}
OctetSet::OctetSet(const OctetSet&& move) : size(move.size), arraybits(move.arraybits) {
}
void OctetSet::remove(int pos) {
	arraybits->remove(pos);
}

void OctetSet::add(int pos) {
	arraybits->add(pos);
}

bool OctetSet::check(int pos) {
	return arraybits->check(pos);
}

void OctetSet::Print() {
	arraybits->Print();
}

OctetSet::~OctetSet()
{
	delete arraybits;
}
