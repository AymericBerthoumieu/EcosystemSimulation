#include <iostream>

#include "KamikazeBehaviour.h"

const T KamikazeBehaviour::color[3] = {230, 0, 0};

const T* KamikazeBehaviour::getColor() {
    std::cout << "Getting color : " << color << "in Strategy." << std::endl;
    return color;
}


KamikazeBehaviour::~KamikazeBehaviour() {
    delete[] &color;
}


