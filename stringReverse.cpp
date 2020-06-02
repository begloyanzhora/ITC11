#include <iostream>

char *stringReverse (char *text) {
    int length = 0;

    while (text[length] != '\0'){
        length++;
	}

    for (int i = 0; i < length-1; ++i){
        for (int j = 0; j < length - i - 1; ++j){
            char temp = text[j];
            text[j] = text[j + 1];
            text[j + 1] = temp;
        }
    }

    return text;
}

int main () {
	char text[100];

	std::cout << "Please enter the text: ";
	std::cin >> text;

    std::cout << "Inputed String: " << text << std::endl;
    std::cout << "Reversed String: " << stringReverse(text) << std::endl;
	return 0;
}