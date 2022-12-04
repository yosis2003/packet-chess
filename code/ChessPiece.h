#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

class ChessPiece
{
    private:
    int value = 0;
    Vector2f position;
    Vector2f prevPos;
    vector <Vector2f> legalMoves;
    Sprite chessSprite;
    int color = 0;

    public:
    virtual bool isLegal(Vector2f testPos) = 0;
    Vector2f getPosition();
    ChessPiece(Vector2f positioning, int coloring);
    Vector2f getLastPos();
    int getValue();
    int getColor();
};