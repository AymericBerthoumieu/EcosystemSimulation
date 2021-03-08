#ifndef BEHAVIOURSTRATEGY_H
#define BEHAVIOURSTRATEGY_H

#include "Pet.h"
#include "Environment.h"

#include <vector>


class BehaviourStrategy
{
public:
	virtual ~BehaviourStrategy(){}
	static std::string getBehaviourName();
	virtual std::vector<Pet> nearestNeighbors(Pet& pet, Environment& myEnvironment) = 0;
    virtual void move(int xLim, int yLim, Pet& pet, Environment& myEnvironment) = 0;
    

};

#endif