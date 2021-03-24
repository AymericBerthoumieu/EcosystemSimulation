//
// Created by Rafinesque on 22/03/2021.
//

#include "Shell.h"
#include "stdlib.h"

std::string Shell::NAME = "a_Shell";

// Create the decorator with the decorated object as attribut, the speedCoef and the armor
Shell::Shell(Animal& a): BaseDecorator(a), probabilityOfFatalCollision(a.getProbabilityOfFatalCollision()/((double)rand()/RAND_MAX*2+1)), speed(a.getSpeed()*probabilityOfFatalCollision) {};

Shell::~Shell(){}

double Shell::getProbabilityOfFatalCollision() const {
    return probabilityOfFatalCollision;
}

void Shell::setProbabilityOfFatalCollision(double armor){
    this->probabilityOfFatalCollision = probabilityOfFatalCollision;
}

double Shell::getSpeed() const{
    return speed;
}

void Shell::setSpeed(double speedDeco) {
    this->speed = speedDeco;
}

