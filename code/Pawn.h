#include "ChessPiece.h"

class Pawn
{
    private:
    bool moved;
    bool doublemoved;

    public:
    Pawn(Vector2f pos, int color);
    bool hasMoved();
    bool hasDoubleMoved();
    bool isLegal(Vector2f testPos); //Try the override keyword later
};