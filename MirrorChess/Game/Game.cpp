//
//  Game.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

using namespace sf;

Game::Game(): knight("black", 0, 0, "black-knight")
{
    
}

void Game::init()
{
    Texture t1;
    t1.loadFromFile("Assets/chess-board.png");
    board.setTexture(t1);
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
                    std::cout << knight.getPosition().x << std::endl;
                    dx = mousePos.x - knight.getPosition().x;
                    dy = mousePos.y - knight.getPosition().y;
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
    
    while (window.isOpen())
    {
        handleInput();
        update();
        
        window.clear();
                
        window.draw(board);
        window.draw(knight.getSpriteRef());
        
        
        window.display();
    }
}

void Game::update()
{
    // here goes logic to find piece and move it
    if (isMoving)
    {
        knight.setPosition(mousePos.x - dx, mousePos.y - dy);
    }
}
