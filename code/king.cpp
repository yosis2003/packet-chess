#include "King.h"
#include "ChessPiece.h"


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

bool King::hasMoved(){
    if (moved == true){
        return true;
    }
    else{
        return false;
    }
}

King::King(Vector2f pos, int passedColor) : ChessPiece(pos, passedColor){
    color = passedColor;
    getColor();
}
bool Pawn::hasMoved(){
    if (moved == true){
        return true;
    }
    else{
        return false;
    }
}
bool Rook::hasMoved(){
    if (moved == true){
        return true;
    }
    else{
        return false;
    }
}

