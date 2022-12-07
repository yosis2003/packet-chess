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
    if (abs(testPos.x - getLastPos().x) > 1 || abs(testPos.y - getLastPos().y) > 1){
        return false;
    }

    else{
        return true; //doesn't include the castling option yet
    }
}

