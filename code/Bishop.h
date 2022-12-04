#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
    public:
    Bishop(Vector2f pos, int color);
    bool isLegal(Vector2f testPos); //Try the override keyword later
};