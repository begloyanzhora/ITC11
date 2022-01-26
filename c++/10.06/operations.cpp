#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main () {
    ifstream f1;
    ifstream f2;
    ifstream f3;
    ofstream res;

    f1.open("n1.txt");
    f2.open("n2.txt");
    f3.open("op.txt");
    res.open("res.txt");

    string ch1;
    string ch2;
    string opLine;

    char op;
    int n1;
    int n2;

    while ( getline(f1, ch1) ) {
        n1 = stoi(ch1);

        while ( getline(f3, opLine) ) {
            op = opLine[0];

            while ( getline(f2, ch2) ) {
                n2 = stoi(ch2);

                switch (op) {
                case '+':
                    res << n1 << " + " << n2 << " = " << n1 + n2 << endl;
                    break;
                case '-':
                    res << n1 << " - " << n2 << " = " << n1 - n2 << endl;
                    break;
                case '*':
                    res << n1 << " * " << n2 << " = " << n1 * n2 << endl;
                    break;
                case '/':
                    res << n1 << " + " << n2 << " = " << n1 / n2 << endl;
                    break;
                default:
                    cout << "Something is wrong:";
                    break;
                }
            }
            if (f2.is_open()) {
                f2.clear();
                f2.seekg(0, ios::beg);
            }
        }
        if (f3.is_open()) {
            f3.clear();
            f3.seekg(0, ios::beg);
        }
    }

    f1.close();
    f2.close();
    f3.close();
    res.close();
    return 0;
}