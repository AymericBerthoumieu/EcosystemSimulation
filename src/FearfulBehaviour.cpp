#include "FearfulBehaviour.h"
#include "MoveUtils.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

// Définition du nom du comportement 
std::string FearfulBehaviour::NAME = "B_Fearful";

// Initialisation du comportement avec un pointeur nul
FearfulBehaviour* FearfulBehaviour::fearfulbehaviour= nullptr;

std::string FearfulBehaviour::getBehaviourName(){
   return NAME;
}

// Cette méthode sera appelée lors de la création du
// (singleton) comportement 
void FearfulBehaviour::getRidOfInstance(void){
   delete fearfulbehaviour;
}

// Cette méthode permet de créer une fois pour toute
// une instance du comportement 
FearfulBehaviour* FearfulBehaviour::getBehaviourInstance(){
   if (fearfulbehaviour == nullptr ){
        fearfulbehaviour = new FearfulBehaviour(); 
    }
    return fearfulbehaviour;
}

// Méthode permettant de récupérer les bestioles environnantes
std::vector<Animal *> FearfulBehaviour::nearestNeighbors(Animal* pet, Environment& myEnvironment){

  // On récupère le vecteurs des voisins détectés dans l'environnement
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
