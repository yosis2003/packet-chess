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

    // Sprites
    Texture ChessBoardTexture;
    ChessBoardTexture.loadFromFile("packet Chess Sprites/Chess Board.png");
    Sprite ChessBoardSprite;
    ChessBoardSprite.setTexture(ChessBoardTexture);


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
        const int chessBoardScale = 1;
        ChessBoardSprite.setOrigin((ChessBoardSprite.getLocalBounds().width)/2, (ChessBoardSprite.getLocalBounds().height)/2);
        ChessBoardSprite.setPosition({currentWindowWidth*0.5f, currentWindowHeight*0.5f});
        ChessBoardSprite.setScale(chessBoardScale, chessBoardScale);
        window.draw(ChessBoardSprite);

        // Chess Pieces


        window.display();

    }

    return 0;

}