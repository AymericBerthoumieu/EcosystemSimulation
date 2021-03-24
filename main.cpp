#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"

#include <iostream>

using namespace std;


int main() {
    int windowWidth = 1200; //640
    int windowHeight = 800; //480
    int delay = 30;
    int startingNbPets = 100;
    map<string, float> animalsDistribution = {{KamikazeBehaviour::getBehaviourInstance()->getBehaviourName(),   25},
                                              {FearfulBehaviour::getBehaviourInstance()->getBehaviourName(),    25},
                                              {GregariousBehaviour::getBehaviourInstance()->getBehaviourName(), 25},
                                              {"b_multiple",                                                    25}};
    Aquarium ecosystem(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution);

    ecosystem.run();

    return 0;
}
