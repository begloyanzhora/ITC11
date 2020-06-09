#include <iostream>

int main () {
	const int n = 10;
	int i = 0;
	int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cin >> i;

	try {
		if (i < 0 || i >= n){
			throw "Undefined elem";
		} else {
			std::cout << arr[i] << std::endl;
		}
	} catch (const char* e) {
		std::cout << e << ". Please enter valid index" << std::endl;
	}

	return 0;
}