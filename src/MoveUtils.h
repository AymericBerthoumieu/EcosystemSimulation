#ifndef MOVE_UTILS_H
#define MOVE_UTILS_H

#include "Animal.h"

/*
 * A small class containg utilisty function(s) to make animals move
 */
class MoveUtils{
public:
    static void setMoveParameters(Animal* a, int& x, int& y, int xLim, int yLim, double& orientation, double& speed, double& cumulX, double& cumulY);
};

#endif
