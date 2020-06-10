#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	const string path = "myFile.txt";

	ifstream file;
	ofstream res;

	file.open(path);
	res.open("res.txt");

	char ch;
	int i = 0;
	char *a = new char[i];

	while (file.get(ch)) {
		*(a + i) = ch;
		i++;
	}

	for (int j = i-1; j >= 0; --j) {
		res << a[j];
	}

	res.close();
	file.close();

	return 0;
}