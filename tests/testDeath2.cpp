//
// Created by aymeric on 12/03/2021.
//
#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"

#include <iostream>

using namespace std;

int main() {
    cout << "[TEST] the pets must die at different steps." << endl;

    int startingNbPets = 10;

    map<string, float> animalsDistribution = {{KamikazeBehaviour::getBehaviourInstance()->getBehaviourName(),   10},
                                              {FearfulBehaviour::getBehaviourInstance()->getBehaviourName(),    30},
                                              {GregariousBehaviour::getBehaviourInstance()->getBehaviourName(), 40},
                                              {"b_multiple",                                                    20}};
    Aquarium ecosystem(1200, 800, 30, startingNbPets, animalsDistribution);

    ecosystem.run(); // launch simulation

    return 0;
}