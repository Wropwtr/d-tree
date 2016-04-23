#pragma once

template <class weightType>
class mark{
public:
	int index; // for 1 peak
	weightType markWeight;

	mark() { index = 0; markWeight = -1;}
	mark(int i, weightType w);
	int operator <(const mark<weightType> &w) const
	{ 
		return markWeight < w.markWeight; 
	}
	int operator >(mark<weightType> w) { return markWeight > w.markWeight; }
	int operator ==(mark<weightType> w) { return w.markWeight == markWeight; }
	int operator <=(mark<weightType> w) { return markWeight <= w.markWeight; }
};

template<class weightType>
mark<weightType>::mark(int i, weightType w){
	index = i;
	markWeight = w;
}
