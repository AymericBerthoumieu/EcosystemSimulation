#include "Animal.h"

using namespace std;

class AnimalFactory {

    virtual Animal createMember(string behaviour="none") = 0;

public:
    virtual vector<Animal> initializePopulation() = 0;
    virtual vector<Animal> createMembersAtRuntime() = 0;
    virtual Animal createMember(Environment& environment, string behaviour="none") = 0;
    virtual void cloneMember(Animal* animal) = 0;
};    
