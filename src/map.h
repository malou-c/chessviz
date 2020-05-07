#pragma once
#include "FileWork.h"
#include <fstream>
#include <iostream>
#include <string>

class Vec2i {
public:
    int x;
    int y;
    bool isOK = true;
    Vec2i()
    {
        x = 0;
        y = 0;
    }
};

class Map {
private:
public:
    std::string step = "";
    int step_id = 0;
    char step_fig = ' ';
    char step_move = ' ';
    Vec2i cell_pos;
    char map[9][9] = {
            {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
            {'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    };
    bool CheckNotation(std::string filename);
    bool found_pos(char x, char y);
    bool CN_typefig();
    bool CN_typemove();
    bool CN_cellfig();
};
