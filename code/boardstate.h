#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "ChessPiece.h"
using namespace sf;
using namespace std;

class BoardState{
    public:
    int boardValue = 0;
    int turn = 0;
    vector<ChessPiece*> Board;
    
};
