#include "ChessPiece.h"

class Rook
{
    private:
    bool moved;

    public:
    Rook(Vector2f pos, int color);
    bool isLegal(Vector2f testPos); //Try the override keyword later
    bool hasMoved();
};