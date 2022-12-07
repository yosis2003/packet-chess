#include "ChessPiece.h"
#include "boardstate.h"

using namespace sf;
using namespace std;

ChessPiece::ChessPiece(Vector2f positioning, int coloring){
    position = positioning;
    color = coloring;
}

Vector2f ChessPiece::getLastPos(){
    return prevPos;
}

Vector2f ChessPiece::getPosition(){
    return position;
}
int ChessPiece::getValue(){
    return value;
}
int ChessPiece::getColor(){
    return color;
}

void ChessPiece::positionSetter(Vector2f pos) {
    position = pos;
}
/*bool ChessPiece::isLegal(Vector2f testPos, vector<ChessPiece*> chessVec) {
    return false;

}*/
Sprite ChessPiece::getSprite(){
    return chessSprite;
}

void ChessPiece::previousPositionSetter(Vector2f pos) {
    pos = prevPos;
}
