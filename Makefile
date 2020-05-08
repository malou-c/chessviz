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


#tests
T_EXEC = test.exe
T_SRC = $(SRC:src/main.cpp=test/main.cpp)
TEST_SRC = test/FileWork_test.cpp
TO_PATH = build/test/
T_OBJ = $(TO_PATH)main.o $(TO_PATH)FileWork_test.o build/FileWork.o

test: $(T_SRC) $(TEST_SRC) $(T_EXEC)

include build/test/*.d

$(T_EXEC): $(T_OBJ)
	$(CC) $(T_OBJ) -o $@

build/test/%.o: test/%.cpp	
	$(CC) $(CFLAGS) $< -o $@

clean:  
	rm -rf build/*.o build/*.d *.html