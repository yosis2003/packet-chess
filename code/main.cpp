// Packet Chess Game
// Creators: Matthew Craig, Yousif Alnomani
// CISP 400


#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

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

    Texture ChessBoardTexture;
    ChessBoardTexture.loadFromFile("packet Chess Sprites/Chess Board.png");
    Sprite ChessBoardSprite;
    ChessBoardSprite.setTexture(ChessBoardTexture);
    const int chessBoardScale = 1;
    ChessBoardSprite.setOrigin((ChessBoardSprite.getLocalBounds().width)/2, (ChessBoardSprite.getLocalBounds().height)/2);
    ChessBoardSprite.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.5f});
    ChessBoardSprite.setScale(chessBoardScale, chessBoardScale);


    // Sprites
    Texture ChessBoardTexture;
    Texture WhiteKingTexture;
    Texture BlackKingTexture;
    Texture WhiteQueenTexture;
    Texture BlackQueenTexture;
    Texture WhiteBishopTexture;
    Texture BlackBishopTexture;
    Texture WhiteKnightTexture;
    Texture BlackKnightTexture;
    Texture WhiteRookTexture;
    Texture BlackRookTexture;
    Texture WhitePawnTexture;
    Texture BlackPawnTexture;

    ChessBoardTexture.loadFromFile("packet Chess Sprites/Chess Board.png");
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

    Sprite WhiteKingSprite;
    Sprite BlackKingSprite;
    Sprite WhiteQueenSprite;
    Sprite BlackQueenSprite;
    Sprite WhiteBishopSprite;
    Sprite BlackBishopSprite;
    Sprite WhiteKnightSprite;
    Sprite BlackKnightSprite;
    Sprite WhiteRookSprite;
    Sprite BlackRookSprite;
    Sprite WhitePawnSprite;
    Sprite BlackPawnSprite;

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

    const int chessPieceScale = 2;
    
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
        Event event;

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
        
        titleScreen.setString("Packet Chess!!");



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

        // TITLE
        const int titleSizeMult = 2;
        titleScreen.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.05f});
        titleScreen.setOrigin({(titleScreen.getLocalBounds().width)/2, (titleScreen.getLocalBounds().height)/2 });
        titleScreen.setScale(titleSizeMult, titleSizeMult);
        textBoxBg.setPosition({titleScreen.getPosition().x - TB_Align_W - TB_BackBorder, titleScreen.getPosition().y + TB_Align_H - TB_BackBorder });
        textBoxBg.setSize({titleScreen.getLocalBounds().width + TB_BackBorder*2 , titleScreen.getLocalBounds().height + TB_BackBorder*2});
        textBoxBg.setOrigin({(titleScreen.getLocalBounds().width)/2, (titleScreen.getLocalBounds().height)/2});
        textBoxBg.setScale(titleSizeMult, titleSizeMult);
        window.draw(textBoxBg);
        window.draw(titleScreen);

        // Board
        window.draw(ChessBoardSprite);

        // Display
        window.display();

    }

    return 0;

}