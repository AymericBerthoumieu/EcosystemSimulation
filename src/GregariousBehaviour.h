#ifndef GREGARIOUS_BEHAVIOUR_H
#define GREGARIOUS_BEHAVIOUR_H


#include "BehaviourStrategy.h"

#include <string>
#include <UImg.h>


class GregariousBehaviour: public BehaviourStrategy{
    private:
	static std::string NAME ;
        static const T color[3];

	static GregariousBehaviour* gregariousbehaviour;
	const int LIMIT_SURROUNDING = 1;

	GregariousBehaviour(){};

    public:
	~GregariousBehaviour();
        
	static GregariousBehaviour* getBehaviourInstance();
	static void getRidOfInstance();

	static std::string getBehaviourName();
        static const T* getColor();

	std::vector<Animal *> nearestNeighbors(Animal* pet, Environment& myEnvironment) override;
	void move(int xLim, int yLim, Animal* pet, Environment& myEnvironment) override;

};

#endif
