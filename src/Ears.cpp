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

bool Ears::isDetecting(const Animal& animal) const{
    std::cout << " >>>>>>>>>>>>>>Ears isDetecting<<<<<<<<<< " << std::endl;
    std::tuple<int,int> pet_coords = animal.getCoordinates();
    int xNeighbor = std::get<0>(pet_coords);
    int yNeighbor = std::get<1>(pet_coords);
    bool exp1 = minimumDistanceOfPerception <= sqrt((x-xNeighbor)*(x-xNeighbor) + (y-yNeighbor)*(y-yNeighbor) );
    bool exp2 = sqrt((x-xNeighbor)*(x-xNeighbor) + (y-yNeighbor)*(y-yNeighbor)) <=  maximumDistanceOfPerception * animal.getVisibility() * capacityOfDetection;
    return (exp1 && exp2);
}

std::string Ears::getName() {
    return "c_Ears";
}

Ears::~Ears() {}