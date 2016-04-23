#include "plenty.h"

void plenty::makeSingle(int i) {
	if (i < 0 || i > size - 1)
		throw "Index out of bounds";
	p[i] = i;
}

void plenty::unite(int i, int j) {
	if (i<0 || i>size - 1 || j<0 || j>size - 1)
		throw "Index out of bounds";
	p[i] = j;
}

int plenty::getPlenty(int i) {
	while (p[i] != i)
		i = p[i];
	return i;
}