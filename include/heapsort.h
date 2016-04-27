#pragma once
#include "tree.h"

template<class tData>
class heapsort{
public:
	static void sort(tData **&arr, int size, int d = 2);
	static void sort(tData *&arr, int size, int d = 2);
};

template<class tData>
void heapsort<tData>::sort(tData **&arr, int size, int d){
	if ( !arr || size <= 0 || d <= 0 ) 
		throw "Bad input";

	tree<tData> *t = new tree<tData>(size, d);
	for( int i = 0; i < size; i++){
		if( !arr[i] ){
			delete t;
			throw "Bad input data";
		}
		else{
			t->insert(arr[i]);
		}
	} // filling

	t->doHeap();
	for( int i = size-1; i >= 0; i--){
		t->swap(i, 0);
		t->down(0);
	} // heapsort

	for( int i = 0; i < size; i++)
		arr[i] = t->deleteNode();
	delete t;
}

template<class tData>
void heapsort<tData>::sort(tData *&arr, int size, int d){
	if(!arr) 
		throw "Bad input";

	tData **arr2 = new tData*[size];
	for( int i = 0; i < size; i++){
		arr2[i] = new int;
		*(arr2[i]) = arr[i];
	}

	sort(arr2, size, d);

	for( int i = 0; i < size; i++){
		arr[i] = *(arr2[i]);
		delete arr2[i];
	}
	delete []arr2;
} // because tree only working with array of pointers