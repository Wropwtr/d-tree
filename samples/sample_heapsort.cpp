#include "heapsort.h"
#include <iostream>

using namespace std;

int main(){
	int *arr = new int[10];
	for( int i = 0; i < 10; i++)
		arr[i] = 10-i;
	heapsort<int>::sort(arr,10);
	for( int i = 0; i < 10; i++)
		cout << arr[i] << endl;
	getchar();
	delete []arr;
	return 0;
}