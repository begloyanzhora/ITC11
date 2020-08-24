#include <iostream>

int main() {
	int a = 0;
	int b = 0;
	int res = 0;

	std::cin >> a;
	std::cin >> b;

	try {
		if (0 == b){
			throw "Error: b must be not 0";
		} else {
			res = a/b;
			std::cout << res;
		}
	} catch (const char* e) {
		std::cout << e;
	}

	return 0;
}