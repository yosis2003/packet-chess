#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
    public:
    Bishop(Vector2f pos, int color, Sprite sprite);
    bool isLegal(Vector2f testPos, vector<ChessPiece*> chessVec); //Try the override keyword later
};