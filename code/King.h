#pragma once
#include "ChessPiece.h"

class King : public ChessPiece
{
    public:
    King(Vector2f pos, int color, Sprite sprite);
    bool isLegal(Vector2f testPos, vector<ChessPiece*> chessVec); //Try the override keyword later
    bool hasMoved();
};