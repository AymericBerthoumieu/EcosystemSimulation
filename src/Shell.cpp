//
// Created by Rafinesque on 22/03/2021.
//

#include "Shell.h"
#include "stdlib.h"

// Create the decorator with the decorated object as attribut, the speedCoef and the armor
Shell::Shell(Animal& a): BaseDecorator(a), armor((double)rand() / RAND_MAX * 99 + 1) {};

void Shell::move(int xLim, int yLim, Environment &myEnvironment){
    double nx, ny;
    double dx = cos( orientation )*speed/armor; // speedCoef is going to modify the speed of the decorated object
    double dy = -sin( orientation )*speed/armor; // speedCoef is going to modify the speed of the decorated object
    int cx, cy;

    cx = static_cast<int>( cumulX ); cumulX -= cx;
    cy = static_cast<int>( cumulY ); cumulY -= cy;

    nx = x + dx + cx;
    ny = y + dy + cy;

    if ( (nx < 0) || (nx > xLim - 1) ) {
        orientation = M_PI - orientation;
        cumulX = 0.;}
    else {
        x = static_cast<int>( nx );
        cumulX += nx - x;}

    if ( (ny < 0) || (ny > yLim - 1) ) {
        orientation = -orientation;
        cumulY = 0.;}
    else {
        y = static_cast<int>( ny );
        cumulY += ny - y;}
}

void Shell::onCollision(){
    double proba = ((double) rand() / (RAND_MAX)) * armor; // The armor make this attribut bigger so the next condition will have less chance to be true
    if (proba < this->getProbabilityOfFatalCollision()) {
        cout << this->getIdentity() << " dies by collision" << endl;
        life = 0;
    }
}

float Shell::getArmor() const{
    return armor;
}

void Shell::setArmor(float armor){
    this->armor = armor;
}

Shell::~Shell(){}