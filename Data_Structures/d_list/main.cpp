#include "List.h"
#include "Iterator.h"
#include "List.cpp"
#include <iostream>
using namespace std;

int main () {
	List<int> l;

	l.push(5);
	l.push(6);
	l.push(7);
	List<int>::Iterator i = l.begin();
	i;
	cout << *i << endl;
	l.show();

	return 0;
}