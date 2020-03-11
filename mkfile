all: start
	
start: main.o FileWork.o
	g++ -Wall main.o FileWork.o -o sp.exe

main.o: main.cpp
	g++ -c main.cpp

FileWork.o: 
	g++ -c FileWork.cpp

clean:  
	rm -rf *.o *.exe *.html