#include <iostream>

int main() {
	try {
		int* myarray= new int[100000787000000];
	} catch (std::exception& ba) {
		std::cout << "Catched stantard execption" << std::endl;
	}

	return 0;
}
