//
// Created by Rafinesque on 12/03/2021.
//

#ifndef _FIN_H_
#define _FIN_H_

#include "BaseDecorator.h"
/*
 * Fin is a concrete decorator that modify the speed of the decorated object
 */
class Fin : public BaseDecorator{
protected:
    float speedCoef; // Coefficient that modify the speed of the decorated object

public:
    float getSpeedCoef() const;
    void setSpeedCoef(float speedCoef);
    void move(int xLim, int yLim, Environment &myEnvironment) override; // Change the way decorated object move.
    Fin(Animal& a);
    static const string getName() {return "a_Fin";};
    ~Fin(); // Destructor
};

#endif


