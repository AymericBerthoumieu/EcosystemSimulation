//
// Created by Rafinesque on 22/03/2021.
//

#ifndef CPP_ECOSYSTEM_PROJECT_SHELL_H
#define CPP_ECOSYSTEM_PROJECT_SHELL_H

#include "BaseDecorator.h"

class Shell: public BaseDecorator {
protected:
    Animal* wrapAnimal; // Give access to the decorated object
    float armor; // Probability of death of the decorated object when there is a collision
public:
    float getArmor() const;
    void setArmor(float armor);
    void onCollision() override;
    void move(int xLim, int yLim, Environment &myEnvironment) override; // Change the way decorated object move.
    std::string getName() override;
    Shell(Animal* animal); // Constructor that decorate the object in parameter
    ~Shell(); // Destructor
};

#endif
