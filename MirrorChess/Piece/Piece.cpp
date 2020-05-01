//
//  Piece.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Piece.hpp"

Piece::Piece(string color, int posX, int posY, string spriteURI): color(color), posX(posX), posY(posY), spriteURI(spriteURI)
{
    texture.loadFromFile("Assets/" + spriteURI + ".png");
    sprite.setTexture(texture);
}

sf::Vector2f Piece::getPosition()
{
    return sprite.getPosition();
}

void Piece::setPosition(int x, int y)
{
    sprite.setPosition(x, y);
}

Sprite& Piece::getSpriteRef()
{
    Sprite& spriteRef = sprite;
    return spriteRef;
}
