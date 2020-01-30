#include "pch.h"
#include "Map.h"

Map::Map()
{
    //ctor
}

Map::~Map()
{
    //dtor
}

void Map::DrawMap()
{
    draw.DrawMap(HEIGHT, WIDTH, map);
}

short Map::getMap(short x, short y) const
{
    short a = map[y][x];
    return a;
}

void Map::setMap(short x, short y)
{
    map[y][x] = 2;

}
