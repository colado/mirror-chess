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

class Game
{
private:
    sf::RenderWindow* windowPtr;
    sf::Sprite board;
    sf::Sprite blackKnight;
    sf::Vector2i mousePos;
    int dx;
    int dy;
    void render();
    bool isMoving = false;
    
public:
    void init();
    void update();
    void handleInput();
};

#endif /* Game_hpp */
