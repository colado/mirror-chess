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
    Vector2i mouseOffset;
    Vector2i position;
    Texture texture;
    Sprite sprite;
    
public:
    Piece(string color, string type, Vector2i position);
    void setPosition(Vector2i position);
    Sprite& getSpriteRef();
    Vector2i getPosition();
    bool contains(Vector2i position);
    bool validateMove(Vector2i position);
    void centerInCell(Vector2i position);
};

#endif /* Piece_*hpp */
