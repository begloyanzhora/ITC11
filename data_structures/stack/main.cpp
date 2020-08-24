#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

int main() {
	Stack<int>* s = new Stack<int>(5, 6);
	s->pop();
	std::cout << s->top() << std::endl;
	std::cout << s->size() << std::endl;

	return 0;
}