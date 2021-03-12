//
// Created by aymeric on 12/03/2021.
//
#include "Aquarium.h"
#include "Environment.h"
#include "Animal.h"
#include "Pet.h"

#include <iostream>

using namespace std;

int main() {
    Aquarium ecosystem(100, 100, 30);
    int life = 1000;

    cout << "[TEST] the pets should have a collision." << endl;
    for (int i = 1; i <= 2; ++i)
        ecosystem.getEnvironment().addMember(Pet());
    ecosystem.getEnvironment().setLife(life); // fixing life of the pet
    ecosystem.run(); // launch simulation

    return 0;
}