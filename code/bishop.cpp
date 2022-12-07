#include "Bishop.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;

Bishop::Bishop(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos;
    color = passedColor;
    position = pos;
    value = 3;
    chessSprite = sprite;

}

bool Bishop::isLegal(Vector2f testPos,  vector<ChessPiece*> chessVec){
    for(int i = 0; i < chessVec.size(); i++)
    {
        if(chessVec[i]->getColor() == color)
        {
            if(chessVec[i]->getPosition() == testPos)
            {
                return false;
            }
        }
    }
    if (abs(testPos.x - position.x) == abs(testPos.y - position.y))
    {
        return true;
    }
    else{
        return false;
    }
}