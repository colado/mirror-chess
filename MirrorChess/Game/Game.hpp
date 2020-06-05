//
//  Game.hpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include "Piece.hpp"
#include "Board.hpp"

using namespace sf;

enum GameState
{
    moving,
    finished,
    notMoving
};

class Game
{
private:
    RenderWindow* windowPtr;
    Board board;
    Vector2i mousePos;
    void render();
    GameState gameState = notMoving;
    void update();
    
public:
    Game();
    void init();
    void handleInput();
};

#endif /* Game_hpp */
