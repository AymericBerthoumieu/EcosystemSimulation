#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"

#include <iostream>

using namespace std;


int main(){
    int windowWidth = 1200; //640
    int windowHeight = 800; //480
    int delay = 30;
    int startingNbPets = 30;
    map<string, float> animalsDistribution = {{KamikazeBehaviour::getBehaviourName(), 30}, {FearfulBehaviour::getBehaviourName(), 30}, {GregariousBehaviour::getBehaviourName(), 20}, {"multiple", 20}};
    Aquarium ecosystem(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution);

//   for (int i = 1; i <= 20; ++i)
//      ecosystem.getEnvironment().addMember(Pet());
    ecosystem.run();

    return 0;}

