#ifndef __GRAPH__H__
#define __GRAPH__H__

#include <list>
#include <map>

struct Node {
	char own;
	std::list<Node*> to;
	std::map<Node*, int> weight;

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
	void addVertex(char, char, int);
	void printGraph();
	void getShortestPath(char);
	void bellmanFord(char);
	~Graph();
};

#endif