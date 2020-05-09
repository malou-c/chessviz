#include "../src/map.h"
#include "thirdparty/catch.hpp"

TEST_CASE("MAP : CN_typefig()", "[MAP]")
{
    Map map;
    SECTION("true value figure")
    {
        map.step = "QRNBK";
        //должен принять и вывести true
        for (int i = 0; i < (int)map.step.size(); i++) {
            CHECK(map.CN_typefig());
        }
    }
    SECTION("true value peshka")
    {
        //должен принять и вывести true для пешек
        map.step = "abcdefgh";
        for (int i = 0; i < (int)map.step.size(); i++) {
            map.step_id = i;
            CHECK(map.CN_typefig());
        }
    }

    SECTION("false value (random)")
    {
        //не должен принимать и вывести false
        map.step = "po154lvio";
        for (int i = 0; i < (int)map.step.size(); i++) {
            map.step_id = i;
            CHECK(!map.CN_typefig());
        }
    }
}

TEST_CASE("MAP : CN_cellfig()", "[MAP]")
{
    Map map;
    SECTION("up figure")
    {
        //проверяем взятие фигуры с поля
        map.cell_pos.x = 1;
        map.cell_pos.y = 1;
        map.step_fig = 'R';
        char now_fig = map.map[map.cell_pos.x][map.cell_pos.y];
        REQUIRE(map.CN_cellfig());
        CHECK(map.map[map.cell_pos.x][map.cell_pos.y] == ' ');
        CHECK(now_fig == map.step_fig);
    }
    SECTION("up wrong figure")
    {
        //пробум взять не ту фигуру
        map.cell_pos.x = 2;
        map.cell_pos.y = 1;
        map.step_fig = 'K';
        CHECK(!map.CN_cellfig());
    }
}

TEST_CASE("MAP : CN_typemove()", "[MAP]")
{
    Map map;
    SECTION("down figure: take enemy fig")
    {
        map.step_id = 0; //обнуляем id
        map.step_fig = 'p';
        map.step = "xh1";
        REQUIRE(map.CN_typemove());
        CHECK(map.map[map.cell_pos.x][map.cell_pos.y] == 'p');
    }
    SECTION("down figure: in void cell")
    {
        map.step_id = 0; //обнуляем id
        map.step_fig = 'p';
        map.step = "-e5";
        REQUIRE(map.CN_typemove());
        CHECK(map.map[map.cell_pos.x][map.cell_pos.y] == 'p');
    }
    SECTION("wrong down figure: take enemy fig")
    {
        map.step_id = 0; //обнуляем id
        map.step_fig = 'p';
        map.step = "-h2";
        REQUIRE(!map.CN_typemove());
    }
    SECTION("wrong down figure: in void cell")
    {
        map.step_id = 0; //обнуляем id
        map.step_fig = 'p';
        map.step = "xa5";
        REQUIRE(!map.CN_typemove());
    }
}
