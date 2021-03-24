//
// Created by Rafinesque on 22/03/2021.
//

#ifndef CPP_ECOSYSTEM_PROJECT_SHELL_H
#define CPP_ECOSYSTEM_PROJECT_SHELL_H

#include "BaseDecorator.h"

class Shell: public BaseDecorator {
protected:
    double probabilityOfFatalCollision; // Probability of death of the decorated object when there is a collision
    double speed;
    static string NAME;
public:
    Shell(Animal& animal);
    ~Shell(); // Destructor
    double getProbabilityOfFatalCollision() const;
    double getSpeed() const;
    void setSpeed(double speedDeco);
    void setProbabilityOfFatalCollision(double probabilityOfFatalCollision);

};

#endif
