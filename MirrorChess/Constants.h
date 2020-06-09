//
//  Constants.h
//  MirrorChess
//
//  Created by Sergio Colado on 01.05.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#include <string>

using namespace std;

enum class Player
{
    White,
    Black
};

const int boardSize = 800;
const int cellSize = 100;
const int nCellsPerRow = 8;
const int piecesPerPlayer = 16;
const int pieceSpriteSize = 86;
const int pieceSpriteOffset = (cellSize - pieceSpriteSize) / 2;
const string pieces[]
{
    "rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"
};
const string pawn = "pawn";
const int initialBlackMainRowYCoord = 0;
const int initialBlackPawnRowYCoord = 100;
const int initialWhitePawnRowYCoord = 600;
const int initialWhiteMainRowYCoord = 700;

//const string whiteTowerALoc = "white-tower-a";
//const string whiteTowerBLoc = "white-tower-b";
//const string blackKnightALoc = "black-knight";

#endif /* Constants_h */
