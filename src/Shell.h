//
// Created by Rafinesque on 22/03/2021.
//

#ifndef CPP_ECOSYSTEM_PROJECT_SHELL_H
#define CPP_ECOSYSTEM_PROJECT_SHELL_H

#include "BaseDecorator.h"

class Shell: public BaseDecorator {
protected:
    double probabilityOfFatalCollision; // Probability of death of the decorated object when there is a collision
public:
    double getArmor() const;
    void setArmor(double probabilityOfFatalCollision);
    static const string getName() {return "a_Shell";};
    Shell(Animal& animal); // Constructor that decorate the object in parameter
    ~Shell(); // Destructor
};

#endif
