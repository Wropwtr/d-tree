#pragma once
#include "tree.h"

template<class tData>
class queue{
protected:
	tree<tData> *t;
public:
	queue( int maximumSize = 100, int d = 2 );
	queue(tree<tData> tr) { t = new tree<tData>(tr); }
	queue(const queue<tData> &q) { t = new tree<tData>(*q.t); }
	~queue() { delete t;}
	
	tData* getTop();
	void insert(tData *&key);
	int isEmpty() { return t->isEmpty(); }
	void rebalance() { t->doHeap(); }
};

template<class tData>
queue<tData>::queue( int maximumSize, int d){
	t = new tree<tData>( maximumSize, d);
}

template<class tData>
tData* queue<tData>::getTop(){
	tData *top = 0;
	try{
		top = t->deleteNode();
	}catch(...){
		throw("Queue is empty\n");
	}
	return top;
}

template<class tData>
void queue<tData>::insert(tData *&key){
	try{
		t->insert(key);
	}catch(...){
		throw("Queue is full\n");
	}
	return;
}