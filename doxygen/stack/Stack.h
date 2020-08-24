#ifndef STACK_H
#define STACK_H

/**
 * @class Node - to describe the element of stack
 * */
template <typename T>
struct Node {
	T data;
	Node* prev;
};

/**
 * @class Stack - Data Structure
 * */
template <typename T>
class Stack {
private:
	Node<T>* sTop;
	unsigned int length;

public:
	/**
	 * @brief constructor for stack class
	 * */
	Stack();
	/**
	 * @brief parameterized constructor for stack class
	 * */
	Stack(T, unsigned int);
	/**
	 * @brief destructor for stack class
	 * */
	~Stack();

	/**
	 * @brief method to check if stack is empty
	 * @return boolean value true or false
	 * */
	bool isEmpty();

	/**
	 * @brief method to add an element to stack
	 * @param 1st - param type T , valeu which you need to add
	 * */
	void push(T);
	/**
	 * @brief method to delete a last element
	 * */
	void pop();

	/**
	 * @brief method to get a last element
	 * */
	T top();

	/**
	 * @brief method to get a size of stack
	 * @private
	 * */
	unsigned int size();
};

#endif