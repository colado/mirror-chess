//
//  Piece.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Piece.hpp"
#include "utils.hpp"
#include <iostream>

Piece::Piece(string color, string type, int posX, int posY): type(type), color(color), posX(posX), posY(posY),spriteURI(color + "-" + type)
{
    std::cout << spriteURI << std::endl;
    texture.loadFromFile("Assets/" + spriteURI + ".png");
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

sf::Vector2f Piece::getPosition()
{
    return sprite.getPosition();
}

void Piece::setPosition(int mousePosX, int mousePosY)
{
    if (dx == 0 && dy == 0)
    {
        dx = sprite.getPosition().x - mousePosX;
        dy = sprite.getPosition().y - mousePosY;
    }
    sprite.setPosition(mousePosX + dx, mousePosY + dy);
}

Sprite& Piece::getSpriteRef()
{
    Sprite& spriteRef = sprite;
    return spriteRef;
}
