#include "BehaviourStrategy.h"
#include <string>


class FearfulBehaviour: public BehaviourStrategy{

	static std::string NAME ;
	const double RADIUS_SURROUNDING = 15.;
	const int LIMIT_SURROUNDING = 5;
	const double CRUISING_SPEED = 4;

public:
	~FearfulBehaviour(){}
	std::string getBehaviourName() override;
	std::vector<Pet> nearestNeighbors(Pet& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Pet& pet, Environment& myEnvironment) override;

};
