#include "BehaviourStrategy.h"
#include <string>


class GregariousBehaviour: public BehaviourStrategy{

	static std::string NAME;
	const double RADIUS_SURROUNDING = 15.;

public:
	~GregariousBehaviour(){}
	std::string getBehaviourName();
	std::vector<Pet> nearestNeighbors(Pet& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Pet& pet, Environment& myEnvironment) override;

};
