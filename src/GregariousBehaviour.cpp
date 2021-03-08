#include "GregariousBehaviour.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>


std::string GregariousBehaviour::NAME = "Gregarious";

std::string GregariousBehaviour::getBehaviourName(){
   return NAME;
}

std::vector<Pet> GregariousBehaviour::nearestNeighbors(Pet& pet, Environment& myEnvironment){

   double         dist;
   std::vector<Pet> closestPets;
   std::vector<Pet> pets = myEnvironment.nearestNeighbors(pet);

   auto cord = pet.get_coordinates();
   int x = std::get<0>(cord);
   int y = std::get<1>(cord);


   for (std::vector<Pet>::iterator it = pets.begin() ; it != pets.end() ; ++it){

      auto neighbor_cord = it->get_coordinates();
      int neighbor_x = std::get<0>(neighbor_cord);
      int neighbor_y = std::get<1>(neighbor_cord);

      dist = std::sqrt( (x-neighbor_x)*(x-neighbor_x) + (y-neighbor_y)*(y-neighbor_y) );
      if ( dist <= RADIUS_SURROUNDING ){
         closestPets.push_back(*it);}
      }

      return closestPets;}

void GregariousBehaviour::move(int xLim, int yLim, Pet& pet, Environment& myEnvironment) {


   auto cord = pet.get_coordinates();
   auto cumul = pet.get_cumul();
   auto orient_speed = pet.get_orient_speed();

   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);

   // On calcule la direction moyenne des bestioles environnantes

   double all_orientation = 0;
   int nb_neighbors = 0;

   std::vector<Pet> closestPets = this->nearestNeighbors(pet,myEnvironment);

   for (std::vector<Pet>::iterator it = closestPets.begin() ; it != closestPets.end() ; ++it){

      auto neighbor_orient_speed = it->get_coordinates();
      int neighbor_orient = std::get<0>(neighbor_orient_speed);
      all_orientation += neighbor_orient;
      nb_neighbors += 1;

   }

   // checker si nb_neighbors != 0

   if(nb_neighbors != 0)
      orientation = all_orientation/nb_neighbors;

   

   


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
   
   pet.set_coordinates(x,y);
   pet.set_cumul(cumulX,cumulY);
   pet.set_orient_speed(orientation,speed); 
   } 

  