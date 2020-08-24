cc=g++
comp=-std=c++11

prog: main.o
	${cc} ${comp} main.o List.o Node.o

main.o: List.o
	${cc} ${comp} main.cpp -c -o main.o

List.o: List.cpp List.h Node.o
	${cc} ${comp} List.cpp -c -o List.o

Node.o: Node.cpp Node.h
	${cc} ${comp} Node.cpp -c -o Node.o

run:
	./a.out

clean:
	rm *.o
