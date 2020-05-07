.PHONY: all clean install uninstall 

CC = g++
CFLAGS = -c -MP -MMD -Wall -Werror
SRC_PATH = src/
SRC = src/main.cpp src/FileWork.cpp src/map.cpp
OBJ = build/FileWork.o build/main.o build/map.o
DFILE = $(wildcard *.d))
EXEC = sp.exe

all: $(SRC) $(EXEC) 

include build/*.d

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.cpp	
	$(CC) $(CFLAGS) $< -o $@


clean:  
	rm -rf build/*.o build/*.d *.html