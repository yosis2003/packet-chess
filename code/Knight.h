#include "ChessPiece.h"

class Knight
{
    public:
    Knight(Vector2f pos, int color);
    bool isLegal(Vector2f testPos); //Try the override keyword later
};