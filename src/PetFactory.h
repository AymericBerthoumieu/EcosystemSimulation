#include "Animal.h"
#include "AnimalFactory.h"

#include <map>
#include <iostream>

using namespace std;


class Statistics;

class PetFactory: public AnimalFactory {
    Statistics statistics();
    map<string, float> accessoriesAndCaptorsDistribution;
    map<string, float> behaviorsDistribution;


    Animal createMember(string behaviour="none");

public:
    vector<Animal> initializePopulation();
    vector<Animal> createMembersAtRuntime() {cout << "PetFactory::createMembersAtRuntime is currently not implemented. You shouldn't use it!" << endl; return vector<Animal>();};
    Animal createMember(Environment& environment, string behaviour="none") {cout << "PetFactory::createMember is currently not implemented. You shouldn't use it!" << endl; return Animal();};
    void cloneMember(Animal* animal) {cout << "PetFactory::cloneMember is currently not implemented. You shouldn't use it!" << endl;};
};    
