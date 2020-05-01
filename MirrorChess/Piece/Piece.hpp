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
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Piece
{
private:
    // TODO: Replace for an enum of only "white" or "black"
    string color;
    string spriteURI;
    int posX;
    int posY;
    Texture texture;
    Sprite sprite;
    
public:
    Piece(string color, int posX, int posY, string spriteURI);
    void setPosition(int x, int y);
    Vector2f getPosition();
    Sprite& getSpriteRef();
};

#endif /* Piece_*hpp */
