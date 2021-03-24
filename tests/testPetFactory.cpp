#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"

#include <iostream>

using namespace std;


int main(){
    int windowWidth = 640; 
    int windowHeight = 480; 
    int delay = 30;
    int startingNbPets = 10;

    map<string, float> animalsDistribution = {{KamikazeBehaviour::getBehaviourInstance()->getBehaviourName(), 100}};
    map<string, float> animalsDistribution2 = {{KamikazeBehaviour::getBehaviourInstance()->getBehaviourName(), 50}, {FearfulBehaviour::getBehaviourInstance()->getBehaviourName(), 50}};
    map<string, float> animalsDistribution3 = {{KamikazeBehaviour::getBehaviourInstance()->getBehaviourName(), 30}, {FearfulBehaviour::getBehaviourInstance()->getBehaviourName(), 30}, {GregariousBehaviour::getBehaviourInstance()->getBehaviourName(), 20}, {"b_multiple", 20}};

    Aquarium ecosystem = Aquarium(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution);
    ecosystem.run();

    Aquarium ecosystem2 = Aquarium(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution2);
    ecosystem2.run();

    Aquarium ecosystem3 = Aquarium(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution3);
    ecosystem3.run();

    return 0;}

