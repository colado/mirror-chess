//
//  Game.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Game.hpp"

using namespace sf;

void Game::init()
{
    render();
}

void Game::handleInput()
{
    Event event;
    
    mousePos = Mouse::getPosition(*windowPtr);
    
    while (windowPtr->pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed:
                windowPtr->close();
                break;
                
            case Event::MouseButtonPressed:
                if (event.key.code == Mouse::Left)
                {
                    isMoving = true;
                    dx = mousePos.x - blackKnight.getPosition().x;
                    dy = mousePos.y - blackKnight.getPosition().y;
                }
                break;
                
            case Event::MouseButtonReleased:
                isMoving = false;
                break;
                
            default:
                break;
        }
    }
}

void Game::render()
{
    RenderWindow window(VideoMode(800, 800), "Mirror Chess");
    
    windowPtr = &window;
    
    Texture t1;
    Texture t2;
    t1.loadFromFile("Assets/chess-board.png");
    t2.loadFromFile("Assets/black-knight.png");
    board.setTexture(t1);
    blackKnight.setTexture(t2);
    
    while (window.isOpen())
    {
        
    
        if (isMoving)
        {
            blackKnight.setPosition(mousePos.x - dx, mousePos.y - dy);
        }
        handleInput();
        
        window.clear();
        
        window.draw(board);
        window.draw(blackKnight);
        
        
        window.display();
    }
}
