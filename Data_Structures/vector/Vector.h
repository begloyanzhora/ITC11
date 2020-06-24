#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
private:
	unsigned int rsize;
	unsigned int maxSize;
	T* arr;
	void alloc();

public:
	Vector();
	Vector(unsigned int);
	Vector(const Vector&);
	~Vector();

	void popBack();
	void pushBack(T);
	unsigned int size();
	unsigned int capacity();
	bool isEmpty();
	void resize(unsigned int);
	void shrinkToFit();
	Vector<T>& operator=(const Vector<T>&);
	T operator[](unsigned int);
	T at(unsigned int);
    class Iterator;
    Iterator begin();
    Iterator end();
};

#endif