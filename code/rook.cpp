#include "Rook.h"
#include "ChessPiece.h"

using namespace sf;
using namespace std;


bool Rook::hasMoved(){
    if (moved == true){
        return true;
    }
    else{
        return false;
    }
}