#include "BehaviourStrategy.h"
#include <string>


class FearfulBehaviour: public BehaviourStrategy{

	static std::string NAME ;
	static FearfulBehaviour* fearfulbehaviour;
	const int LIMIT_SURROUNDING = 1;
	FearfulBehaviour(){};
	const double CRUISING_SPEED = 4;

public:
	~FearfulBehaviour(){}
	static FearfulBehaviour* getBehaviourInstance();
	static void getRidOfInstance();
	static  std::string getBehaviourName();
	std::vector<Animal> nearestNeighbors(Animal& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) override;

};
