#include <cstdlib>
#include <iostream>
#include <string>

#include "FileWork.h"
#include "map.h"

int main()
{
    Map map;
    std::string path_html = "chesse.html";
    FileWork fw;
    //проверяем нотацию попутно рисуя ходы
    if (map.CheckNotation("gamelog.txt")) {
        //инфо в консоль
        std::cout << "Status: Good" << std::endl;
        //инфо о статусе завершения в html
        fw.add_complete(path_html);
    } else {
        //инфо об ошибке в консоль
        std::cout << "Status: Bad" << std::endl;
        std::cout << "Wrong step: " << map.step << std::endl;
        //инфо о статусе завершения в html
        fw.add_error(map.step, path_html);
        //рисуем конец html файла
        fw.add_end(path_html);
        //открываем html нотацию
        system("xdg-open chesse.html");
        return -1;
    }
    //рисуем конец html файла
    fw.add_end(path_html);

    //открываем html нотацию
    system("xdg-open chesse.html");
    return 0;
}