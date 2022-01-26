#include <iostream>

template<typename T>
class Node {
public:
	Node* pNext;
	T data;

	Node(T, Node*);
};

template<typename T>
Node<T>::Node(T data, Node<T>* pNext) {
	this -> data = data;
	this -> pNext = pNext;
}

template <typename T>
class List {
private:
	Node<T>* head;
	int length;

public:
	List();
	~List();
	int getLength();
	T getElemByIndex(int);
	void show ();
	void insert (T, int);
	void remove(int);
	void clear ();
};

template <typename T>
List<T>::List () {
	length = 0;
	head = nullptr;
}

template <typename T>
int List<T>::getLength () {
	return length;
}


template <typename T>
T List<T>::getElemByIndex (int index) {
	int count = 0;
	Node<T>* current = this -> head;

	while (current != nullptr) {
		if (count == index) {
			return current -> data;
		}
		current = current -> pNext;
		count++;
	}
}


template <typename T>
void List<T>::show () {
	std::cout << "List: ";

	for (int i = 0; i < length; i++) {
		std::cout << getElemByIndex(i) << '\t';
	}
}

template <typename T>
void List<T>::insert (T data, int index) {
	if (index == 0) {
		head = new Node<T>(data, head);
	} else {
		Node<T>* prev = this -> head;

		for (int i = 0; i < index - 1; i++) {
			prev = prev -> pNext;
		}

		Node<T>* newNode = new Node<T> (data, prev -> pNext);
		prev -> pNext = newNode;
	}
	length++;
}

template <typename T>
void List<T>::remove (int index) {
	if(index == 0) {
		Node<T>* temp = head;
		head = head -> pNext;

		delete temp;
	} else {
		Node<T>* prev = this -> head;

		for (int i = 0; i < index - 1; i++) {
			prev = prev -> pNext;
		}

		Node<T> *forRemove = prev -> pNext;
		prev -> pNext = forRemove -> pNext;
		delete forRemove;
	}
	length--;
}

template <typename T>
void List<T>::clear () {
	while (length){
	Node<T>* temp = head;
	head = head -> pNext;

	delete temp;
	length--;
	}
}

template <typename T>
List<T>::~List () {
	clear();
}

template<typename T>
class Queue : protected List<T> {
public:
	Queue() : List<T>() {}
	~Queue();
	void push (T);
	T shift ();
	T getFirst ();
	T getLast ();
	int length ();
};

template<typename T>
void Queue<T>::push (T elem) {
	int index = length ();
	this->insert (elem, index);
}

template<typename T>
T Queue<T>::shift () {
	T elem = getFirst();
	this->remove (0);
	return elem;
}

template<typename T>
T Queue<T>::getFirst () {
	return this->getElemByIndex(0);
}

template<typename T>
T Queue<T>::getLast () {
	return this->getElemByIndex(length() - 1);
}

template<typename T>
int Queue<T>::length () {
	return this->getLength();
}

template<typename T>
Queue<T>::~Queue () {
	this->clear();
}

class myException : public std::exception {
	char* err;
public:
	myException (char* msg) {
		this->err = msg;
	}
	char* what() {
		return this->err;
	}
};

void printL (List<int>& l) {
	if (0 == l.getLength()) {
		throw myException("In LIST");
	} else {
		std::cout << l.getLength() << std::endl;
	}
}

void printQ (Queue<int>& q) {
	if (0 == q.length()) {
		throw myException("In QUEUE");
	} else {
		std::cout << q.length() << std::endl;
	}
}

int main () {
	List<int> l;
	Queue<int> q;
	try {
		printL(l);
	} catch (myException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		printQ(q);
	} catch (myException& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}