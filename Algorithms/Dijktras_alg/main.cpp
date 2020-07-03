#include "Graph.h"

int main() {

	Graph mygraph;

	mygraph.addVertex('A', 'S', 6);
	mygraph.addVertex('B', 'S', 2);
	mygraph.addVertex('A', 'B', 3);
	mygraph.addVertex('E', 'A', 1);
	mygraph.addVertex('E', 'B', 5);

	mygraph.printGraph();
	mygraph.getShortestPath('S', 'E');
	return 0;
}