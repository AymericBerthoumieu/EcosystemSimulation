#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H

#include "Animal.h"

using namespace std;

class AnimalFactory {

    virtual Animal& createMember(string behaviour="none") = 0;

public:
    virtual vector<Animal> initializePopulation(int number) = 0;
    virtual ~AnimalFactory() {};
//    virtual vector<Animal> createMembersAtRuntime() = 0;
//    virtual Animal& createMember(Environment& environment, string behaviour="none") = 0;
//    virtual Animal& cloneMember(Animal* animal) = 0;
};    

#endif
