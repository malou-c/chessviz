.PHONY: all clean install uninstall 

CC = g++
CFLAGS = -c -MP -MMD -Wall -Werror
SRC_PATH = src/
SRC = src/main.cpp src/FileWork.cpp
OBJ = build/FileWork.o build/main.o
EXEC = sp.exe


all: $(SRC) $(EXEC) 

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.cpp	
	$(CC) $(CFLAGS) $< -o $@

include $(OBJ:.o=.d)

clean:  
	rm -rf build/*.o *.html