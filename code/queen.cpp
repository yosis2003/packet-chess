#include "Queen.h"
#include <cmath>

using namespace sf;


bool Queen::isLegal(Vector2f testPos, vector<ChessPiece*> chessVec){
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
    if ((abs(testPos.x - position.x) == 0 || abs(testPos.y - position.y) == 0))
    {
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
    else if(abs(testPos.x - position.x) == abs(testPos.y - position.y))
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
    }
    else
    {
        return false;
    }
    
}

Queen::Queen(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos;
    position = pos;
    color = passedColor;
    value = 9;
    chessSprite = sprite;
}