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
    Aquarium ecosystem(640, 480, 30);

    int life = 10;
    cout << "[TEST] the pet must die after " << life << " steps." << endl;
    for (int i = 1; i <= 1; ++i)
        ecosystem.getEnvironment().addMember(Pet());
    ecosystem.getEnvironment().setLife(life); // fixing life of the pet
    ecosystem.run(); // launch simulation

    return 0;
}