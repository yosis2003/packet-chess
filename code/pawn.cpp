#include "Pawn.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;


bool Pawn::hasMoved(){
    if (moved == true || (getPosition() != getLastPos())){
        return true;
    }
    else{
        return false;
    }
}
bool Pawn::isLegal(Vector2f testPos, vector<ChessPiece*> chessVec){
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
    if(color == 0)
    {
        if ((testPos.y - position.y) < 0) {
            for (int i = 0; i < chessVec.size(); i++)
            {
                if (position.y == 3 && chessVec[i]->getPosition().y == (testPos.y + 1) && chessVec[i]->getColor() == 1 && chessVec[i]->hasDoubleMoved() == true && abs(position.x - testPos.x) == 1)
                {
                    chessVec[i]->chessSprite.setPosition(Vector2f(150, 100 + epGraves * 50));
                    chessVec[i]->positionSetter(Vector2f(10,10));
                    epGraves += 1;
                    return true;
                }
            }
            if((testPos.y - position.y) == -2 && (testPos.x-position.x == 0))
            {
                if(moved == false)
                {
                    moved = true;
                    doublemoved = true;
                    return true;
                }
                else if (moved == true) {
                    return false;
                }
            }
            else if ((testPos.y - position.y) == -1 && (testPos.x - position.x == 0)) 
            {
                for(int i = 0; i < chessVec.size(); i++)
                {
                    if(chessVec[i]->getPosition() == testPos)
                    {
                        return false;
                    }
                }
                    moved = true;
                    return true;
            }
            else if (((testPos.y - position.y) == -1 && abs(testPos.x - position.x)) == 1) {
                for(int i = 0; i < chessVec.size(); i++)
                {
                    if(chessVec[i]->getPosition() == testPos && chessVec[i]->getColor() == 1)
                    {
                        moved = true;
                        return true;
                    }
                }
            }    
        }
        else {
            return false;
        }
    }
    else if(color == 1)
    {
        if ((testPos.y - position.y) > 0) {
            for (int i = 0; i < chessVec.size(); i++)
            {
                if (position.y == 4 && chessVec[i]->getPosition().y == (testPos.y - 1) && chessVec[i]->getColor() == 0 && chessVec[i]->hasDoubleMoved() == true && abs(position.x - testPos.x) == 1)
                {
                    return true;
                }
            }
            if((testPos.y - position.y) == 2 && (testPos.x-position.x == 0))
            {
                if(moved == false)
                {
                    moved = true;
                    doublemoved = true;
                    return true;
                }
                else if (moved == true)
                {
                    return false;
                }
            }
            else if ((testPos.y - position.y) == 1 && (testPos.x - position.x == 0)) 
            {
                for(int i = 0; i < chessVec.size(); i++)
                {
                    if(chessVec[i]->getPosition() == testPos)
                    {
                        return false;
                    }
                }
                    moved = true;
                    return true;
            }
            else if (((testPos.y - position.y) == 1 && abs(testPos.x - position.x)) == 1) {
                for(int i = 0; i < chessVec.size(); i++)
                {
                    if(chessVec[i]->getPosition() == testPos && chessVec[i]->getColor() == 0)
                    {
                        moved = true;
                        return true;
                    }
                }
            }
        }
        else {
            return false;
        }
    }
    if (abs(testPos.x - getLastPos().x) > 1 || (abs(testPos.y - getLastPos().y) > 2 ||abs(testPos.y - getLastPos().y) < 1)){
        return false;
    }
    else if (abs(testPos.x - getLastPos().x) >= 0 && abs(testPos.x - getLastPos().x) <= 1 && (abs(testPos.y - getLastPos().y) == 1 || (abs(testPos.y - getLastPos().y) == 2 && moved == false))){
        return true;
    }
}

Pawn::Pawn(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos;
    color = passedColor;
    position == pos;
    value = 1;
    chessSprite = sprite;
    doublemoved = false;
    moved = false;
    epGraves = 0;
}