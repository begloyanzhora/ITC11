#include <iostream>
#include <vector>

std::vector<int> mem(1, 0);

int fib (int n) {
	if (n < mem.size()) {
		return mem[n];
	}

	if (n < 2) {
		mem.push_back(n);
		return mem[n];
	}

	mem.push_back(fib(n - 1) + fib(n - 2));
	return mem[n];

}

int main() {

	int n = fib(3);

	std::cout << n << std::endl;

	return 0;
}
