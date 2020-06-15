prog: main.o
	g++ -std=c++11 main.o List.o Node.o

main.o: List.o
	g++ -std=c++11 main.cpp -c -o main.o

List.o: List.cpp List.h Node.o
	g++ -std=c++11 List.cpp -c -o List.o

Node.o: Node.cpp Node.h
	g++ -std=c++11 Node.cpp -c -o Node.o

clean:
	rm *.o
