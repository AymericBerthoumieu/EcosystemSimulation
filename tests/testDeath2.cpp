//
// Created by aymeric on 12/03/2021.
//
#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include <iostream>

using namespace std;

int main() {
    Aquarium ecosystem(640, 480, 30);

    cout << "[TEST] the pets must die at different steps." << endl;
    for (int i = 1; i <= 5; ++i)
        ecosystem.getEnvironment().addMember(Pet());
    ecosystem.run(); // launch simulation

    return 0;
}