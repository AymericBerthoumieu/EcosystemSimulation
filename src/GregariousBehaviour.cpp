#include "GregariousBehaviour.h"
#include "MoveUtils.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

// Définition du nom du comportement 
std::string GregariousBehaviour::NAME = "B_Gregarious";

// Initialisation du comportement avec un pointeur nul
GregariousBehaviour* GregariousBehaviour::gregariousbehaviour= nullptr;

std::string GregariousBehaviour::getBehaviourName(){
   return NAME;
}

// Cette méthode sera appelée lors de la création du
// (singleton) comportement 
void GregariousBehaviour::getRidOfInstance(void){
   delete gregariousbehaviour;
}

// Cette méthode permet de créer une fois pour toute
// une instance du comportement 
GregariousBehaviour* GregariousBehaviour::getBehaviourInstance(){
   if (gregariousbehaviour == nullptr ){
        gregariousbehaviour = new GregariousBehaviour(); 
    }
    return gregariousbehaviour;
}

// Méthode permettant de récupérer les bestioles environnantes
std::vector<Animal *> GregariousBehaviour::nearestNeighbors(Animal* pet, Environment& myEnvironment){

   // On récupère le vecteurs des voisins détectés dans l'environnement
   std::vector<Animal *> pets = myEnvironment.detectedNeighbors(pet);
   return pets;}

void GregariousBehaviour::move(int xLim, int yLim, Animal* pet, Environment& myEnvironment) {


   auto cord = pet->getCoordinates();
   auto cumul = pet->getCumul();
   auto orient_speed = pet->getOrientationSpeed();

   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);

   // On calcule la direction moyenne des bestioles environnantes

   double all_orientation = 0;
   int nb_neighbors = 0;
   std::vector<Animal *> closestPets = this->nearestNeighbors(pet,myEnvironment);

   for (std::vector<Animal *>::iterator it = closestPets.begin() ; it != closestPets.end() ; ++it){

      auto neighbor_orient_speed = (*it)->getCoordinates();
      double neighbor_orient = std::get<0>(neighbor_orient_speed);

      all_orientation += neighbor_orient;
      nb_neighbors += 1;

   }


   // S'il n'y a aucune bestiole environante, la bestiole
   // courante poursuivra son mouvement avec son orientation
   // précédente

   if(nb_neighbors != 0 && nb_neighbors >= LIMIT_SURROUNDING){

      orientation = all_orientation/nb_neighbors;
      
   }

   // On définit les nouveaux paramètres de mouvement de la bestiole
   MoveUtils::setMoveParameters(pet, x, y, xLim, yLim, orientation, speed, cumulX, cumulY);
} 

  