#include "BehaviourStrategy.h"
#include <string>


class KamikazeBehaviour: public BehaviourStrategy{

	static std::string NAME ;
	bool has_reset_orientation = 0;

public:
	~KamikazeBehaviour(){}
	static std::string getBehaviourName();
	std::vector<Animal> nearestNeighbors(Animal& pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) override;

};
