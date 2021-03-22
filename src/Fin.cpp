//
// Created by Rafinesque on 12/03/2021.
//
#include "Fin.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cstring>


Fin::Fin(Animal* animal):  wrapAnimal(animal), speedCoef((double)rand()) {}


void Fin::move(int xLim, int yLim, Environment &myEnvironment){
    double nx, ny;
    double dx = cos( orientation )*speed*speedCoef;
    double dy = -sin( orientation )*speed*speedCoef;
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

std::string Fin::getName() {
    return "a_Fin";
}

Fin::~Fin(){}
