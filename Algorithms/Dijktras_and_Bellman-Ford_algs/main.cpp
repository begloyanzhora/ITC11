#include "Graph.h"
#include <iostream>

int main() {

	Graph mygraph;
	Graph mygraph2;

	mygraph.addVertex('A', 'S', 5);
	mygraph.addVertex('B', 'S', 0);
	mygraph.addVertex('C', 'A', 20);
	mygraph.addVertex('D', 'A', 15);
	mygraph.addVertex('C', 'B', 35);
	mygraph.addVertex('D', 'B', 30);
	mygraph.addVertex('E', 'D', 20);
	mygraph.addVertex('E', 'C', 10);

	mygraph2.addVertex('E', 'S', 8);
	mygraph2.addVertex('A', 'S', 10);
	mygraph2.addVertex('C', 'A', 2);
	mygraph2.addVertex('B', 'C', -2);
	mygraph2.addVertex('A', 'B', 1);
	mygraph2.addVertex('D', 'E', 1);
	mygraph2.addVertex('A', 'D', -4);
	mygraph2.addVertex('C', 'D', -1);

	std::cout << "===============Dijkstra's Algorithm=================" << std::endl;

	mygraph.printGraph();
	mygraph.getShortestPath('E');

	std::cout << "==============Bellman-Ford's Algorithm==============" << std::endl;

	mygraph2.printGraph();
	mygraph2.bellmanFord('E');
	return 0;
}