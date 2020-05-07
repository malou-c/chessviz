.PHONY: all clean install uninstall 

CC = g++
CFLAGS = -c -M -Wall 
SRC_PATH = src/
SRC = src/main.cpp src/FileWork.cpp
OBJ = build/main.o build/FileWork.o
EXEC = sp.exe


all: $(SRC) $(EXEC) 

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.cpp	
	$(CC) $(CFLAGS) $< -o $@

clean:  
	rm -rf build/*.o *.html