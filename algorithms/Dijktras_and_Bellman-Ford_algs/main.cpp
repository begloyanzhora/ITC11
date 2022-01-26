#include "Graph.h"
#include <iostream>

int main() {

	Graph mygraph;
	Graph mygraph2;
	Graph mygraph3;
	Graph mygraph4;

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

	mygraph3.addVertex('A', 'S', 4);
	mygraph3.addVertex('B', 'S', 5);
	mygraph3.addVertex('C', 'A', 7);
	mygraph3.addVertex('A', 'B', 7);
	mygraph3.addVertex('B', 'C', -15);

	mygraph4.addVertex('A', 'S', 6);
	mygraph4.addVertex('B', 'S', 5);
	mygraph4.addVertex('C', 'S', 5);
	mygraph4.addVertex('D', 'A', -1);
	mygraph4.addVertex('A', 'B', -2);
	mygraph4.addVertex('D', 'B', 1);
	mygraph4.addVertex('B', 'C', -2);
	mygraph4.addVertex('E', 'C', -1);
	mygraph4.addVertex('F', 'D', 3);
	mygraph4.addVertex('F', 'E', 3);

	std::cout << "===============Dijkstra's Algorithm=================" << std::endl;

	mygraph.printGraph();
	mygraph.getShortestPath('E');

	std::cout << "==============Bellman-Ford's Algorithm==============" << std::endl;

	mygraph2.printGraph();
	mygraph2.bellmanFord('E');

	std::cout << "==============Bellman-Ford's Algorithm cycle with negative wiight==============" << std::endl;

	mygraph3.printGraph();
	mygraph3.bellmanFord('C');

	std::cout << "==============Bellman-Ford's Algorithm Example 3==============" << std::endl;

	mygraph4.printGraph();
	mygraph4.bellmanFord('F');
	return 0;
}