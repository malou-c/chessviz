.PHONY: all clean install uninstall 

CC = g++
CFLAGS = -c -MP -MMD -Wall -Werror
SRC_PATH = src/
SRC = src/main.cpp src/FileWork.cpp src/map.cpp
OBJ = build/src/FileWork.o build/src/main.o build/src/map.o
DFILE = $(wildcard *.d))
EXEC = sp.exe

all: $(SRC) $(EXEC) 

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

build/src/%.o: src/%.cpp	
	$(CC) $(CFLAGS) $< -o $@
	
-include build/src/*.d



#tests
T_EXEC = test.exe
#меняет мейн на тестовый мейн
T_SRC = $(SRC:src/main.cpp=test/main.cpp)
TEST_SRC = test/FileWork_test.cpp test/map_test.cpp
TO_PATH = build/test/
T_OBJ = $(TO_PATH)main.o $(TO_PATH)FileWork_test.o $(TO_PATH)map_test.o build/src/FileWork.o build/src/map.o

test: $(T_SRC) $(TEST_SRC) $(T_EXEC)



$(T_EXEC): $(T_OBJ)
	$(CC) $(T_OBJ) -o $@

build/test/%.o: test/%.cpp	
	$(CC) $(CFLAGS) $< -o $@

-include build/test/*.d

clean:  
	rm -rf build/src/*.o build/src/*.d build/test/*.o build/test/*.d