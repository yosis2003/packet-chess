#include "ChessPiece.h"

class King : public ChessPiece
{
    private:
    bool moved;

    public:
    King(Vector2f pos, int colovvvvvvvvvvvvvvvvvr);
    bool isLegal(Vector2f testPos); //Try the override keyword later
    bool hasMoved();
};