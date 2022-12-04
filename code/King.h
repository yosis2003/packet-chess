#include "ChessPiece.h"

class King
{
    private:
    bool moved;

    public:
    King(Vector2f pos, int color);
    bool isLegal(Vector2f testPos); //Try the override keyword later
    bool hasMoved();
};