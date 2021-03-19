#include <iostream>

#include "FearfulBehaviour.h"

const T FearfulBehaviour::color[3] = {0, 0, 230};

const T* FearfulBehaviour::getColor() {
    std::cout << "Getting color : " << color << "in Strategy." << std::endl;
    return color;
}

FearfulBehaviour::~FearfulBehaviour() {
    delete[] &color;
}
