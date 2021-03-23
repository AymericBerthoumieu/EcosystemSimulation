//
// Created by Rafinesque on 12/03/2021.
//

#ifndef _BASEDECORATOR_H_
#define _BASEDECORATOR_H_

#include "Animal.h"

/*
 * Base of all the decorator Animals are going to be composed by 0,one or several decorators that inherit this class
 */
class BaseDecorator: public Animal {
protected:
    Animal& wrapAnimal; // Give access to the decorated object
public:
    BaseDecorator(Animal& a);
};

#endif


