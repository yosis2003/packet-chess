#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece
{
    private:
    int epGraves;

    public:
    Pawn(Vector2f pos, int color, Sprite sprite);
    bool hasMoved();
    bool isLegal(Vector2f testPos, vector<ChessPiece*> chessVec);
};