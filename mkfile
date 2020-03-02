all: start

start: main.o
    g++ -Wall main.o -o sp

main.o: main.cpp
    g++ -c main.cpp

clean: 
	rm *.o