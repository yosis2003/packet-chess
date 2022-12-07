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
    if (position.x == testPos.x || position.y == testPos.y){
        if((position.x - testPos.x) > 0)
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().x < position.x && chessVec[i]->getPosition().x > testPos.x && position.y == chessVec[i]->getPosition().y)
                {
                    return false;
                }
            }
        }
        else if((position.x - testPos.x) < 0)
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().x > position.x && chessVec[i]->getPosition().x < testPos.x && position.y == chessVec[i]->getPosition().y)
                {
                    return false;
                }
            }
        }
        else if((position.y - testPos.y) < 0)
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().y > position.y && chessVec[i]->getPosition().y < testPos.y && position.x == chessVec[i]->getPosition().x)
                {
                    return false;
                }
            }
        }
        else if((position.y - testPos.y) > 0)
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().y < position.y && chessVec[i]->getPosition().y > testPos.y && position.x == chessVec[i]->getPosition().x)
                {
                    return false;
                }
            }
        }
        return true;
    }
    else {
        return false;
    }
}
Rook::Rook(Vector2f pos, int passedColor, Sprite sprite)  : ChessPiece(pos, passedColor){
    prevPos = pos;
    position = pos;
    color = passedColor;
    value = 5;
    chessSprite = sprite;
    //vector <Vector2f> RookLegal;
    
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