#pragma once
#include "FileWork.h"

using namespace std;
fstream fs;

void FileWork::add_msg(string msg, string path)
{
    fs.open(path, fs.out | fs.app);
    if (fs.is_open()) {
        cout << "file open" << endl;
        fs << msg;

    } else {
        cout << "error file" << endl;
    }
    fs.close();
}
