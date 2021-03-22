#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H

#include "Animal.h"

using namespace std;

class AnimalFactory {

    // it is used to create only one animal in other methods of the class
    // not public because its behaviour is not for being called outside of this class
    virtual Animal* createMember(string behaviour="none") = 0;

public:
    // function meant to initialize the population of animals at the start of the session
    virtual vector<Animal*> initializePopulation(int number) = 0;
    virtual ~AnimalFactory() {};
};    

#endif

