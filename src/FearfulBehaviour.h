#ifndef FEARFUL_BEHAVIOUR_H 
#define FEARFUL_BEHAVIOUR_H

#include "BehaviourStrategy.h"
#include <string>


class FearfulBehaviour: public BehaviourStrategy{

	static std::string NAME ;
        static const T color[3];
	static FearfulBehaviour* fearfulbehaviour;
	const int LIMIT_SURROUNDING = 1;
	FearfulBehaviour(){};
	const double CRUISING_SPEED = 4;

public:
	~FearfulBehaviour();
        static const T* getColor();
	static FearfulBehaviour* getBehaviourInstance();
	static void getRidOfInstance();
	std::string getBehaviourName() override;
	std::vector<Animal *> nearestNeighbors(Animal* pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal* pet, double speed, Environment& myEnvironment) override;

};

#endif
