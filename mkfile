all: start
	
start: main.o FileWork.o
	g++ main.o FileWork.o -o sp

main.o: main.cpp
	g++ -c main.cpp

FileWork.o: FileWork.cpp
	g++ -c FileWork.cpp

clean: 
	rm *.o