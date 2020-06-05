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
            blackPieces.push_back(new Piece("black", pieces[i], i * cellSize, 0));
        }
        else
        {
            blackPieces.push_back(new Piece("black", pawn, (i - nCellsPerRow) * cellSize, cellSize));
        }
    }
}

// Not sure about this implementation. Not sure how to avoid dragging multiple pieces
void Board::update(int mousePosX, int mousePosY, bool isMoveFinished)
{
    if (isMoveFinished)
    {
        activePiece->centerSprite(mousePosX - (mousePosX % cellSize), mousePosY - (mousePosY % cellSize));
        activePiece = nullptr;
    }
    else if (activePiece == nullptr)
    {
        for (int i = 0; i < blackPieces.size(); i++)
        {
            if (blackPieces[i]->contains(mousePosX, mousePosY))
            {
                activePiece = blackPieces[i];
                break;
            }
        }
    }
    else
    {
        activePiece->setPosition(mousePosX, mousePosY);
    }
}

Sprite& Board::getSpriteRef()
{
    Sprite& spriteRef = sprite;
    return spriteRef;
}

Sprite& Board::getPieceRef(string color, int index)
{
    Sprite& spriteRef = blackPieces[index]->getSpriteRef();
    return spriteRef;
}

int Board::getNumberOfPieces()
{
    return blackPieces.size();
}
