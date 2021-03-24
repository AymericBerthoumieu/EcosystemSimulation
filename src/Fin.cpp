//
// Created by Rafinesque on 12/03/2021.
//
#include "Fin.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cstring>

std::string Fin::NAME = "a_Fin";

Fin::Fin(Animal& a): BaseDecorator(a), speed(a.getSpeed() * (double)rand()/RAND_MAX * MAX_SPEED + 1){};

double Fin::getSpeed() const{
    return speed;
}

void Fin::setSpeed(double speedDeco) {
    this->speed = speedDeco;
}
vector<string> Fin::getAccessoriesAndCaptors() {

    vector<string> names = wrapAnimal.getAccessoriesAndCaptors();
    names.push_back(NAME);
    return names;
}

Fin::~Fin(){}
