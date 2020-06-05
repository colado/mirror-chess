//
//  Piece.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Piece.hpp"
#include "utils.hpp"
#include "Constants.h"
#include <iostream>

Piece::Piece(string color, string type, int posX, int posY): type(type), color(color), posX(posX), posY(posY),spriteURI(color + "-" + type)
{
    texture.loadFromFile("Assets/" + spriteURI + ".png");
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
    centerSprite(posX, posY);
}

// do I need this?
Vector2f Piece::getPosition()
{
    return sprite.getPosition();
}

bool Piece::contains(int mousePosX, int mousePosY)
{
    std::cout << sprite.getOrigin().x << endl;
    return sprite.getGlobalBounds().contains(mousePosX, mousePosY);
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

void Piece::centerSprite(int posX, int posY)
{
    int horizontalOffset = (cellSize - sprite.getTexture()->getSize().x) / 2;
    int verticalOffset = (cellSize - sprite.getTexture()->getSize().y) / 2;
    sprite.setPosition(posX + horizontalOffset, posY + verticalOffset);
}

Sprite& Piece::getSpriteRef()
{
    Sprite& spriteRef = sprite;
    return spriteRef;
}
