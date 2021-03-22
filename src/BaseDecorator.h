//
// Created by Rafinesque on 12/03/2021.
//

#ifndef _BASEDECORATOR_H_
#define _BASEDECORATOR_H_

#include "Animal.h"

class BaseDecorator: public Animal {




public:

    virtual void move(int xLim, int yLim, Environment &myEnvironment) = 0;
    virtual std::string getName() = 0;
    //virtual bool isDetecting(const Animal& animal) const = 0;
    virtual ~BaseDecorator() {};
    //virtual vector<string> getAccessoriesAndCaptors() = 0;

};

#endif


