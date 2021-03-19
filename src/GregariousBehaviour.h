#include "BehaviourStrategy.h"
#include <string>


class GregariousBehaviour: public BehaviourStrategy{
private:

	static std::string NAME ;
	static GregariousBehaviour* gregariousbehaviour;
	const int LIMIT_SURROUNDING = 1;
	GregariousBehaviour(){};

public:
	~GregariousBehaviour(){}
	static GregariousBehaviour* getBehaviourInstance();
	static void getRidOfInstance();
	static std::string getBehaviourName();
	std::vector<Animal> nearestNeighbors(Animal& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) override;

};
