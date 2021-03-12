#ifndef _PETS_H_
#define _PETS_H_

#include "UImg.h"
#include "Animal.h"

#include <iostream>

using namespace std;


class Environment;


class Pet: public Animal{
public :
   Pet();
   ~Pet();
};

#endif
