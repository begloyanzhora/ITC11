#include <iostream>

int getMin (int a, int b, int c) {
	int min = a;

	if (min > b){
		min = b;
	}
	if (min > c) {
		min = c;
	}

	return min;
}

int getUglyNumber (int nth) {
	int* ugNum = new int [nth];
	ugNum[0] = 1;
	int p2 = 0;
	int p3 = 0;
	int p5 = 0;
	int m2 = 2;
	int m3 = 3;
	int m5 = 5;
	int next;

	for (int i = 1; i < nth; ++i) {

		next = getMin(m2, m3, m5);
		ugNum[i] = next;

		if (next == m2) {
			++p2;
			m2 = ugNum[p2] * 2;
		}

		if (next == m3) {
			++p3;
			m3 = ugNum[p3] * 3;
		}

		if(next == m5){
			++p5;
			m5 = ugNum[p5] * 5;
		}
	}

	return ugNum[nth - 1];
}

int main () {

	for (int i = 1; i <= 10; i++) {
		std::cout << getUglyNumber(i) << ' ';
	}
	std::cout << std::endl;

	return 0;
}