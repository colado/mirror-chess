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
                    inputState = InputState::Pressed;
                }
                break;
                
            case Event::MouseButtonReleased:
                inputState = InputState::Released;
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
        for (int i = 0; i < board.getNumberOfPieces(); i++)
        {
            window.draw(board.getPieceRef("white", i));
        }
        
        window.display();
    }
}

void Game::update()
{
    switch (inputState)
    {
        case InputState::Pressed:
            board.update(mousePos, true);
            break;
            
        case InputState::Released:
            board.update(mousePos, false);
            inputState = InputState::Inactive;
            break;
            
        default:
            break;
    }
}
