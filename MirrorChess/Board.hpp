//
//  Board.hpp
//  MirrorChess
//
//  Created by Sergio Colado on 05.05.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Piece.hpp"
#include "Constants.h"

using namespace sf;

class Board
{
private:
    Texture texture;
    Sprite sprite;
    vector<Piece*> whitePieces;
    vector<Piece*> blackPieces;
    Texture bT;
    Sprite bS;
    Piece* activePiece;
    Vector2i activePieceOrigPos;
    Player turn;
    
public:
    Board(string spriteURI);
    void update(Vector2i position, bool isMousePressed);
    Sprite& getSpriteRef();
    Sprite& getPieceRef(string color, int index);
    int getNumberOfPieces();
};

#endif /* Board_hpp */
