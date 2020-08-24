#include "Graph.h"

int main() {

	Graph mygraph;

	mygraph.addVertex('A', 'S');
	mygraph.addVertex('B', 'S');
	mygraph.addVertex('C', 'A');
	mygraph.addVertex('A', 'B');
	mygraph.addVertex('C', 'B');
	mygraph.addVertex('E', 'C');

	mygraph.printGraph();

	return 0;
}