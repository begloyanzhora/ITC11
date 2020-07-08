#include "Graph.h"
#include <iostream>
#include <map>
#include <climits>

#define INF INT_MAX

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

void Graph::getShortestPath(char finish) {

	std::list<Node*> unvisited = vertex;
	std::list<Node*> visited;
	std::map<Node*, int> distance;
	std::map<Node*, Node*> prev;

	auto i = unvisited.begin();
	distance[*i] = 0;
	++i;

	for (;i != unvisited.end(); ++i) {
		distance[*i] = INF;
	}

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

	std::cout << "Shortest path to <" << finish << "> will be: " << distance[lastNode] << std::endl;

	std::cout << finish << "<--" ;

	while (prev[lastNode] != nullptr) {

		std::cout << prev[lastNode]->own << "<--";
		lastNode = prev[lastNode];
	}

	std::cout << "start" << std::endl;
}

void Graph::bellmanFord(char finish) {

	std::map<Node*, int> distance;
	std::map<Node*, Node*> prev;
	Node* lastNode = getVertexNode(finish);

	auto i = vertex.begin();
	distance[*i] = 0;
	++i;
	for (; i != vertex.end(); ++i) {
		distance[*i] = INF;
	}

	for (int k = 0; k < vertex.size() - 1; ++k) {
		Node* current;

		for (auto i = vertex.begin(); i != vertex.end(); ++i) {
			current = *i;

			if (distance[current] == INF) {
				continue;
			}

			if(!(current->to).empty()) {

				for(auto j = (current->to).begin(); j != (current->to).end(); ++j) {

					if (distance[*j] > distance[current] + current->weight[*j]) {
						distance[*j] = distance[current] + current->weight[*j];
						prev[*j] = current;
					}
				}
			}
		}
	}

	std::cout << "Shortest path to <" << lastNode->own << "> will be: " << distance[lastNode] << std::endl;

	std::cout << lastNode->own << "<--" ;

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