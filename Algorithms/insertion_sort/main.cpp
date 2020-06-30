#include <iostream>

void insertSort (int*, int);
void swap (int&, int&);

int main () {

	int arr[6] = {5, 85, 4, 21, -12, 15};
	insertSort (arr, 6);

	for(int i = 0; i < 6; ++i) {

		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}


void swap (int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}

void insertSort (int arr[], int length) {

	int j;
	for (int i = 1; i < 6; ++i) {

		j = i;
		while (arr[j] < arr[j-1] && j > 0) {
			swap(arr[j], arr[j-1]);
			--j;
		}
	}
}