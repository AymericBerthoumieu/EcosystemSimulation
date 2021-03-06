#ifndef BEHAVIOURSTRATEGY_H
#define BEHAVIOURSTRATEGY_H

#include "Animal.h"
#include "Environment.h"

#include <vector>


class BehaviourStrategy
{
	
public:
	virtual ~BehaviourStrategy(){};
	virtual std::string getBehaviourName() = 0;
	virtual std::vector<Animal *> nearestNeighbors(Animal* pet, Environment& myEnvironment) = 0;
    virtual void move(int xLim, int yLim, Animal* pet, Environment& myEnvironment) = 0;
    

};

#endif
