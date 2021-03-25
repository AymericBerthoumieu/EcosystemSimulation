//
// Created by aymeric on 12/03/2021.
//
#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include "FearfulBehaviour.h"

#include <iostream>

using namespace std;

int main() {
    int life = 10;
    cout << "[TEST] the pet must die after " << life << " steps." << endl;

    int nb_animals = 1; // two animals
    string behaviour = FearfulBehaviour::getBehaviourInstance()->getBehaviourName();


    map<string, float> animalsDistribution = {{behaviour, 100}};

    Aquarium ecosystem(100, 100, 30, nb_animals, animalsDistribution);

    ecosystem.getEnvironment().setLife(life); // fixing life of the animals
    ecosystem.run(); // launch simulation

    return 0;
}