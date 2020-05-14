//
//  Board.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 05.05.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Board.hpp"
#include "Constants.h"
#include <iostream>

Board::Board(string spriteURI): bishop("white", "bishop", 200, 500)
{
    texture.loadFromFile("Assets/" + spriteURI + ".png");
    sprite.setTexture(texture);
    
    for (int i = 0; i < piecesPerPlayer; i++)
    {
        if (i < nCellsPerRow)
        {
            whitePieces.push_back(new Piece("white", pieces[i], i * cellSize + pieceSpriteOffset, pieceSpriteOffset));
        }
        else
        {
            whitePieces.push_back(new Piece("white", pawn, (i - nCellsPerRow) * cellSize, cellSize + pieceSpriteOffset));
        }
    }
}

void Board::update(int mousePosX, int mousePosY)
{
    //    for (int i = 0; i < whitePieces.size(); i++)
    //    {
    //        if (whitePieces[i].getPosition().x - )
    //        {
    //
    //        }
    //    }
}

Sprite& Board::getSpriteRef()
{
    Sprite& spriteRef = sprite;
    return spriteRef;
}

Sprite& Board::getPieceRef(string color, int index)
{
    Sprite& spriteRef = whitePieces[index]->getSpriteRef();
    return spriteRef;
}

int Board::getNumberOfPieces()
{
    return whitePieces.size();
}
