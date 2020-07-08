#include <iostream>
#include <cmath>
/*------------------------------------------------
				Linear Search
-------------------------------------------------*/
int linearSearch (int arr[], int length, int value) {

	if (arr[0] == value) {

		return 0;
	}

	for (int index = 1; index < length; ++index) {

		if (arr[index] == value) {

			return index;
		}
	}

	return -1;
}
/*------------------------------------------------
				Binary Search
-------------------------------------------------*/
int binarySearch (int arr[], int low, int high, int value) {

	int mid;
	int midElem;

	while (low <= high) {
		mid = (low + high) / 2;
		midElem = arr[mid];

		if (value == midElem) {
			return mid;
		}

		if (value > midElem) {
			return binarySearch(arr, mid + 1, high, value);
		}
		return binarySearch(arr, low, mid - 1, value);

	}

	return -1;
}

/*Version without recursion*/
int binarySearch2 (int arr[], int length, int value) {

	int low = 0;
	int high = length - 1;
	int mid;
	int midElem;

	while (low <= high) {
		mid = (low + high) / 2;
		midElem = arr[mid];

		if (value == midElem) {
			return mid;
		}

		if (value > midElem) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return -1;
}
/*------------------------------------------------
				Jump Search
--------------------------------------------------*/
int jumpSearch(int arr[], int length, int value) {

	int i = 0;

	while (i < length && value > arr[i])  {

		i += sqrt(length);
	}

	if (i >= length) {

		for (int j = i/2; j < length; ++j) {

			if(arr[j] == value){
				return j;
			}
		}
	} else {

		for (int j = i/2; j <= i; ++j) {

			if(arr[j] == value){
				return j;
			}
		}
	}

	return -1;
}
/*------------------------------------------------
				Ternary Search
--------------------------------------------------*/
int ternarySearch(int arr[], int low, int high, int value) {
	int mid1;
	int mid2;

	while (low <= high) {
		mid1 = low + (high - low) / 3;
		mid2 = high - (high - low) / 3;

		if (value == arr[mid1]) {
			return mid1;
		}

		if (value == arr[mid2]) {
			return mid2;
		}

		if (value < arr[mid1]) {

			return ternarySearch(arr, low, mid1 - 1, value);
		} else if (value > arr[mid1] && value < arr[mid2]) {

			return ternarySearch(arr, mid1 + 1, mid2 - 1, value);
		}

		return ternarySearch(arr, mid2 + 1, high, value);
	}

	return -1;
}
/*--------------------------------------------------------------------
				Interpolation Search
------------------------------------------------------------------------------*/
int interpolationSearch(int* arr, int low, int high, int value) {
	int pos;

	if (arr[high] - arr[low] == 0) {
		if (value == arr[low]) {
			return low;
		}
		return -1;
	}

	while (low <= high && value >= arr[low]) {
		pos = low + ( (value - arr[low]) * (high - low) / (arr[high] - arr[low]) );

		if (value == arr[pos]) {
			return pos;
		}

		if (value > arr[pos]) {
			return interpolationSearch(arr, pos + 1, high, value);
		}
		return interpolationSearch(arr, low, pos - 1, value);

	}

	return -1;
}
/*-----------------------------------------------------------
				Exponential Search
-----------------------------------------------------------*/
int exponentialSearch(int* arr, int low, int high, int value) {
	if (arr[0] == value) {
		return 0;
	}

	int i = 1;
	while (i <= high && arr[i] <= value) {
		i *= 2;
	}

	if (i > high) {
		return binarySearch(arr, i / 2, high, value);
	}
	return binarySearch(arr, i / 2, i, value);
}
/*--------------------------------------------
				Some functions for arrays
----------------------------------------------*/
int* inputArray(int length) {
	int* arr = new int[length];
	int i = 0;
	while (i < length) {
		std::cout << "arr[" << i << "]: ";
		std::cin >> arr[i];
		++i;
	}

	return arr;
}

void printArray(int* arr, int length) {
	for (int i = 0; i < length; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void swap (int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}

void insertSort (int arr[], int length) {

	int j;
	for (int i = 1; i < length; ++i) {

		j = i;
		while (arr[j] < arr[j-1] && j > 0) {
			swap(arr[j], arr[j-1]);
			--j;
		}
	}
}