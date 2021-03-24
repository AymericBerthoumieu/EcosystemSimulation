//
// Created by Rafinesque on 19/03/2021.
//

#include "Ears.h"
#include "stdlib.h"
#include "cmath"
#include "memory"

std::string Ears::NAME = "c_Ears";

Ears::Ears(Animal& animal): Sensor(animal) {}


Ears::~Ears() {}