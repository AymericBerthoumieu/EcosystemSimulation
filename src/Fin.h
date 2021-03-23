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
    double speed; // Coefficient that modify the speed of the decorated object

public:
    double getSpeed() const;
    void setSpeed(double speedDeco);
    Fin(Animal& a);
    static const string getName() {return "a_Fin";};
    ~Fin(); // Destructor
};

#endif


