#include <iostream>

void swap (int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}

void insertSort (int arr[], int length, int interval) {

	int j;
	for (int i = interval; i < length; ++i) {

		j = i;
		while (arr[j] < arr[j-interval] && j >= interval) {
			swap(arr[j], arr[j-interval]);
			j -= interval;
		}
	}
}

void shellSort (int arr[], int length) {
	int interval = length / 2;


	while (interval >= 1) {
		insertSort(arr, length, interval);
		interval /= 2;
	}
}

void printArr(int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		std::cout << arr[i] << ' ';
	}
}