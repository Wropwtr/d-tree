#pragma once
#include <stdio.h>

template<class tData>
class tree{
	int d; // d-tree
	int size; // size of used elements of array
	int maxSize;
	tData **keys; 
public:
    tree( int maximumSize = 100, int dd = 2);
    tree(const tree<tData> &t);
	~tree() { delete []keys;}

	int minChild( int i ); // return index in array
	
	void swap( int i, int j );
	void up( int i );
	void down( int i );
	tData* deleteNode();
	void doHeap();
	void insert( tData *&key );
	int isEmpty() { return size <= 0; }

	//void print();
};

template<class tData>
tree<tData>::tree( int maximumSize, int dd ){
	if ( maximumSize <= 0 ) 
		throw "Bad size"; 

	d = dd;
	size = 0;
	maxSize = maximumSize;
	keys = new tData*[maxSize];
}

template<class tData>
tree<tData>::tree(const tree<tData> &t){
	if (keys == t.keys) 
		return;

	d = t.d;
	size = t.size;
	maxSize = t.maxSize;
	keys = new tData*[maxSize];
	for( int i = 0; i < size; i++)
		keys[i] = t.keys[i];
}

template<class tData>
void tree<tData>::swap( int i, int j){
	tData *buf = keys[i];
	keys[i] = keys[j];
	keys[j] = buf;
}

template<class tData>
void tree<tData>::up( int i ){
	int p = (i-1)/d;
	while( i > 0 ){		
		if ( *(keys[p]) < *(keys[i]) )
			break;
		swap(i, p);
		i = p;
		p = (i-1)/d;
	}
}

template<class tData>
int tree<tData>::minChild( int i ){
	int firstChild = i*d+1;
	if (firstChild >= size) 
		return -1;

	int lastChild = i*d+d;
	if (lastChild > size-1) lastChild = size-1;

	int minChildInd = firstChild;
	for( int i = firstChild; i <= lastChild; i++){
		if ( *(keys[i]) < *(keys[minChildInd]) )
			minChildInd = i;
	}
	return minChildInd;
}

template<class tData>
void tree<tData>::down( int i ){
	int c = minChild(i);
	while ( c!= -1 && *(keys[c]) < *(keys[i]) ){
		swap(i, c);
		i = c;
		c = minChild(i);
	}
}
template<class tData>
tData* tree<tData>::deleteNode(){
	if ( size == 0 )
		throw("Tree is empty");
	if ( size == 1){
		size--;
		return keys[0];
	}
	tData *result = keys[0];
	keys[0] = keys[size-1];
	size--;
	down(0);

	return result;
} // get element with minimum key(from root)

template<class tData>
void tree<tData>::doHeap(){
	int i = size-1;
	while ( i >= 0 ){
		down(i);
		i--;
	}
}

template<class tData>
void tree<tData>::insert(tData *&key){
	if ( size > maxSize - 1 )
		throw("Too many elements");

	size++;
	keys[size-1] = key;
	up(size-1);
}
