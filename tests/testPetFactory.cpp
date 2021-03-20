#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"
//#include <unistd.h>

#include <iostream>

using namespace std;


int main(){
    int windowWidth = 640; 
    int windowHeight = 480; 
    int delay = 30;
    int startingNbPets = 10;

    map<string, float> animalsDistribution = {{KamikazeBehaviour::getBehaviourName(), 100}};
    map<string, float> animalsDistribution2 = {{KamikazeBehaviour::getBehaviourName(), 50}, {FearfulBehaviour::getBehaviourName(), 50}};
    map<string, float> animalsDistribution3 = {{KamikazeBehaviour::getBehaviourName(), 30}, {FearfulBehaviour::getBehaviourName(), 30}, {GregariousBehaviour::getBehaviourName(), 20}, {"multiple", 20}};

    Aquarium* ecosystem = new Aquarium(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution);
    ecosystem->run();
    //usleep(5*pow(10,6));
    //ecosystem.close();

    delete ecosystem;
     
    Aquarium* ecosystem2 = new Aquarium(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution2);
    ecosystem2->run();
    //usleep(5*pow(10,6));
    //ecosystem2.close();

    delete ecosystem2;

    Aquarium* ecosystem3 = new Aquarium(windowWidth, windowHeight, delay, startingNbPets, animalsDistribution3);
    ecosystem3->run();
    //usleep(5*pow(10,6));
    //ecosystem3.close();

    delete ecosystem3;

    return 0;}

