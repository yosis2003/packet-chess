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
    protected:
    int value = 0;
    int color = 0;//0 is black 1 is white
    Vector2f position;
    Vector2f prevPos;

    public:
    Sprite chessSprite;
    virtual bool isLegal(Vector2f testPos, vector<ChessPiece*> chessVec) = 0;
    Vector2f getPosition();
    ChessPiece(Vector2f positioning, int coloring);
    Vector2f getLastPos();
    int getValue();
    int getColor();
    Sprite getSprite();
    void positionSetter(Vector2f pos);
    void previousPositionSetter(Vector2f pos);

};