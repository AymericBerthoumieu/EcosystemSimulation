#include <iostream>

#include "FearfulBehaviour.h"

const T FearfulBehaviour::color[3] = {0, 0, 230};

const T* FearfulBehaviour::getColor() {
    return color;
}

FearfulBehaviour::~FearfulBehaviour() {
    delete[] &color;
}
