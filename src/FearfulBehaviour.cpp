#include "FearfulBehaviour.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>


std::string FearfulBehaviour::NAME = "Fearful";

std::string FearfulBehaviour::getBehaviourName(){
   return NAME;
}

std::vector<Animal> FearfulBehaviour::nearestNeighbors(Animal& pet, Environment& myEnvironment){

   double         dist;
   std::vector<Animal> closestPets;
   std::vector<Animal> pets = myEnvironment.detectedNeighbors(pet);

   auto cord = pet.getCoordinates();
   int x = std::get<0>(cord);
   int y = std::get<1>(cord);


   for (std::vector<Animal>::iterator it = pets.begin() ; it != pets.end() ; ++it){

      auto neighbor_cord = it->getCoordinates();
      int neighbor_x = std::get<0>(neighbor_cord);
      int neighbor_y = std::get<1>(neighbor_cord);

      dist = std::sqrt( (x-neighbor_x)*(x-neighbor_x) + (y-neighbor_y)*(y-neighbor_y) );
      if ( dist <= RADIUS_SURROUNDING ){
         closestPets.push_back(*it);}
      }

      return closestPets;}


void FearfulBehaviour::move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) {


   auto cord = pet.getCoordinates();
   auto cumul = pet.getCumul();
   auto orient_speed = pet.getOrientationSpeed();

   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);

   // On calcule le nombre de bestioles environnantes

   
   int nb_neighbors = 0;

   std::vector<Animal> closestPets = this->nearestNeighbors(pet,myEnvironment);

   for (std::vector<Animal>::iterator it = closestPets.begin() ; it != closestPets.end() ; ++it){
     	
     	nb_neighbors += 1;

   }

   if(nb_neighbors >= LIMIT_SURROUNDING){

   		orientation = M_PI-orientation;
  	  	speed = pet.getMaxSpeed();
  	  	cout << "Orientation Updated and neigbors are " << nb_neighbors << endl;

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
