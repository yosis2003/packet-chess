// Packet Chess Game
// Creators: Matthew Craig, Yousif Alnomani
// CISP 400


#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "boardstate.h"
#include "ChessPiece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Sprites.h"
using namespace sf;
using namespace std;

void boardLoaderBlack(vector<ChessPiece*> &CHPV )
{
    // Row One
    Rook* RookBlackLeft = new Rook(Vector2f(0,0), 1, BlackRookSprite);
    Knight* KnightBlackLeft = new Knight(Vector2f(1,0), 1, BlackKnightSprite);
    Bishop* BishopBlackLeft = new Bishop(Vector2f(2,0), 1, BlackBishopSprite);
    Queen* QueenBlack = new Queen(Vector2f(3,0), 1, BlackQueenSprite);
    King* KingBlack = new King(Vector2f(4,0), 1, BlackKingSprite);
    Bishop* BishopBlackRight = new Bishop(Vector2f(5,0), 1, BlackBishopSprite);
    Knight* KnightBlackRight = new Knight(Vector2f(6,0), 1, BlackKnightSprite);
    Rook* RookBlackRight = new Rook(Vector2f(7,0), 1, BlackRookSprite);
    // Row Two
    Pawn* PawnBlackZero = new Pawn(Vector2f(0,1), 1, BlackPawnSprite);
    Pawn* PawnBlackOne = new Pawn(Vector2f(1,1), 1, BlackPawnSprite);
    Pawn* PawnBlackTwo = new Pawn(Vector2f(2,1), 1, BlackPawnSprite);
    Pawn* PawnBlackThree = new Pawn(Vector2f(3,1), 1, BlackPawnSprite);
    Pawn* PawnBlackFour = new Pawn(Vector2f(4,1), 1, BlackPawnSprite);
    Pawn* PawnBlackFive = new Pawn(Vector2f(5,1), 1, BlackPawnSprite);
    Pawn* PawnBlackSix = new Pawn(Vector2f(6,1), 1, BlackPawnSprite);
    Pawn* PawnBlackSeven = new Pawn(Vector2f(7,1), 1, BlackPawnSprite);
    // Add To Vector
    CHPV.push_back(RookBlackLeft);
    CHPV.push_back(KnightBlackLeft);
    CHPV.push_back(BishopBlackLeft);
    CHPV.push_back(QueenBlack);
    CHPV.push_back(KingBlack);
    CHPV.push_back(BishopBlackRight);
    CHPV.push_back(KnightBlackRight);
    CHPV.push_back(RookBlackRight);
    CHPV.push_back(PawnBlackZero);
    CHPV.push_back(PawnBlackOne);
    CHPV.push_back(PawnBlackTwo);
    CHPV.push_back(PawnBlackThree);
    CHPV.push_back(PawnBlackFour);
    CHPV.push_back(PawnBlackFive);
    CHPV.push_back(PawnBlackSix);
    CHPV.push_back(PawnBlackSeven);
}

void boardLoaderWhite(vector<ChessPiece*> &CHPV )
{
    // Row Seven
    Rook* RookWhiteLeft = new Rook(Vector2f(0,7), 0, WhiteRookSprite);
    Knight* KnightWhiteLeft = new Knight(Vector2f(1,7), 0, WhiteKnightSprite);
    Bishop* BishopWhiteLeft = new Bishop(Vector2f(2,7), 0, WhiteBishopSprite);
    Queen* QueenWhite = new Queen(Vector2f(3,7), 0, WhiteQueenSprite);
    King* KingWhite = new King(Vector2f(4,7), 0, WhiteKingSprite);
    Bishop* BishopWhiteRight = new Bishop(Vector2f(5,7), 0, WhiteBishopSprite);
    Knight* KnightWhiteRight = new Knight(Vector2f(6,7), 0, WhiteKnightSprite);
    Rook* RookWhiteRight = new Rook(Vector2f(7,7), 0, WhiteRookSprite);
    // Row Eight
    Pawn* PawnWhiteZero = new Pawn(Vector2f(0,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteOne = new Pawn(Vector2f(1,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteTwo = new Pawn(Vector2f(2,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteThree = new Pawn(Vector2f(3,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteFour = new Pawn(Vector2f(4,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteFive = new Pawn(Vector2f(5,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteSix = new Pawn(Vector2f(6,6), 0, WhitePawnSprite);
    Pawn* PawnWhiteSeven = new Pawn(Vector2f(7,6), 0, WhitePawnSprite);
    // Add To Vector
    CHPV.push_back(RookWhiteLeft);
    CHPV.push_back(KnightWhiteLeft);
    CHPV.push_back(BishopWhiteLeft);
    CHPV.push_back(QueenWhite);
    CHPV.push_back(KingWhite);
    CHPV.push_back(BishopWhiteRight);
    CHPV.push_back(KnightWhiteRight);
    CHPV.push_back(RookWhiteRight);
    CHPV.push_back(PawnWhiteZero);
    CHPV.push_back(PawnWhiteOne);
    CHPV.push_back(PawnWhiteTwo);
    CHPV.push_back(PawnWhiteThree);
    CHPV.push_back(PawnWhiteFour);
    CHPV.push_back(PawnWhiteFive);
    CHPV.push_back(PawnWhiteSix);
    CHPV.push_back(PawnWhiteSeven);
}

void boardLoader(vector<ChessPiece*> &CHPV)
{
    boardLoaderBlack(CHPV);
    boardLoaderWhite(CHPV);
}

void boardDestroyer(vector<ChessPiece*> &CHPV)
{
    for(int i = 0; i < CHPV.size(); i++)
    {
        delete CHPV.at(i);
        CHPV.erase(CHPV.begin() + i);
    }
}

int main(){

    // Window Management
    float windowScale = 1.0f;
    int currentWindowWidth = VideoMode::getDesktopMode().width*windowScale;
    int currentWindowHeight = VideoMode::getDesktopMode().height*windowScale;
    VideoMode desktop(currentWindowWidth, currentWindowHeight);
    float aspect_ratio = currentWindowHeight / static_cast<float>(currentWindowWidth);
    RenderWindow window(desktop, "Packet Chess", Style::Default);

    // Text Management
    const int TB_Align_W = 2;
    const int TB_Align_H = 7;

    Font font;
    font.loadFromFile("fonts/SebastianSerifNbp-7weB.ttf");
    Text titleScreen;
    titleScreen.setFont(font);
    titleScreen.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.4f});
    const int TB_BackBorder = 5;
    RectangleShape textBoxBg;
    textBoxBg.setFillColor(Color(0,0,0,127));
    textBoxBg.setPosition({titleScreen.getPosition().x - TB_Align_W - TB_BackBorder, titleScreen.getPosition().y + TB_Align_H - TB_BackBorder });

    //Chess Board
    Texture ChessBoardTexture;
    ChessBoardTexture.loadFromFile("packet Chess Sprites/Chess Board.png");
    Sprite ChessBoardSprite;
    ChessBoardSprite.setTexture(ChessBoardTexture);
    const int chessBoardScale = 1;
    ChessBoardSprite.setOrigin((ChessBoardSprite.getLocalBounds().width)/2, (ChessBoardSprite.getLocalBounds().height)/2);
    ChessBoardSprite.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.5f});
    ChessBoardSprite.setScale(chessBoardScale, chessBoardScale);

    WhiteKingTexture.loadFromFile("packet Chess Sprites/White_King.png");
    BlackKingTexture.loadFromFile("packet Chess Sprites/Black_King.png");
    WhiteQueenTexture.loadFromFile("packet Chess Sprites/White_Queen.png");
    BlackQueenTexture.loadFromFile("packet Chess Sprites/Black_Queen.png");
    WhiteBishopTexture.loadFromFile("packet Chess Sprites/White_Bishop.png");
    BlackBishopTexture.loadFromFile("packet Chess Sprites/Black_Bishop.png");
    WhiteKnightTexture.loadFromFile("packet Chess Sprites/White_Knight.png");
    BlackKnightTexture.loadFromFile("packet Chess Sprites/Black_Knight.png");
    WhiteRookTexture.loadFromFile("packet Chess Sprites/White_Rook.png");
    BlackRookTexture.loadFromFile("packet Chess Sprites/Black_Rook.png");
    WhitePawnTexture.loadFromFile("packet Chess Sprites/White_Pawn.png");
    WhitePawnTexture.loadFromFile("packet Chess Sprites/Black_Pawn.png");

    WhiteKingSprite.setTexture(WhiteKingTexture);
    BlackKingSprite.setTexture(BlackKingTexture);
    WhiteQueenSprite.setTexture(WhiteQueenTexture);
    BlackQueenSprite.setTexture(BlackQueenTexture);
    WhiteBishopSprite.setTexture(WhiteBishopTexture);
    BlackBishopSprite.setTexture(BlackBishopTexture);
    WhiteKnightSprite.setTexture(WhiteKnightTexture);
    BlackKnightSprite.setTexture(BlackKnightTexture);
    WhiteRookSprite.setTexture(WhiteRookTexture);
    BlackRookSprite.setTexture(BlackRookTexture);
    WhitePawnSprite.setTexture(WhitePawnTexture);
    BlackPawnSprite.setTexture(BlackPawnTexture);
    
    WhiteKingSprite.setOrigin((WhiteKingSprite.getLocalBounds().width)/2, (WhiteKingSprite.getLocalBounds().height)/2);
    BlackKingSprite.setOrigin((BlackKingSprite.getLocalBounds().width)/2, (BlackKingSprite.getLocalBounds().height)/2);
    WhiteQueenSprite.setOrigin((WhiteQueenSprite.getLocalBounds().width)/2, (WhiteQueenSprite.getLocalBounds().height)/2);
    BlackQueenSprite.setOrigin((BlackQueenSprite.getLocalBounds().width)/2, (BlackQueenSprite.getLocalBounds().height)/2);
    WhiteBishopSprite.setOrigin((WhiteBishopSprite.getLocalBounds().width)/2, (WhiteBishopSprite.getLocalBounds().height)/2);
    BlackBishopSprite.setOrigin((BlackBishopSprite.getLocalBounds().width)/2, (BlackBishopSprite.getLocalBounds().height)/2);
    WhiteKnightSprite.setOrigin((WhiteKnightSprite.getLocalBounds().width)/2, (WhiteKnightSprite.getLocalBounds().height)/2);
    BlackKnightSprite.setOrigin((BlackKnightSprite.getLocalBounds().width)/2, (BlackKnightSprite.getLocalBounds().height)/2);
    WhiteRookSprite.setOrigin((WhiteRookSprite.getLocalBounds().width)/2, (WhiteRookSprite.getLocalBounds().height)/2);
    BlackRookSprite.setOrigin((BlackRookSprite.getLocalBounds().width)/2, (BlackRookSprite.getLocalBounds().height)/2);
    WhitePawnSprite.setOrigin((WhitePawnSprite.getLocalBounds().width)/2, (WhitePawnSprite.getLocalBounds().height)/2);
    BlackPawnSprite.setOrigin((BlackPawnSprite.getLocalBounds().width)/2, (BlackPawnSprite.getLocalBounds().height)/2);
    
    const int chessPieceScale = 2;

    WhiteKingSprite.setScale(chessPieceScale, chessPieceScale);
    BlackKingSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteQueenSprite.setScale(chessPieceScale, chessPieceScale);
    BlackQueenSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteBishopSprite.setScale(chessPieceScale, chessPieceScale);
    BlackBishopSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteKnightSprite.setScale(chessPieceScale, chessPieceScale);
    BlackKnightSprite.setScale(chessPieceScale, chessPieceScale);
    WhiteRookSprite.setScale(chessPieceScale, chessPieceScale);
    BlackRookSprite.setScale(chessPieceScale, chessPieceScale);
    WhitePawnSprite.setScale(chessPieceScale, chessPieceScale);
    BlackPawnSprite.setScale(chessPieceScale, chessPieceScale);




    /*----------------------------------*\
    **************************************
    |___|****                    ****|___|
    !!!!!***                      ***!!!!!
    |___|**     Main Game Loop     **|___|
    !!!!!***                      ***!!!!!
    |___|****                    ****|___|
    **************************************
    \*----------------------------------*/

    while(window.isOpen())
    {

        /*----------------------------------------*\
        ********************************************
        |___|****                          ****|___|
        !!!!!***                            ***!!!!!
        |___|**     Update Scene Segment     **|___|
        !!!!!***                            ***!!!!!
        |___|****                          ****|___|
        ********************************************
        \*----------------------------------------*/

        enum Mode
        {
            TITLE, MULTIPLAYER, SINGLEPLAYER, PUZZLE, ONLINE_MP
        };

        enum State
        {
            PLAYING, PAUSED, END
        };

        enum MouseState
        {
            Holding, Released
        };

        Mode gameMode = MULTIPLAYER;
        State gameState = PLAYING;

        while(gameMode == MULTIPLAYER && window.isOpen())
        {
            titleScreen.setString("Packet Chess!!");

            Event event;

            // TITLE
            const int titleSizeMult = 2;
            titleScreen.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.05f});
            titleScreen.setOrigin({(titleScreen.getLocalBounds().width)/2, (titleScreen.getLocalBounds().height)/2 });
            titleScreen.setScale(titleSizeMult, titleSizeMult);
            textBoxBg.setPosition({titleScreen.getPosition().x - TB_Align_W - TB_BackBorder, titleScreen.getPosition().y + TB_Align_H - TB_BackBorder });
            textBoxBg.setSize({titleScreen.getLocalBounds().width + TB_BackBorder*2 , titleScreen.getLocalBounds().height + TB_BackBorder*2});
            textBoxBg.setOrigin({(titleScreen.getLocalBounds().width)/2, (titleScreen.getLocalBounds().height)/2});
            textBoxBg.setScale(titleSizeMult, titleSizeMult);

            // GAME INITIALIZATION
            BoardState BoardZero;
            boardLoader(BoardZero.Board);
            cout << BoardZero.Board.size();
            Vector2i mousePosition;
            MouseState mouseStateOne = Released;
            vector <ChessPiece*> selectedChessPiece;

            // Sound
            Music music;
            if (!music.openFromFile("sounds/packetchessbanger.wav"))
                return -1;
            music.setVolume(50);
            music.play();

            // TEST TRASH
            BoardZero.Board[0]->chessSprite.setPosition(50,50);
            
            
            while(gameState == PLAYING && window.isOpen())
            {

                while(window.pollEvent(event))
                {
                    switch(event.type)
                    {
                        case Event::Closed:
                        {
                            window.close();
                            break;

                        }

                        case Event::KeyPressed:
                        {
                            if (Keyboard::isKeyPressed(Keyboard::Escape))
                                window.close();
                            break;
                        }

                        //Mouse Button Press Event Stuff

                        case Event::MouseButtonPressed:
                        {
                            if(event.mouseButton.button == Mouse::Left)
                            {
                                mouseStateOne = Holding;
                            }
                            for(int i = 0; i < BoardZero.Board.size(); i++)
                            {
                                if(Mouse::getPosition().x >= BoardZero.Board[i]->chessSprite.getPosition().x && Mouse::getPosition().x < (BoardZero.Board[i]->chessSprite.getPosition().x + BoardZero.Board[i]->chessSprite.getLocalBounds().width))
                                {
                                    if(Mouse::getPosition().y >= BoardZero.Board[i]->chessSprite.getPosition().y && Mouse::getPosition().y < (BoardZero.Board[i]->chessSprite.getPosition().y + BoardZero.Board[i]->chessSprite.getLocalBounds().height))
                                    {
                                        selectedChessPiece.push_back(BoardZero.Board[i]);
                                    }
                                }
                            }
                            //mousePosition = Mouse::getPosition();
                            break;
                        }

                        //Mouse Move Event Stuff

                        default:
                            break;
                    }
                }

                /*----------------------------------------*\
                ********************************************
                |___|****                          ****|___|
                !!!!!***                            ***!!!!!
                |___|**     Update Scene Segment     **|___|
                !!!!!***                            ***!!!!!
                |___|****                          ****|___|
                ********************************************
                \*----------------------------------------*/
                
                if(mouseStateOne == Holding)
                {
                    selectedChessPiece[0]->chessSprite.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
                }

                /*--------------------------------------*\
                ******************************************
                |___|****                        ****|___|
                !!!!!***                          ***!!!!!
                |___|**     Draw Scene Segment     **|___|
                !!!!!***                          ***!!!!!
                |___|****                        ****|___|
                ******************************************
                \*--------------------------------------*/

                window.clear(sf::Color(50, 50, 50, 255));

                window.draw(textBoxBg);
                window.draw(titleScreen);

                // Board
                window.draw(ChessBoardSprite);
                window.draw(BoardZero.Board[0]->chessSprite);

                // Display
                window.display();
            }
            
            boardDestroyer(BoardZero.Board);
        }
    }

    return 0;

}