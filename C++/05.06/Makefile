prog: main.cpp List.o
	g++ -std=c++11 main.cpp -o prog

List.o: List.cpp List.h Node.o
	g++ -std=c++11 List.cpp -c -o List.o

Node.o: Node.cpp Node.h
	g++ -std=c++11 Node.cpp -c -o Node.o
