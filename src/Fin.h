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

    void move(int xLim, int yLim) override;

public:
    std::string getName();
    Fin(Animal* animal);
};

#endif


