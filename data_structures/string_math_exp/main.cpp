#include <iostream>
#include <stack>

int toInt(char);
int getPreority(char);
int calculate(int, int, char);

int main() {
	char* exp = (char*)"7+5*6-4-2+5*3";

	std::stack<int> numbers;
	std::stack<char> opers;
	int i = 0;

	while (exp[i] != '\0') {

		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

			int currPr = getPreority(exp[i]);
			int topPr = getPreority(opers.top());

			while (!opers.empty() && currPr <= topPr) {
				int b = numbers.top();
				numbers.pop();

				int a = numbers.top();
				numbers.pop();

				char op = opers.top();
				opers.pop();

				int res = calculate(a, b, op);
				numbers.push(res);
			}

			opers.push(exp[i]);

		} else {

			numbers.push( toInt(exp[i]) );
		}


		++i;
	}

	while (!opers.empty()) {
		int b = numbers.top();
		numbers.pop();

		int a = numbers.top();
		numbers.pop();

		char op = opers.top();
		opers.pop();

		int res = calculate(a, b, op);
		numbers.push(res);
	}
	if (!numbers.empty()) {
		std::cout << numbers.top() << std::endl;
	}
}

int toInt (char c) {
	int n = c - 48;
	return n;
}

int getPreority (char op) {
	if (op == '*' || op == '/') {
		return 2;
	}

	return 1;
}

int calculate (int a, int b, char op) {

	switch (op) {
	case '+':
		return a + b;
		break;

	case '-':
		return a - b;
		break;

	case '*':
		return a * b;
		break;

	case '/':
		return a / b;
		break;

	default:
		break;
	}
}