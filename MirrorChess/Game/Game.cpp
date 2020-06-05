//
//  Game.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
#include "utils.hpp"

using namespace sf;

Game::Game(): board("chess-board")
{
    
}

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
                    gameState = moving;
                }
                break;
                
            case Event::MouseButtonReleased:
                gameState = finished;
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
        
        window.draw(board.getSpriteRef());
        for (int i = 0; i < board.getNumberOfPieces(); i++)
        {
            window.draw(board.getPieceRef("black", i));
        }
        
        window.display();
    }
}

void Game::update()
{
    // here goes logic to find piece and move it
    switch (gameState)
    {
        case moving:
            board.update(mousePos.x, mousePos.y, false);
            break;
            
        case finished:
            board.update(mousePos.x, mousePos.y, true);
            gameState = notMoving;
            break;
            
        default:
            break;
    }
}
