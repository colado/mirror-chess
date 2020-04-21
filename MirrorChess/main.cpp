//
//  main.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 20.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 800), "Mirror Chess");
    
    while (window.isOpen())
    {
        Event event;
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
            
        }
        
        Texture t1;
        
        // TODO: Fix absolute path
        t1.loadFromFile("Assets/chess-board.png");
        Sprite board(t1);
        
        window.clear();
        
        window.draw(board);
        
        
        window.display();
    }
}
