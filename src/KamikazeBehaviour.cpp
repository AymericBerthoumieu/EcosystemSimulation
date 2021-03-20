#include <iostream>

#include "KamikazeBehaviour.h"

const T KamikazeBehaviour::color[3] = {230, 0, 0};

const T* KamikazeBehaviour::getColor() {
    return color;
}


KamikazeBehaviour::~KamikazeBehaviour() {
    delete[] &color;
}


