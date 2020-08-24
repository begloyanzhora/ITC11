#include <iostream>
#include "func.h"

int main () {
	int length = 0;
	std::cout << "Enter the length of array(>0): ";

	std::cin >> length;
	while (std::cin.fail() || length < 1) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Please reenter the valid number: ";
		std::cin >> length;
	}

	int* arr = inputArray(length);
	int value = 0;
	int algNum = 2;

	std::cout << "You've entered: " << std::endl;
	printArray(arr, length);

	std::cout << "The sorted array:" << std::endl;
	insertSort(arr, length);
	printArray(arr, length);

	std::cout << "Please enter the integer number to find it in the array: ";

	std::cin >> value;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Please reenter the valid number: ";
		std::cin >> value;
	}

	std::cout << "Which of these algorithms do you want to use?" << std::endl;
	std::cout << "[1].Linear search" << std::endl;
	std::cout << "[2].Binary search" << std::endl;
	std::cout << "[3].Jump search" << std::endl;
	std::cout << "[4].Ternary search" << std::endl;
	std::cout << "[5].Interpolation search" << std::endl;
	std::cout << "[6].Exponential search" << std::endl;
	std::cout << "Please enter the number: ";

	std::cin >> algNum;
	while (std::cin.fail() || algNum < 1 || algNum > 6) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Please reenter the valid number: ";
		std::cin >> algNum;
	}

 	switch (algNum) {
	case 1:
		std::cout << "Found with Linear search. Value " << value << " is at " << linearSearch(arr, length, value) << " index" << std::endl;
		break;

	case 2:
		std::cout << "Found with Binary search. Value " << value << " is at " << binarySearch(arr, 0, length - 1, value) << " index" << std::endl;
		break;

	case 3:
		std::cout << "Found with Jump search. Value " << value << " is at " << jumpSearch(arr, length, value) << " index" << std::endl;
		break;

	case 4:
		std::cout << "Found with Ternary search. Value " << value << " is at " << ternarySearch(arr, 0, length - 1, value) << " index" << std::endl;
		break;

	case 5:
		std::cout << "Found with Interpolation search. Value " << value << " is at " << interpolationSearch(arr, 0, length - 1, value) << " index" << std::endl;
		break;

	case 6:
		std::cout << "Found with Exponential search. Value " << value << " is at " << exponentialSearch(arr, 0, length - 1, value) << " index" << std::endl;
		break;

	default:
		break;
	}

	return 0;
}