#include "FearfulBehaviour.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>


std::string FearfulBehaviour::NAME = "Fearful";

FearfulBehaviour* FearfulBehaviour::fearfulbehaviour= nullptr;

std::string FearfulBehaviour::getBehaviourName(){
   return NAME;
}

void FearfulBehaviour::getRidOfInstance(void){
   delete fearfulbehaviour;
   cout << " LA DESTRUCTION DE LA PEUREUSE EFFECTIVEMENT LIEU !" <<endl;   
}

FearfulBehaviour* FearfulBehaviour::getBehaviourInstance(){
   if (fearfulbehaviour == nullptr ){
        fearfulbehaviour = new FearfulBehaviour(); 
    }
    return fearfulbehaviour;
}

std::vector<Animal> FearfulBehaviour::nearestNeighbors(Animal& pet, Environment& myEnvironment){

  
  std::vector<Animal> pets = myEnvironment.detectedNeighbors(pet);
  return pets;}


void FearfulBehaviour::move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) {


   auto cord = pet.getCoordinates();
   auto cumul = pet.getCumul();
   auto orient_speed = pet.getOrientationSpeed();
   std::cout << "Fearfull move attribut" << std::endl;

   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);
    std::cout << "Fearfull move attribut 2" << std::endl;
   // On calcule le nombre de bestioles environnantes

   
   int nb_neighbors = 0;

   std::vector<Animal> closestPets = this->nearestNeighbors(pet,myEnvironment);
    std::cout << "Fearfull move std vector" << std::endl;
   for (std::vector<Animal>::iterator it = closestPets.begin() ; it != closestPets.end() ; ++it){
       std::cout << "Fearfull move For" << std::endl;
     	nb_neighbors += 1;

   }

   if(nb_neighbors >= LIMIT_SURROUNDING){

   		orientation = M_PI-orientation;
  	  	speed = pet.getMaxSpeed();
  	  	//cout << "Orientation Updated and neigbors are " << nb_neighbors << endl;

  	  }

  	// Otherwise we set the speed to the cruising speed

  	if(nb_neighbors < LIMIT_SURROUNDING && speed == pet.getMaxSpeed()){
  		speed = CRUISING_SPEED;
  	}


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
