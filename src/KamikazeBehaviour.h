#include "BehaviourStrategy.h"
#include <string>


class KamikazeBehaviour: public BehaviourStrategy{
private:
	static std::string NAME ;
	static KamikazeBehaviour* kamikazebehaviour;
	bool has_reset_orientation = 0;
	KamikazeBehaviour(){};

public:
	~KamikazeBehaviour(){};
	static KamikazeBehaviour* getBehaviourInstance();
	static void getRidOfInstance();
	static std::string getBehaviourName();
	std::vector<Animal *> nearestNeighbors(Animal* pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal* pet, Environment& myEnvironment) override;

};
