#include "Graph.h"
#include <iostream>

Graph::Graph () {

	Node* s = new Node('S');
	vertex.push_back(s);
}

void Graph::addVertex(char val, char from) {

	bool exist = false;
	Node* fromNode = getVertexNode(from);
	Node* v;

	for (auto i = vertex.begin(); i != vertex.end(); ++i) {

		if (val == (*i)->own) {
			exist = true;
			break;
		}
	}

	if(exist) {
		v = getVertexNode(val);

	} else {

		v = new Node(val);
		vertex.push_back(v);
	}

	fromNode->to.push_back(v);
}

void Graph::printGraph() {

	for (auto i = vertex.begin(); i != vertex.end(); ++i) {

		std::cout << (*i) -> own << " --> ";

		for( auto j = (*i) -> to.begin(); j != (*i) -> to.end(); ++j ) {
			std::cout << (*j)->own << ' ';
		}

		std::cout << std::endl;
	}
}

Node* Graph::getVertexNode (char v) {

	for (auto i = vertex.begin(); i != vertex.end(); ++i) {

		if((*i) -> own == v) {
			return *i;
		}
	}
}

Graph::~Graph () {

	while (!vertex.empty()) {

		vertex.pop_front();
		delete vertex.front();
	}
}