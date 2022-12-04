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

    float windowScale = 1.0f;
    int currentWindowWidth = VideoMode::getDesktopMode().width*windowScale;
    int currentWindowHeight = VideoMode::getDesktopMode().height*windowScale;
    VideoMode desktop(currentWindowWidth, currentWindowHeight);
    float aspect_ratio = currentWindowHeight / static_cast<float>(currentWindowWidth);
    RenderWindow window(desktop, "Packet Chess", Style::Default);

    //FONT SECTION

    //TEXT BOX SECTION

    //VERTEX ARRAY STUFF


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
                    
                }
            }
        }
    }

    return 0;

}