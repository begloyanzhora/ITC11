#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

void encrypt (ifstream&, int, ofstream&);
void decrypt (ifstream&, int, ofstream&);

int main (int argc, char* argv[]) {
	if (argc != 4) {
		exit(0);
	} else {
		int res = strcmp (argv[3], "encrypt");
		int res2 = strcmp (argv[3], "decrypt");
		ifstream f;
		ofstream r;
		ofstream r1;
		f.open (argv[1]);
		r.open("res.txt");

		int step = stoi(argv[2]);

		if (0 == res) {
			encrypt(f, step, r);
		} else if (0 == res2) {
			decrypt (f, step, r);
		}

		f.close();
		r.close();
		return 0;
	}
}

void encrypt (ifstream& f, int step, ofstream& r) {
	char ch;
	int n;

	while (f.get(ch)) {
		n = (int)ch;
		n += step;

		if (n > 122) {
			n = 64 + n - 122;
		}

		ch = (char) n;
		r << ch;
	}
}

void decrypt (ifstream& f, int step, ofstream& r) {
	char ch;
	int n;

	while (f.get(ch)) {
		n = (int)ch;
		n -= step;

		if (n < 65) {
			n = 123 - (65 - n);
		}

		ch = (char) n;
		r << ch;
	}
}
