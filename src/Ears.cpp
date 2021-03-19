//
// Created by Rafinesque on 19/03/2021.
//

#include "Ears.h"
#include <stdlib.h>

Ears::Ears(Animal &animal) {
    wrapAnimal = animal;
    capacityOfDetection = (float)rand() / (float)RAND_MAX ;
    minimumDistanceOfDetection = 0;
    maximumDistanceOfDetection = 1;
}

bool Ears::isDetecting(const Animal &animal) {

}