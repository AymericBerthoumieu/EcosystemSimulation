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
    static string NAME;

public:
    Fin(Animal& a);
    ~Fin(); // Destructor
    double getSpeed() const;
    void setSpeed(double speedDeco);
    vector<string> getAccessoriesAndCaptors();
};

#endif


