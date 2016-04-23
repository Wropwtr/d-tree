#pragma once
#include<stdio.h>

class plenty{
	int *p;
public:
	int size;
	plenty(int n = 10 ){ p = new int[n]; size = n; }
	~plenty() { delete []p; }

	void makeSingle(int i);
	void unite(int i, int j);
	int getPlenty(int i);
};
