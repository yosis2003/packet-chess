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
        if((testPos.x - position.x) > 0 && (testPos.y - position.y) > 0) // Down and to the right
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().x < testPos.x && chessVec[i]->getPosition().y < testPos.y && chessVec[i]->getPosition().x > position.x && chessVec[i]->getPosition().y > position.y && abs(chessVec[i]->getPosition().x - testPos.x) == abs(chessVec[i]->getPosition().y - testPos.y))
                {
                    return false;
                }
            }
        }
        else if((testPos.x - position.x) > 0 && (testPos.y - position.y) < 0) // Up and to the right
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().x < testPos.x && chessVec[i]->getPosition().y > testPos.y && chessVec[i]->getPosition().x > position.x && chessVec[i]->getPosition().y < position.y && abs(chessVec[i]->getPosition().x - testPos.x) == abs(chessVec[i]->getPosition().y - testPos.y))
                {
                    return false;
                }
            }
        }
        else if((testPos.x - position.x) < 0 && (testPos.y - position.y) > 0) // Down and to the left
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().x > testPos.x && chessVec[i]->getPosition().y < testPos.y && chessVec[i]->getPosition().x < position.x && chessVec[i]->getPosition().y > position.y && abs(chessVec[i]->getPosition().x - testPos.x) == abs(chessVec[i]->getPosition().y - testPos.y))
                {
                    return false;
                }
            }
        }
        else if((testPos.x - position.x) < 0 && (testPos.y - position.y) < 0) // Up and to the left
        {
            for(int i = 0; i < chessVec.size(); i++)
            {
                if(chessVec[i]->getPosition().x > testPos.x && chessVec[i]->getPosition().y > testPos.y && chessVec[i]->getPosition().x < position.x && chessVec[i]->getPosition().y < position.y && abs(chessVec[i]->getPosition().x - testPos.x) == abs(chessVec[i]->getPosition().y - testPos.y))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}