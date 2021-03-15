#include "BehaviourStrategy.h"
#include <string>


class GregariousBehaviour: public BehaviourStrategy{

	static std::string NAME ;
	const int LIMIT_SURROUNDING = 1;

public:
	~GregariousBehaviour(){}
	static std::string getBehaviourName();
	std::vector<Animal> nearestNeighbors(Animal& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) override;

};
