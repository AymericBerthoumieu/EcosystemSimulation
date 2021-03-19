//
// Created by Rafinesque on 19/03/2021.
//

#include "Ears.h"
#include "stdlib.h"
#include "cmath"
#include "memory"


Ears::Ears(Animal* animal) {
    wrapAnimal = animal;
    capacityOfDetection = (float)rand() / (float)RAND_MAX ;
    minimumDistanceOfPerception = 0;
    maximumDistanceOfPerception = (float)rand() / (float)RAND_MAX * LIMIT_VIEW;
}

bool Ears::isDetecting(Animal* neighborAnimal) {
    std::tuple<int,int> pet_coords = neighborAnimal->getCoordinates();
    int xNeighbor = std::get<0>(pet_coords);
    int yNeighbor = std::get<1>(pet_coords);
    if (maximumDistanceOfPerception * neighborAnimal->getVisibility() * capacityOfDetection <= sqrt((x-xNeighbor)*(x-xNeighbor) + (y-yNeighbor)*(y-yNeighbor))) {
        return 1;
    }
    return 0;
}

std::string Ears::getName() {
    return "c_Ears";
}
