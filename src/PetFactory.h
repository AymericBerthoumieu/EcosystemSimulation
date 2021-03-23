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
    // Distribution of pets to respect in the initial generation.
    // A float number disctates the proportion in the total number of pets to create.
    map<string, float> behavioursDistribution;
    // List of implemented accessories and captors.
    // Can also be used the control the accessories and captors pets can have for a given session.
    unordered_set<string> availableAccessoriesAndCaptors;

    // see comment in AnimalFactory
    Animal* createMember(string behaviour="none") override;

public:
    // xLim and yLim are the x and y limits for setting the position of pets in the window
    PetFactory(int xLim, int yLim, map<string, float> behavioursDistribution, unordered_set<string> availableAccessoriesAndCaptors, Statistics& stats);

    // see comment in AnimalFactory
    vector<Animal*> initializePopulation(int number) override;
};    

#endif

