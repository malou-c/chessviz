#include "map.h"

using namespace std;
// проверяет правильность позиции и записывает ее в переменную
bool Map::found_pos(char x, char y)
{
    cell_pos.isOK = false;
    for (int i = 1; i < 9; i++) {
        if (map[0][i] == x) {
            cell_pos.y = i;
            cell_pos.isOK = true;
            step_id++;
            break;
        }
    }
    for (int j = 1; j < 9; j++) {
        if (map[j][0] == y) {
            cell_pos.x = j;
            cell_pos.isOK = true;
            step_id++;
            break;
        }
    }

    return cell_pos.isOK;
}
//проверяет тип фигуры
bool Map::CN_typefig()
{
    std::string typefig = "QRNBK";
    for (int i = 0; i < (int)typefig.size(); i++) {
        if (step[step_id] == typefig[i]) {
            step_id++;
            step_fig = typefig[i];
            return true;
        }
    }
    if ((int)step[step_id] >= 97 && (int)step[step_id] <= 104) {
        step_fig = 'P';
        return true;
    }

    return false;
}
//проверяет тип хода
bool Map::CN_typemove()
{
    std::string typemove = "-x";
    for (int i = 0; i < (int)typemove.size(); i++) {
        if (step[step_id] == typemove[i]) {
            //след элемент нотации
            step_id++;
            //проверяем aim cell
            if (!found_pos(step[step_id], step[step_id + 1])) {
                std::cout << "error: cell aim wrong" << std::endl;
                return false;
            }
            if (typemove[i] == '-' && map[cell_pos.x][cell_pos.y] != ' ') {
                std::cout << "error: cell have figure, need void cell";
                return false;
            }
            if (typemove[i] == 'x' && map[cell_pos.x][cell_pos.y] == ' ') {
                std::cout
                        << "error: cell dont have figure, need figure in cell";
                return false;
            }
            //ставим на клетку фигуру
            map[cell_pos.x][cell_pos.y] = step_fig;
            return true;
        }
    }
    return false;
}
//проверяем есть ли в клетке данная фигура
bool Map::CN_cellfig()
{
    int up_reg = 32;
    //рассматривает верхний (+32) и  нижний регистры
    if ((int)map[cell_pos.x][cell_pos.y] == (int)step_fig
        || (int)map[cell_pos.x][cell_pos.y] == (int)step_fig + up_reg) {
        //берем  фигуру
        step_fig = map[cell_pos.x][cell_pos.y];
        //убираем фигуру с клетки
        map[cell_pos.x][cell_pos.y] = ' ';

        return true;
    } else {
        std::cout << map[cell_pos.x][cell_pos.y] << std::endl;
        std::cout << cell_pos.x << "  " << cell_pos.y << std::endl;
        std::cout << (int)map[cell_pos.x][cell_pos.y] << std::endl;
        std::cout << (int)step_fig << std::endl;
        return false;
    }
}

bool Map::CheckNotation(std::string filename)
{
    FileWork fw;
    std::string html_path = "chesse.html";
    std::fstream fh;
    //рисуем голову  в  html
    fw.add_head(html_path);

    //допустимые значения для проверки
    fstream file;
    file.open(filename, file.in);
    if (!file.is_open()) {
        cout << "error: file notation not found" << endl;
        return -1;
    }
    while (!file.eof()) {
        file >> step;
        //вот тут мы работаем с  ходом
        if (!CN_typefig()) {
            std::cout << "error: figure wrong" << std::endl;
            return false;
        }
        if (!found_pos(step[step_id], step[step_id + 1])) {
            std::cout << "error: cell start wrong" << std::endl;
            return false;
        }

        if (!CN_cellfig()) {
            std::cout << "error: in cell wrong figure" << std::endl;
            return false;
        }
        if (!CN_typemove()) {
            std::cout << "error: move wrong" << std::endl;
            return false;
        }

        //рисуем ход в  html
        fw.add_step(step, html_path);
        for (int i = 1; i < 9; i++) {
            fw.add_msg("<tr>", html_path);
            for (int j = 1; j < 9; j++) {
                fw.add_figure(map[i][j], html_path);
            }
            fw.add_msg("</tr>", html_path);
        }
        fw.add_msg("</table>", html_path);
        //обнуление текущего хода
        step = "";
        step_id = 0;
        step_fig = ' ';
        step_move = ' ';
    }

    //закрываем нотацию
    file.close();
    return true;
}
