#include <iostream>
#include <thread>

class Node {
public:
	Node* pNext;
	int data;

	Node(int, Node*);
};

Node::Node(int data, Node* pNext = nullptr) {
	this -> data = data;
	this -> pNext = pNext;
}

class List {
private:
	Node* head;
	int length;

public:
	List();
	~List();
	int getLength();
	int getElemByIndex(int);
	void show ();
	void shift ();
	void syncInsert (int, int);
	void asyncInsert (int, int);
	void remove(int);
	void asyncRemove(int);
};

List::List () {
	length = 0;
	head = nullptr;
}

int List::getLength () {
	return length;
}

int List::getElemByIndex (int index) {
	int count = 0;
	Node* current = this -> head;

	while (current != nullptr) {
		if (count == index) {
			return current -> data;
		}
		current = current -> pNext;
		count++;
	}
}

void List::show () {
	std::cout << "List: ";

	for (int i = 0; i < length; i++) {
		std::cout << getElemByIndex(i) << '\t';
	}
}

void List::syncInsert (int data, int index) {
	if (index == 0) {
		head = new Node(data, head);
	} else {
		Node* prev = this -> head;

		for (int i = 0; i < index - 1; i++) {
			prev = prev -> pNext;
		}

		Node* newNode = new Node (data, prev -> pNext);
		prev -> pNext = newNode;
	}
	length++;
}

void List::asyncInsert (int data, int index) {
	std::thread th(&List::syncInsert, this, data, index);
	th.join();
}

void List::remove (int index) {
	if(index == 0) {
		Node* temp = head;
		head = head -> pNext;

		delete temp;
	} else {
		Node* prev = this -> head;

		for (int i = 0; i < index - 1; i++) {
			prev = prev -> pNext;
		}

		Node *forRemove = prev -> pNext;
		prev -> pNext = forRemove -> pNext;
	}
	length--;
}

void List::asyncRemove(int index) {
	std::thread th(&List::remove, this, index);
	th.join();
}

List::~List () {
	while (length){
		Node* temp = head;
		head = head -> pNext;

		delete temp;
		length--;
	}
}

int main () {

	List test;
	test.asyncInsert(65, 0);
	test.asyncInsert(66, 1);
	test.asyncInsert(67, 2);
	test.asyncInsert(68, 3);

	test.asyncRemove(0);

	test.show();

	std::cout << "Element by index 0: " << test.getElemByIndex(0) << std::endl;
	std::cout << "Length: " << test.getLength() << std::endl;

	return 0;
}
