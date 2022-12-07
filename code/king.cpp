#include "King.h"
#include "ChessPiece.h"


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

using namespace std;
using namespace sf;

bool King::hasMoved(){
    if (moved == true || (getPosition() != getLastPos())){
        moved = true;
        return true;
    }
    else{
        return false;
    }
}

King::King(Vector2f pos, int passedColor, Sprite sprite) : ChessPiece(pos, passedColor){
    prevPos = pos;
    color = passedColor;
    position = pos;
    value = 50;
    chessSprite = sprite;
    
}
bool King::isLegal(Vector2f testPos, vector<ChessPiece*> chessVec){

    if(testPos == Vector2f(0,7*(1-color)) && chessVec[24*(1-color)]->hasMoved() == false && hasMoved() == false) // LEFT CASTLE
    {
        for(int i = 0; i < chessVec.size(); i++)
        {
            if(chessVec[i]->getPosition() == Vector2f(1,7*(1-color)) || chessVec[i]->getPosition() == Vector2f(2,7*(1-color)) || chessVec[i]->getPosition() == Vector2f(3,7*(1-color)))
            {
                return false;
            }
            
        }
        position.x -= 2;
        chessVec[24*(1-color)]->positionSetter(Vector2f(chessVec[24*(1-color)]->getPosition().x + 3, chessVec[24*(1-color)]->getPosition().y));
        chessVec[24*(1-color)]->chessSprite.setPosition(Vector2f(chessVec[24*(1-color)]->chessSprite.getPosition().x + 93*3, chessVec[24*(1-color)]->chessSprite.getPosition().y));
        return false;
    }
    else if(testPos == Vector2f(7,7*(1-color)) && chessVec[7 + 24*(1-color)]->hasMoved() == false && hasMoved() == false) // RIGHT CASTLE
    {
        for(int i = 0; i < chessVec.size(); i++)
        {
            if(chessVec[i]->getPosition() == Vector2f(5,7*(1-color)) || chessVec[i]->getPosition() == Vector2f(6,7*(1-color)))
            {
                return false;
            }
            
        }
        position.x += 2;
        chessVec[7 + 24*(1-color)]->positionSetter(Vector2f(chessVec[7 + 24*(1-color)]->getPosition().x - 2, chessVec[7 + 24*(1-color)]->getPosition().y));
        chessVec[7 + 24*(1-color)]->chessSprite.setPosition(Vector2f(chessVec[7 + 24*(1-color)]->chessSprite.getPosition().x - 93*2, chessVec[7 + 24*(1-color)]->chessSprite.getPosition().y));
        return false;
    }

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
    if ((abs(testPos.x - position.x) == 1 && abs(testPos.y - position.y) == 0) || (abs(testPos.x - position.x) == 0 && abs(testPos.y - position.y) == 1) || (abs(testPos.x - position.x) == 1 && abs(testPos.y - position.y) == 1)) {
        moved = true;
        return true;
    }

    else{
        return false; //doesn't include the castling option yet
    }
}

