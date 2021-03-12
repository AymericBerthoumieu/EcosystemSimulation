#include "BehaviourStrategy.h"
#include <string>


class KamikazeBehaviour: public BehaviourStrategy{

	static std::string NAME ;

public:
	~KamikazeBehaviour(){}
	std::string getBehaviourName() override;
	std::vector<Pet> nearestNeighbors(Pet& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Pet& pet, Environment& myEnvironment) override;

};
