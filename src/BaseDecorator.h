//
// Created by Rafinesque on 12/03/2021.
//

#ifndef _BASEDECORATOR_H_
#define _BASEDECORATOR_H_

#include "Animal.h"

class BaseDecorator: public Animal {
protected:
    virtual void move(int xLim, int yLim) = 0;
    virtual std::string getName() = 0;
    //virtual vector<string> getAccessoriesAndCaptors() = 0;

};

#endif


