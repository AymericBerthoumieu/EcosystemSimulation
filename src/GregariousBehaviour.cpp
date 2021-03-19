#include <iostream>

#include "GregariousBehaviour.h"



const T GregariousBehaviour::color[3] = {0, 230, 0};

const T* GregariousBehaviour::getColor() {
    std::cout << "Getting color : " << color << "in Strategy." << std::endl;
    return color;
}

GregariousBehaviour::~GregariousBehaviour() {
    delete[] &color;
}
