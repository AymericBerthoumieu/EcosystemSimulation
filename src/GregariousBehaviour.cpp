#include <iostream>

#include "GregariousBehaviour.h"



const T GregariousBehaviour::color[3] = {0, 230, 0};

const T* GregariousBehaviour::getColor() {
    return color;
}

GregariousBehaviour::~GregariousBehaviour() {
    delete[] &color;
}
