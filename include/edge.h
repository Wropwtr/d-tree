//typedef int weightData;
#pragma once
#include <iostream>
using namespace std;

template<class weightData>
class edge{
public:
	weightData w;
	int s;
	int e;

	edge(int start, int end, weightData weight);
	edge(){ w = 0; s = 0; e = 0; }

	int operator <( edge<weightData> e ) { return w < e.w; }
	int operator >( edge<weightData> e ) { return w > e.w; }
	int operator ==( edge<weightData> e ) { return e.w == w; }
	int operator <=( edge<weightData> e ) { return w <= e.w; }

	void printEdge();
};

template<class weightData>
edge<weightData>::edge(int start, int end, weightData weight){
	s = start;
	e = end;
	w = weight;
}

template<class weightData>
void edge<weightData>::printEdge(){
	cout << s << " - " << e << " , weight = " << w << endl;
}