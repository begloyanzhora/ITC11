#include <iostream>
#include "Vector.cpp"
#include "Vector.h"
#include "Iterator.h"
using namespace std;

int main () {
	Vector<int> v;
	v.pushBack(5);
	v.pushBack(10);
	v.pushBack(15);

	cout << "Pushed into the vector " << v.size() << " elements. These are: " << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	if (v.isEmpty()) {
		cout << "The vector is empty." << endl;
	} else {
		cout << "The vector isn't empty." << endl;
	}

	cout << "Capacity of the vector is: " << v.capacity() << endl << endl;

	Vector<int> vec2 = v;
	cout << "Copied vector with overloaded operator=: " << endl;
	for (int i = 0; i < vec2.size(); ++i) {
		cout << vec2[i] << " ";
	}
	cout << endl;


	auto i = v.begin();
	cout << *(i+2) <<endl;

	return 0;
}