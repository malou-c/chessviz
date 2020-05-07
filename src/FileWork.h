#pragma once
#include <fstream>
#include <iostream>
#include <string>

class FileWork {
public:
    void add_msg(std::string msg, std::string path);
    void add_head(std::string path);
    void add_step(std::string step, std::string path);
    void add_figure(char figure, std::string path);
    void add_end(std::string path);
    void add_complete(std::string path);
    void add_error(std::string step, std::string path);
};