//
// Created by Rafinesque on 22/03/2021.
//

#include "Shell.h"
#include "stdlib.h"

// Create the decorator with the decorated object as attribut, the speedCoef and the armor
Shell::Shell(Animal& a): BaseDecorator(a), probabilityOfFatalCollision(probabilityOfFatalCollision / (double)rand() / RAND_MAX * 2 + 1) {};

double Shell::getArmor() const{
    return probabilityOfFatalCollision;
}

void Shell::setArmor(double armor){
    this->probabilityOfFatalCollision = probabilityOfFatalCollision;
}

Shell::~Shell(){}