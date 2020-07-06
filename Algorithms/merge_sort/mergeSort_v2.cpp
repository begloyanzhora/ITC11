#include <iostream>
using namespace std;

void swap (int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}

void mergeSort(int arr[], int length) {

	if (2 == length) {

		if(arr[0] > arr[1]) {

			swap(arr[0], arr[1]);
		}
	} else if (length > 2) {

		int m = length / 2;
		int* leftArr = new int[m];
		int* rightArr = new int[length - m];
		for (int i = 0, j = m; i < m, j < length; ++i, ++j) {

			leftArr[i] = arr[i];
			rightArr[i] = arr[j];
		}

		mergeSort(leftArr, m);
		mergeSort(rightArr, length - m);

		int i = 0;
		int j = 0;
		int k = 0;

		while (i < m && j < length - m) {
			if(leftArr[i] < rightArr[j]) {
				arr[k] = leftArr[i];
				++i;
			} else if (leftArr[i] > rightArr[j]) {
				arr[k] = rightArr[j];
				++j;
			}
			++k;
		}

		while (i < m) {
			arr[k] = leftArr[i];
			++i;
			++k;
		}

		while (j < length - m) {
			arr[k] = rightArr[j];
			++j;
			++k;
		}

		delete leftArr;
		delete rightArr;
	}
}


int main () {

	int arr[5] = {5, 3, 2, 1, 0};
	mergeSort(arr, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr[i];
	}

	return 0;
}
