#include <iostream>

void mergeSort (int*, int, int);
void merge(int*, int, int);
void swap(int&, int&);

int main () {
	int arr[7] = {5, 85, 4, 21, -5, -15, 6};

	mergeSort(arr, 0, 6);

	std::cout << "Sorted array by merge sort: ";
	for(int i = 0; i < 7; ++i) {

		std::cout << arr[i] << ' ';
	}

	std::cout << std::endl;
	return 0;
}


void merge (int arr[], int left, int right) {

	int ls = left;
	int m = left + (right - left) / 2;
	int rs = m + 1;
	int merged[right - left];
	int i = 0;

	while (ls <= m && rs <= right) {

		if (arr[ls] <= arr[rs]) {

			merged[i] = arr[ls];
			ls++;
		} else {

			merged[i] = arr[rs];
			rs++;
		}

		i++;
	}

	while (ls <= m) {
		merged[i] = arr[ls];
		ls++;
		i++;
	}

	while (rs <= right) {
		merged[i] = arr[rs];
		rs++;
		i++;
	}

	for (int j = 0; j < i; j++){
		arr[left + j] = merged[j];
	}
}


void mergeSort (int* arr, int left, int right) {

	if (right > left) {

		if(right - left == 1) {

			if(arr[right] <= arr[left]){
				swap (arr[left], arr[right]);
			}

		} else {

			int m = left + (right - left) / 2;
			mergeSort(arr, left, m);
			mergeSort(arr, m + 1, right);
			merge(arr, left, right);
		}
	}
}

void swap (int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}