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
    string type;
    // TODO: Replace for an enum of only "white" or "black"
    string color;
    string spriteURI;
    int dx = 0;
    int dy = 0;
    int posX;
    int posY;
    Texture texture;
    Sprite sprite;
    
public:
    Piece(string color, string type, int posX, int posY);
    void setPosition(int mousePosX, int mousePosY);
    Vector2f getPosition();
    Sprite& getSpriteRef();
};

#endif /* Piece_*hpp */
