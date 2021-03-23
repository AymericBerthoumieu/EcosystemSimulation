//
// Created by aymeric on 12/03/2021.
//
#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include "KamikazeBehaviour.h"

#include <iostream>

using namespace std;

int main() {
    cout << "[TEST] the pets should have a collision." << endl;

    int nb_animals = 2; // two animals
    int life = 100000000;
    string behaviour = KamikazeBehaviour::getBehaviourInstance()->getBehaviourName();


    map<string, float> animalsDistribution = {{behaviour, 100}}; // all kamikaze in order to have collision
    Aquarium ecosystem(80, 80, 30, nb_animals, animalsDistribution);
    ecosystem.getEnvironment().setLife(life); // fixing life of the animals

    ecosystem.run(); // launch simulation

    return 0;
}