#include "boardstate.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;

int BoardState::getBoardValue(){
    return boardValue;
}
int BoardState::getTurn(){
    return turn;
}
