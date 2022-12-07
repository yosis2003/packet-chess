#include "Knight.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;

Knight::Knight(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos; 
    position = pos;
    color = passedColor;
    value = 3;
    chessSprite = sprite;
}
bool Knight::isLegal(Vector2f testPos, vector<ChessPiece*> chessVec){
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

    if (abs(testPos.x - position.x) == 2 && abs(testPos.y - position.y) == 1 || (abs(testPos.x - position.x) == 1 && abs(testPos.y - position.y) == 2)){
        return true;
    }
    else{
        return false;
    }
}

