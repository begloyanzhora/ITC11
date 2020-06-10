#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream pic;
    ofstream newPic;

    pic.open("pic.jpg", ios::binary);
    newPic.open("newPic.jpg", ios::binary);
    char ch;
    while (pic.get(ch)) {
        newPic << ch;
    }

    return 0;
}