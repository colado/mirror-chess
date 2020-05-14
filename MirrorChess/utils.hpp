//
//  utils.hpp
//  MirrorChess
//
//  Created by Sergio Colado on 01.05.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

void moveKnight(Sprite sprite, int mousePosX, int mousePosY, int origPosX, int origPosY);
void moveRook(Sprite* sprite, int origPosX, int origPosY, int mousePosX, int mousePosY);
void moveBishop(Sprite* sprite, int origPosX, int origPosY, int mousePosX, int mousePosY);


#endif /* utils_hpp */
