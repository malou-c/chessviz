#include <fstream>

#include "../src/FileWork.h"
#include "thirdparty/catch.hpp"

using namespace std;

FileWork testfw;
string path = "test/test_out.txt";

void cleanfile(string path)
{
    //чистит файл перед тестом
    fstream file;
    file.open(path, ios::out | ios::trunc);
    file.clear();
    file.close();
}

TEST_CASE("FW: add_msg()", "[FW]")
{
    //чистит файл перед тестом
    fstream file;
    cleanfile(path);
    //записываем сообщение через функцию
    string msg = "test msg 1 2 3";
    string test_msg = "testmsg123";
    testfw.add_msg(msg, path);
    //открываем файл и проверяем сообщение
    file.open(path, ios::in);
    string msg_in_file = "";
    string step = "";
    while (!file.eof()) {
        file >> step;
        msg_in_file += step;
    }
    CHECK(msg_in_file == test_msg);
    file.close();
}

TEST_CASE("FW: add_figure()", "[FW]")
{
    //чистит файл перед тестом
    fstream file;
    cleanfile(path);
    //записываем сообщение через функцию

    string test_fig = "QKPBNRqkpbnr ";
    string wrong_fig = "Zxasdvm]lL12";

    //проверяем на правильных фигурах
    for (int i = 0; i < (int)test_fig.size(); i++) {
        CHECK(testfw.add_figure(test_fig[i], path));
    }
    //проверяем на неправильных фигурах
    for (int i = 0; i < (int)wrong_fig.size(); i++) {
        CHECK(!testfw.add_figure(wrong_fig[i], path));
    }
}
