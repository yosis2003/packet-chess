#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ChessPiece.h"
using namespace sf;
using namespace std;

class Tile
{
    protected:
    Vector2f upperLeft;
    Vector2f lowerRight;
    Vector2f center;
    Vector2f matrixPos; //chess board piece positions starts at 0,0 goes to 7,7

    public:
    Vector2f getCenter();
    vector <ChessPiece*> Defenders;
    Tile(Vector2f topLeft, Vector2f botRight, Vector2f matPos);
    Vector2f getMatrix();
};