#include "BehaviourStrategy.h"
#include <string>


class GregariousBehaviour: public BehaviourStrategy{

	static std::string NAME ;
	const double RADIUS_SURROUNDING = 30.;
	const int LIMIT_SURROUNDING = 1;

public:
	~GregariousBehaviour(){}
	std::string getBehaviourName() override;
	std::vector<Animal> nearestNeighbors(Animal& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) override;

};
