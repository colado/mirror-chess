//
//  Piece.hpp
//  MirrorChess
//
//  Created by Sergio Colado on 22.04.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>

class Piece
{
private:
    int posX;
    int posY;
    
public:
    void update();
};

#endif /* Piece_hpp */
