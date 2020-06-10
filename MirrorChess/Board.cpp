//
//  Board.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 05.05.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "Board.hpp"

Board::Board(string spriteURI): activePiece(nullptr), turn(Player::White)
{
    texture.loadFromFile("Assets/" + spriteURI + ".png");
    sprite.setTexture(texture);
    
    for (int i = 0; i < piecesPerPlayer; i++)
    {
        if (i < nCellsPerRow)
        {
            blackPieces.push_back(new Piece("black", pieces[i], Vector2i(i * cellSize, initialBlackMainRowYCoord)));
        }
        else
        {
            blackPieces.push_back(new Piece("black", pawn, Vector2i((i - nCellsPerRow) * cellSize, initialBlackPawnRowYCoord)));
        }
    }
    
    for (int i = 0; i < piecesPerPlayer; i++)
    {
        if (i < nCellsPerRow)
        {
            whitePieces.push_back(new Piece("white", pieces[i], Vector2i(i * cellSize, initialWhiteMainRowYCoord)));
        }
        else
        {
            whitePieces.push_back(new Piece("white", pawn, Vector2i((i - nCellsPerRow) * cellSize, initialWhitePawnRowYCoord)));
        }
    }
}

// Not sure about this implementation. Not sure how to avoid dragging multiple pieces
void Board::update(Vector2i mousePos, bool isMousePressed)
{
    if (activePiece == nullptr)
    {
        int nPieces = turn == Player::White ? (int)whitePieces.size() : (int)blackPieces.size();
        for (int i = 0; i < nPieces; i++)
        {
            bool clickIsInRange = turn == Player::White
            ? whitePieces[i]-> contains(mousePos)
            : blackPieces[i]-> contains(mousePos);
            
            if (clickIsInRange)
            {
                activePiece = turn == Player::White ? whitePieces[i] : blackPieces [i];
                activePieceOrigPos = Vector2i(activePiece->getPosition());
            }
        }
    }
    
    if (isMousePressed && activePiece)
    {
        activePiece->setPosition(mousePos);
    }
    else if (!isMousePressed && activePiece)
    {
        if (false)
        {
            activePiece->setPosition(activePieceOrigPos);
            activePiece = nullptr;
        }
        else
        {
            activePiece->centerInCell(mousePos);
            activePiece = nullptr;
            turn = turn == Player::White ? Player::Black : Player::White;
        }
    }
}

Sprite& Board::getSpriteRef()
{
    Sprite& spriteRef = sprite;
    return spriteRef;
}

Sprite& Board::getPieceRef(string color, int index)
{
    Sprite& spriteRef = color == "black" ? blackPieces[index]->getSpriteRef() : whitePieces[index]->getSpriteRef();
    return spriteRef;
}

int Board::getNumberOfPieces()
{
    return blackPieces.size();
}
