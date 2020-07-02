#ifndef __GRAPH__H__
#define __GRAPH__H__

#include <list>

struct Node {
	char own;
	std::list<Node*> to;

	Node(char val) {
		this->own = val;
	}
};

class Graph {
private:
	std::list<Node*> vertex;
	Node* getVertexNode(char);

public:

	Graph();
	void addVertex(char, char);
	void printGraph();
	~Graph();
};

#endif