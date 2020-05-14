//
//  utils.cpp
//  MirrorChess
//
//  Created by Sergio Colado on 01.05.20.
//  Copyright © 2020 Sergio Colado. All rights reserved.
//

#include "utils.hpp"
#include "Constants.h"
#include <iostream>

// Needs changes
void moveKnight(Sprite sprite, int mousePosX, int mousePosY, int origPosX, int origPosY)
{
    int targetX = mousePosX < origPosX ? -cellSize : cellSize;
    int targetY = mousePosY < origPosY ? -cellSize : cellSize;
    
    mousePosX > mousePosY ? targetX *= 2 : targetY *= 2;
    
    sprite.setPosition(targetX , targetY);
}

//void moveRook(Sprite* sprite, int mousePosX, int mousePosY)
//{
//    int x = mousePosX - origPosX;
//    int y = mousePosY - origPosY;
//    
//    if (abs(x) > abs(y)) sprite->setPosition(x, origPosY);
//    else sprite->setPosition(origPosX, y);
//}

void moveBishop(Sprite* sprite, int origPosX, int origPosY, int mousePosX, int mousePosY)
{
    int x = mousePosX - origPosX;
    int y = mousePosY - origPosY;
    
    int distance = mousePosX > mousePosY ? x : y;
    
    sprite->setPosition(distance, distance);
}
