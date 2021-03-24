#include "FearfulBehaviour.h"
#include "MoveUtils.h"


#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>


std::string FearfulBehaviour::NAME = "b_Fearful";

std::string FearfulBehaviour::getBehaviourName(){
   return NAME;
}


const T FearfulBehaviour::color[3] = {0, 0, 230};

const T* FearfulBehaviour::getColor() {
    return color;
}


FearfulBehaviour* FearfulBehaviour::fearfulbehaviour= nullptr;

FearfulBehaviour* FearfulBehaviour::getBehaviourInstance(){
   if (fearfulbehaviour == nullptr ){
        fearfulbehaviour = new FearfulBehaviour(); 
    }
    return fearfulbehaviour;
}

void FearfulBehaviour::getRidOfInstance(void){
   delete fearfulbehaviour;
}

FearfulBehaviour::~FearfulBehaviour() {
}


// Méthode permettant de récupérer les bestioles environnantes
std::vector<Animal *> FearfulBehaviour::nearestNeighbors(Animal* pet, Environment& myEnvironment){
  std::vector<Animal *> pets = myEnvironment.detectedNeighbors(pet);
  return pets;}


void FearfulBehaviour::move(int xLim, int yLim, Animal* pet, Environment& myEnvironment) {
   auto cord = pet->getCoordinates();
   auto cumul = pet->getCumul();
   auto orient_speed = pet->getOrientationSpeed();

   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);

   // On calcule le nombre de bestioles environnantes
   int nb_neighbors = 0;
   std::vector<Animal *> closestPets = this->nearestNeighbors(pet,myEnvironment);
   for (std::vector<Animal *>::iterator it = closestPets.begin() ; it != closestPets.end() ; ++it){
     	nb_neighbors += 1;
   }

   // Si le nombre de bestioles environnantes est
   // suffisamment grand alors la bestiole change de vitesse
   if(nb_neighbors >= LIMIT_SURROUNDING){
   		orientation = M_PI-orientation;
  	  	speed = pet->getMaxSpeed();
  	  }

    // Si le nombre de bestioles environnantes n'est pas 
    // important et que sa vitesse est la vitesse maximale
    // la bestiole reprend sa vitesse de croisière
  	if(nb_neighbors < LIMIT_SURROUNDING && speed == pet->getMaxSpeed()){
  		speed = CRUISING_SPEED;
  	}

    // On définit les nouveaux paramètres de mouvement de la bestiole
    MoveUtils::setMoveParameters(pet, x, y, xLim, yLim, orientation, speed, cumulX, cumulY);
  } 
