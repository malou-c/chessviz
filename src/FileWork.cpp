
#include "FileWork.h"

using namespace std;
fstream fs;

void FileWork::add_msg(string msg, string path)
{
    fs.open(path, fs.out | fs.app);
    if (fs.is_open()) {
        fs << msg;

    } else {
        cout << "error file" << endl;
    }
    fs.close();
}
void FileWork::add_head(string path)
{
    string head = R"( 
 <!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>chessviz</title>
  <style type="text/css">
    table.chessboard {
      border: 5px solid #333;
      border-collapse: collapse;
      height: 320px;
      margin: 20px;
      width: 320px;
    }
    table.chessboard caption {
      text-align: left;
    }
    table.chessboard td {
      background-color: #fff;
      font-size: 25px;
      height: 40px;
      text-align: center;
      vertical-align: middle;
      width: 40px;
    }
    table.chessboard tr:nth-child(odd) td:nth-child(even),
    table.chessboard tr:nth-child(even) td:nth-child(odd) {
      background-color: #999;
    }

    table.chessboard .white.king:before   { content: "\2654"; }
    table.chessboard .white.queen:before  { content: "\2655"; }
    table.chessboard .white.rook:before   { content: "\2656"; }
    table.chessboard .white.bishop:before { content: "\2657"; }
    table.chessboard .white.knight:before { content: "\2658"; }
    table.chessboard .white.pawn:before   { content: "\2659"; }

    table.chessboard .black.king:before   { content: "\265A"; }
    table.chessboard .black.queen:before  { content: "\265B"; }
    table.chessboard .black.rook:before   { content: "\265C"; }
    table.chessboard .black.bishop:before { content: "\265D"; }
    table.chessboard .black.knight:before { content: "\265E"; }
    table.chessboard .black.pawn:before   { content: "\265F"; }
  </style>
</head>
<body>)";
    fs.open(path, fs.out | fs.trunc);
    if (fs.is_open()) {
        fs << head;

    } else {
        cout << "error file" << endl;
    }
    fs.close();
}

void FileWork::add_step(std::string step, std::string path)
{
    string msg = R"(
    <table class="chessboard">
    <caption>)"
            + step + "</caption>";

    fs.open(path, fs.out | fs.app);
    if (fs.is_open()) {
        fs << msg;
    } else {
        cout << "error file" << endl;
    }
    fs.close();
}

void FileWork::add_end(std::string path)
{
    string msg = R"(
        
      </body>
      </html>
    )";

    fs.open(path, fs.out | fs.app);
    if (fs.is_open()) {
        fs << msg;
    } else {
        cout << "error file" << endl;
    }
    fs.close();
}

void FileWork::add_error(std::string step, std::string path)
{
    string msg = R"(
    <p> <font size="5" color="black" face="Arial">Статус нотации: </font> 
    <font size="5" color="red" face="Arial">Bad</font></p>

    <b> <font size="5" color="black" face="Arial">Ход с ошибкой: )"
            + step + "</font></b>";

    fs.open(path, fs.out | fs.app);
    if (fs.is_open()) {
        fs << msg;
    } else {
        cout << "error file" << endl;
    }
    fs.close();
}
void FileWork::add_complete(std::string path)
{
    string msg = R"(
    <p> <font size="5" color="black" face="Arial">Статус нотации: </font> 
    <font size="5" color="green" face="Arial">Good</font></p>

    )";

    fs.open(path, fs.out | fs.app);
    if (fs.is_open()) {
        fs << msg;
    } else {
        cout << "error file" << endl;
    }
    fs.close();
}

bool FileWork::add_figure(char figure, std::string path)
{
    string str_fig = "";
    switch (figure) {
        //белые
    case 'k':
        str_fig = "white king";
        break;
    case 'q':
        str_fig = "white queen";
        break;
    case 'r':
        str_fig = "white rook";
        break;
    case 'n':
        str_fig = "white knight";
        break;
    case 'b':
        str_fig = "white bishop";
        break;
    case 'p':
        str_fig = "white pawn";
        break;
        //черные
    case 'K':
        str_fig = "black king";
        break;
    case 'Q':
        str_fig = "black queen";
        break;
    case 'R':
        str_fig = "black rook";
        break;
    case 'N':
        str_fig = "black knight";
        break;
    case 'B':
        str_fig = "black bishop";
        break;
    case 'P':
        str_fig = "black pawn";
        break;
        // пустое поле
    case ' ':
        str_fig = " ";
        break;

    default:
        std::cout << "error read figure: not found";
        return false;
        break;
    }
    string msg = R"(
      <td><span class=")"
            + str_fig + R"("></span></td>)";

    fs.open(path, fs.out | fs.app);
    if (fs.is_open()) {
        fs << msg;
    } else {
        cout << "error file" << endl;
    }
    fs.close();
    return true;
}
