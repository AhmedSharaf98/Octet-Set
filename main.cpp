#include "pch.h"
#include <iostream>
#include "OctetSet.h"
#include "Arraybits.h"

using namespace std;
int main(){
	OctetSet cs(36);
	cs.Print();
	cs.add(10);
	cs.Print();
	if (cs.check(10)) {
		cs.add(1);
	}
	cs.Print();
	cs.remove(10);
	cs.Print();
}
