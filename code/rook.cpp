#include "Rook.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;


bool Rook::hasMoved(){
    if (moved == true || (getPosition() != getLastPos())){
        moved = true;
        return true;
    }
    else{
        return false;
    }
}

bool Rook::isLegal(Vector2f testPos, vector<ChessPiece*> chessVec){
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
    if (getPosition().x == testPos.x || getPosition().y == testPos.y){
        return true;
    }
    else {
        return false;
    }
    /*
    Vector2f Difference(testPos.x - position.x, testPos.y - position.y);
    for(int i = 0; i < RookLegalMoves.size(); i++)
    {
        if(Difference.x == RookLegalMoves[i].x && Difference.y == RookLegalMoves[i].y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    */
}
Rook::Rook(Vector2f pos, int passedColor, Sprite sprite)  : ChessPiece(pos, passedColor){
    prevPos = pos;
    position = pos;
    color = passedColor;
    value = 5;
    chessSprite = sprite;
    vector <Vector2f> RookLegal;
    
    /*
    for (int i = 1; i <= 7; i++)
    {
        RookLegalMoves.push_back(Vector2f(0, i));
    }
    for (int i = 1; i <= 7; i++)
    {
        RookLegalMoves.push_back(Vector2f(i, 0));
    }
    for (int i = 1; i < 7; i++)
    {
        RookLegalMoves.push_back(Vector2f(-i, 0));
    }
    for (int i = 1; i <= 7; i++)
    {
        RookLegalMoves.push_back(Vector2f(0, -i));
    }
    */
}