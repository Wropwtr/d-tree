#include "plenty.h"

void plenty::makeSingle(int i) {
	if (i < 0 || i > size - 1)
		throw "Index out of bounds";
	p[i] = i;
}

void plenty::unite(int i, int j) {
	if (i<0 || i>size - 1 || j<0 || j>size - 1)
		throw "Index out of bounds";
	p[getPlenty(i)] = getPlenty(j);
}

int plenty::getPlenty(int i) {
	int count = 0;
	while (p[i] != i){
		i = p[i];
		count++;
	}
	return i;
}