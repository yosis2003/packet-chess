#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece
{
    private:
    bool moved;
    vector <Vector2f> RookLegalMoves;

    public:
    Rook(Vector2f pos, int color, Sprite sprite);
    bool isLegal(Vector2f testPos, vector<ChessPiece*> chessVec);
    bool hasMoved();
};