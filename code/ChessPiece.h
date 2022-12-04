#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

class ChessPiece
{
    private:
    vector <Vector2f> legalMoves;
    Sprite chessSprite;
    protected:
    int value = 0;
    int color = 0;
    Vector2f position;
    Vector2f prevPos;

    public:
    virtual bool isLegal(Vector2f testPos) = 0;
    Vector2f getPosition();
    ChessPiece(Vector2f positioning, int coloring);
    Vector2f getLastPos();
    int getValue();
    int getColor();

};