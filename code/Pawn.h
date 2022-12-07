#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
    private:
    bool moved;
    int epGraves;

    public:
    Pawn(Vector2f pos, int color, Sprite sprite);
    bool hasMoved();
    bool isLegal(Vector2f testPos, vector<ChessPiece*> chessVec); //Try the override keyword later
};