#include "ChessPiece.h"

class Queen
{
    public:
    Queen(Vector2f pos, int color);
    bool isLegal(Vector2f testPos); //Try the override keyword later
};