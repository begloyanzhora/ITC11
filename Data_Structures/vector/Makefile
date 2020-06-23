cc=g++
comp=-std=c++11

prog: main.o
	${cc} ${comp} main.o

main.o: Vector.o
	${cc} ${comp} main.cpp -c -o main.o

Vector.o: Vector.cpp Vector.h Iterator.h
	${cc} ${comp} Vector.cpp -c -o Vector.o

run:
	./a.out

clean:
	rm *.o