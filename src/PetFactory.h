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

    Animal& createMember(string behaviour="none") override;

public:
    PetFactory();
    PetFactory(int xLim, int yLim, map<string, float> behavioursDistribution, unordered_set<string> availableAccessoriesAndCaptors, Statistics& stats);

    vector<Animal> initializePopulation(int number) override;
//    vector<Animal> createMembersAtRuntime() override {cout << "PetFactory::createMembersAtRuntime is currently not implemented. You shouldn't use it!" << endl; return vector<Animal>();};
//    Animal& createMember(Environment& environment, string behaviour="none") override {cout << "PetFactory::createMember is currently not implemented. You shouldn't use it!" << endl; return Animal();};
//    Animal& cloneMember(Animal* animal) override {cout << "PetFactory::cloneMember is currently not implemented. You shouldn't use it!" << endl;};
};    

#endif
