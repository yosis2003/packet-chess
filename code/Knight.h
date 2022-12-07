#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
    public:
    Knight(Vector2f pos, int color, Sprite sprite);
    bool isLegal(Vector2f testPos, vector<ChessPiece*> chessVec); //Try the override keyword later
};