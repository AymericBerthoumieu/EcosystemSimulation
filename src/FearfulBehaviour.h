#include "BehaviourStrategy.h"
#include <string>


class FearfulBehaviour: public BehaviourStrategy{

	static std::string NAME ;
	const int LIMIT_SURROUNDING = 1;
	const double CRUISING_SPEED = 4;

public:
	~FearfulBehaviour(){}
	static  std::string getBehaviourName();
	std::vector<Animal> nearestNeighbors(Animal& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) override;

};