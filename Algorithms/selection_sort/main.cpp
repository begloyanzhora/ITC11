#include <iostream>
void selectSort (int*, int);

int main () {
	int arr[6] = {5, 85, 4, 21, -5, 15};
	int length = sizeof(arr) / sizeof(arr[0]);

	selectSort(arr, length);

	for(int i = 0; i < 6; ++i) {

		std::cout << arr[i] << ' ';
	}

	std::cout << std::endl;
	return 0;
}

void selectSort (int arr[], int length) {
	std::cout << "length:::" << length << std::endl;
	int min;
	int minIndex;
	int j;

	for (int i = 0; i < length - 1; ++i) {
		min = arr[i];
		minIndex = i;

		j = i + 1;
		while (j < 6) {
			if (arr[j] < min) {
				min = arr[j];
				minIndex = j;
			}
			++j;

		}
		int tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;

	}
}