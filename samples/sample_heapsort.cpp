#include "heapsort.h"
#include <iostream>

using namespace std;

int main(){
	int *arr = new int[10];
	arr[0] = 9;
	arr[1] = 8;
	arr[2] = 7;
	arr[3] = 0;

	arr[4] = 4;
	arr[5] = 5;
	arr[6] = 6;
	arr[7] = 2;

	arr[8] = 3;
	arr[9] = 1;
	/*for( int i = 0; i < 10; i++)
		arr[i] = 10-i;*/
	heapsort<int>::sort(arr,10);
	for( int i = 0; i < 10; i++)
		cout << arr[i] << endl;
	delete []arr;
	return 0;
}