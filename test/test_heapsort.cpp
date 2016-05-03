#include <gtest.h>
#include "heapsort.h"

TEST(Heapsort, throw_then_bad_input_1){
	int *arr = 0;
	ASSERT_ANY_THROW(heapsort<int>::sort(arr,10));
}

TEST(Heapsort, throw_then_bad_input_2){
	int *arr = new int[1];
	ASSERT_ANY_THROW(heapsort<int>::sort(arr,0));
	delete []arr;
}

TEST(Heapsort, can_sort_1_element){
	int **arr = new int*[1];
	arr[0] = new int;
	*(arr[0]) = 1;
	heapsort<int>::sort(arr,1);
	EXPECT_EQ(*(arr[0]), 1);
}
	
TEST(Heapsort, can_call_static_method_with_pointers){
	int **arr = new int*[10];
	for( int i = 0; i < 10; i++){
		arr[i] = new int;
		*(arr[i]) = 10-i;
	}
	heapsort<int>::sort(arr,10);
	
	EXPECT_EQ(*(arr[0]), 1);
	
	for( int i = 0; i < 10; i++)
		delete arr[i];
	delete []arr;
}

TEST(Heapsort, can_call_static_method_without_pointers){
	int *arr = new int[10];
	for( int i = 0; i < 10; i++)
		arr[i] = 10-i;
	heapsort<int>::sort(arr,10);
	
	EXPECT_EQ(arr[0], 1);
	
	delete []arr;
}

TEST(Heapsort, can_call_different_d){
	int *arr = new int[10];
	for (int i = 0; i < 10; i++)
		arr[i] = 10 - i;
	heapsort<int>::sort(arr, 10, 4);

	EXPECT_EQ(arr[0], 1);

	delete []arr;
}

TEST(Heapsort, sort_sorted_array){
	int *arr = new int[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	heapsort<int>::sort(arr, 10);

	EXPECT_EQ(arr[0], 0);

	delete []arr;
}

TEST(Heapsort, can_sort_1){
	int *arr = new int[10];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = 1;

	arr[3] = 4;
	arr[4] = 5;
	arr[5] = 6;

	arr[6] = 10;
	arr[7] = 9;
	arr[8] = 8;
	arr[9] = 7;

	heapsort<int>::sort(arr, 10);

	EXPECT_EQ(arr[0], 1);
}