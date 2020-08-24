#include <iostream>

bool isUgly (int n) {
	int tmp = n;

	while (true) {

		if(tmp == 1) {
			return true;
		}

		if ((tmp % 2 != 0) && (tmp % 3 != 0) && (tmp % 5 != 0)) {
			return false;
		}

		if (tmp % 2 == 0) {
			tmp /= 2;
		} else if (tmp % 3 == 0) {
			tmp /= 3;
		} else {
			tmp /= 5;
		}
	}
}

int getUglyNum (int nth) {
	if (nth < 1) {
		std::cout << "Invalid number" << std::endl;
		return -1;
	}

	int count = 1;
	int n = 2;

	while (count < nth) {

		if (isUgly(n)) {
			++count;
		}
		++n;
	}

	return n - 1;
}

int main () {
	int n = 6;

	for (size_t i = 1; i <= 10; i++) {
		std::cout << getUglyNum(i) << ' ';
	}

	std::cout << std::endl;
}