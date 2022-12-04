#include "Rook.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;


bool Rook::hasMoved(){
    if (moved == true || (getPosition() != getLastPos())){
        return true;
    }
    else{
        return false;
    }
}

bool Rook::isLegal(Vector2f testPos){
    if (getLastPos().x == testPos.x || getLastPos().y == testPos.y){
        return true;
    }
}
Rook::Rook(Vector2f pos, int passedColor)  : ChessPiece(pos, passedColor){
    position = pos;
    color = passedColor;
}