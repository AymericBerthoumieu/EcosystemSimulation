//
// Created by Rafinesque on 12/03/2021.
//

#ifndef _FIN_H_
#define _FIN_H_

#include "BaseDecorator.h"

class Fin : public BaseDecorator{
protected:
    Animal* wrapAnimal;
    float speedCoef;


    // TODO implémenter isDetecting
public:
    void move(int xLim, int yLim, Environment &myEnvironment) override;
    bool isDetecting(const Animal& animal) const override{return wrapAnimal->isDetecting(animal);};
    std::string getName() override;
    Fin(Animal* animal);
    ~Fin();
};

#endif


