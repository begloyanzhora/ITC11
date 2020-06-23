#include <iostream>
using namespace std;

template<typename T>
class MyVector {
private:
	unsigned int rsize;
	unsigned int maxSize;
	T* arr;
	void alloc();

public:
	MyVector();
	MyVector(unsigned int);
	MyVector(const MyVector&);
	~MyVector();

	void pushBack(T);
	unsigned int size();
	unsigned int capacity();
	bool isEmpty();
	void resize(unsigned int);
	void shrinkToFit();
	MyVector<T>& operator=(const MyVector<T>&);
	T operator[](unsigned int);
	T at(unsigned int);
};

template<typename T>
MyVector<T>::MyVector() {
	rsize = 0;
	maxSize = 20;
	arr = new T[maxSize];
}

template<typename T>
MyVector<T>::MyVector(unsigned int n) {
	rsize = 0;
	maxSize = n;
	arr = new T[maxSize];
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& vec) {
	maxSize = vec.maxSize;
	rsize = vec.rsize;
	arr = new T[maxSize];

	for(int i = 0; i < rsize; ++i) {
		arr[i] = vec.arr[i];
	}
}

template<typename T>
void MyVector<T>::pushBack(T elem) {
	if (rsize + 1 > maxSize) {
		alloc();
	}

	arr[rsize] = elem;
	++rsize;
}

template<typename T>
unsigned int MyVector<T>::size() {
	return rsize;
}

template<typename T>
unsigned int MyVector<T>::capacity() {
	return maxSize;
}

template<typename T>
bool MyVector<T>::isEmpty() {
	return (0 == rsize);
}

template<typename T>
T MyVector<T>::operator[](unsigned int i) {
	return arr[i];
}
/*------------------------------Doesn't work--------------------------------*/
/*MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
	if (this != &MyVector) {
		maxSize = v.maxSize;
		rsize = v.rsize;
		delete[] arr;
		arr = new T[maxSize];

		for (int i = 0; i < rsize; ++i) {
			arr[i] = v.arr[i];
		}
	}
	return *this;
}*/
/*----------------------------------------------------------------------------*/
template<typename T>
T MyVector<T>::at(unsigned int i) {
	if (i < rsize) {
		return arr[i];
	}
	try {
		throw "Please run again and enter the valid index.";
	} catch(const char* e) {
		cout << e << endl;
	}
}

template<typename T>
void MyVector<T>::resize(unsigned int n) {
	maxSize = n;
	T* tmp = new T[maxSize];

	for(int i = 0; i < maxSize; ++i) {
		tmp[i] = arr[i];
	}

	delete[] arr;

	arr = tmp;
}

template<typename T>
void MyVector<T>::shrinkToFit() {
	resize(rsize);
}

template<typename T>
void MyVector<T>::alloc() {
	unsigned int n = rsize * 2;
	resize(n);
}

template<typename T>
MyVector<T>::~MyVector() {
	delete[] arr;
}

int main () {
	MyVector<int> v;
	int tmp;

	cout << "Please enter the elements of your vector[enter number -1 to finish]: " << endl;

	while (1) {
		cin >> tmp;
		if (-1 == tmp) {
			break;
		}
		v.pushBack(tmp);
	}

	cout << "You've entered: " << v.size() << " elements. These are: " << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	if (v.isEmpty()) {
		cout << "The vector is empty." << endl;
	} else {
		cout << "The vector isn't empty." << endl;
	}

	cout << "capacity " << v.capacity() << endl;
	//cout << "v[5] = " << v.at(5) << endl;

	v.resize(5);

	cout << "capacity " << v.capacity() << endl;

	cout << "You've entered: " << v.size() << " elements. These are: " << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	MyVector<int> vec2 = v;
	for (int i = 0; i < vec2.size(); ++i) {
		cout << vec2[i] << " ";
	}
	cout << endl;


	return 0;
}
