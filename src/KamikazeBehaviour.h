#ifndef KAMIKAZE_BEHAVIOUR_H
#define KAMIKAZE_BEHAVIOUR_H

#include "BehaviourStrategy.h"

#include <string>


class KamikazeBehaviour: public BehaviourStrategy{
    private:
        KamikazeBehaviour(){};

	static std::string NAME ;
        static const T color[3];

        static KamikazeBehaviour* kamikazebehaviour;

        bool has_reset_orientation = 0;

    public:
	~KamikazeBehaviour();
	
        static KamikazeBehaviour* getBehaviourInstance();
	static void getRidOfInstance();
	
        std::string getBehaviourName() override;
        static const T* getColor() ;

	std::vector<Animal *> nearestNeighbors(Animal* pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal* pet, double speed, Environment& myEnvironment) override;

};

#endif
