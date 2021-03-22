#ifndef PET_FACTORY_H
#define PET_FACTORY_H

#include "AnimalFactory.h"
#include "Statistics.h"

#include <unordered_set>

using namespace std;


class PetFactory final: public AnimalFactory {
    int XLIM;
    int YLIM;

    Statistics& statistics;
    map<string, float> behavioursDistribution;
    unordered_set<string> availableAccessoriesAndCaptors;

    Animal* createMember(string behaviour="none") override;

public:
//    PetFactory();
    PetFactory(int xLim, int yLim, map<string, float> behavioursDistribution, unordered_set<string> availableAccessoriesAndCaptors, Statistics& stats);

    vector<Animal*> initializePopulation(int number) override;
};    

#endif

