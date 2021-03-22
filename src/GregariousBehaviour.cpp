#include "GregariousBehaviour.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>


std::string GregariousBehaviour::NAME = "Gregarious";

GregariousBehaviour* GregariousBehaviour::gregariousbehaviour= nullptr;

std::string GregariousBehaviour::getBehaviourName(){
   return NAME;
}

void GregariousBehaviour::getRidOfInstance(void){
   delete gregariousbehaviour;
   cout << " LA DESTRUCTION DE LA GREGAIRE EFFECTIVEMENT LIEU !" <<endl;   
}

GregariousBehaviour* GregariousBehaviour::getBehaviourInstance(){
   if (gregariousbehaviour == nullptr ){
        gregariousbehaviour = new GregariousBehaviour(); 
    }
    return gregariousbehaviour;
}

std::vector<Animal> GregariousBehaviour::nearestNeighbors(Animal& pet, Environment& myEnvironment){


   std::vector<Animal> pets = myEnvironment.detectedNeighbors(pet);
   return pets;}

void GregariousBehaviour::move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) {


   auto cord = pet.getCoordinates();
   auto cumul = pet.getCumul();
   auto orient_speed = pet.getOrientationSpeed();
   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);
   // On calcule la direction moyenne des bestioles environnantes

   double all_orientation = 0;
   int nb_neighbors = 0;


   //cout << "Old orientation "  <<  orientation << endl;
   std::vector<Animal> closestPets = this->nearestNeighbors(pet,myEnvironment);
   for (std::vector<Animal>::iterator it = closestPets.begin() ; it != closestPets.end() ; ++it){
      auto neighbor_orient_speed = it->getCoordinates();
      double neighbor_orient = std::get<0>(neighbor_orient_speed);

      all_orientation += neighbor_orient;
      nb_neighbors += 1;

   }


   // checker si nb_neighbors != 0

   if(nb_neighbors != 0 && nb_neighbors >= LIMIT_SURROUNDING){

      orientation = all_orientation/nb_neighbors;
      
   }

   //cout << "Orientation Updated and neigbors are " << nb_neighbors << " New orientation "  <<  orientation << endl;

   double nx, ny;
   double dx = cos( orientation )*speed;
   double dy = -sin( orientation )*speed;
   int cx, cy;

   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;}
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;}

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;}
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;} 


   // We modify the pet travel information
   
   pet.setCoordinates(x,y);
   pet.setCumul(cumulX,cumulY);
   pet.setOrientationSpeed(orientation,speed); 
   } 

  