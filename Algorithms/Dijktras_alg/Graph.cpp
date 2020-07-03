#include "Graph.h"
#include <iostream>
#include <map>
Graph::Graph () {

	Node* s = new Node('S');
	vertex.push_back(s);
}

void Graph::addVertex(char val, char from, int weight) {

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
	fromNode->weight[v] = weight;
}

void Graph::printGraph() {

	for (auto i = vertex.begin(); i != vertex.end(); ++i) {

		std::cout << (*i) -> own << " --> ";

		for( auto j = (*i) -> to.begin(); j != (*i) -> to.end(); ++j ) {
			std::cout << (*j)->own << (*i)->weight[*j] << ' ';
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

void Graph::getShortestPath(char start, char finish) {

	std::list<Node*> unvisited = vertex;
	std::list<Node*> visited;
	std::map<Node*, int> distance;
	std::map<Node*, Node*> prev;
	Node* startNode = getVertexNode(start);

	for (auto i = unvisited.begin(); i != unvisited.end(); ++i) {
		distance[*i] = 10000;
	}


	for (auto i = (startNode->to).begin(); i != (startNode->to).end(); ++i) {

		distance[*i] = startNode->weight[*i];
		prev[*i] = startNode;
	}

	visited.push_back(startNode);
	unvisited.remove(startNode);

	while (!unvisited.empty()) {

		Node* current = unvisited.front();
		char currentVal = current->own;

		for ( auto i = unvisited.begin(); i != unvisited.end(); ++i ) {

			if(distance[*i] < distance[current]) {
				current = *i;
			}
		}

		if (!(current->to).empty()) {
			for (auto j = (current->to).begin(); j != (current->to).end(); ++j) {

				if (distance[*j] > distance[current] + current->weight[*j]) {

					distance[*j] = distance[current] + current->weight[*j];

					prev[*j] = current;
				}
			}
		}

		visited.push_back(current);
		unvisited.remove(current);
	}

	Node* lastNode;

	for (auto i = visited.begin(); i != visited.end(); ++i) {

		if ((*i)->own == finish) {

			lastNode = *i;
			break;
		}
	}

	std::cout << "Shortest path to <" << finish << "> will be:" << std::endl;

	std::cout << finish << "<--" ;

	while (prev[lastNode] != nullptr) {

		std::cout << prev[lastNode]->own << "<--";
		lastNode = prev[lastNode];
	}

	std::cout << "start" << std::endl;
}

Graph::~Graph () {

	while (!vertex.empty()) {

		vertex.pop_front();
		delete vertex.front();
	}
}