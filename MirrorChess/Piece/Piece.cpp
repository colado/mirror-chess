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

Piece::Piece(string color, string type, Vector2i position): type(type), color(color), position(position),spriteURI(color + "-" + type), mouseOffset(Vector2i(0, 0))
{
    texture.loadFromFile("Assets/" + spriteURI + ".png");
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);
    centerInCell((Vector2i)sprite.getPosition());
}

bool Piece::contains(Vector2i position)
{
    std::cout << sprite.getOrigin().x << endl;
    return sprite.getGlobalBounds().contains(position.x, position.y);
}

void Piece::setPosition(Vector2i position)
{
    if (mouseOffset.x == 0 && mouseOffset.y == 0)
    {
        mouseOffset.x = sprite.getPosition().x - position.x;
        mouseOffset.y = sprite.getPosition().y - position.y;
    }
    
    sprite.setPosition(position.x + mouseOffset.x, position.y + mouseOffset.y);
}

Vector2i Piece::getPosition()
{
    return Vector2i(sprite.getPosition());
}

void Piece::centerInCell(Vector2i position)
{
    Vector2i offset = Vector2i((cellSize - sprite.getTexture()->getSize().x) / 2, (cellSize - sprite.getTexture()->getSize().y) / 2);
    Vector2i targetPosition = Vector2i((position.x - (position.x % cellSize)), position.y - (position.y % cellSize));

    sprite.setPosition(targetPosition.x + offset.x, targetPosition.y + offset.y);;
}

Sprite& Piece::getSpriteRef()
{
    Sprite& spriteRef = sprite;
    return spriteRef;
}

bool Piece::validateMove(Vector2i position)
{
    bool result;
    
    if (type == pawn)
    {
        if (position.y - sprite.getPosition().y < 100) result = true;
    }
    return result;
}
