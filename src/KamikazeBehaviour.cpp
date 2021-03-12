#include "KamikazeBehaviour.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <limits>


std::string KamikazeBehaviour::NAME = "Kamikaze";

std::string KamikazeBehaviour::getBehaviourName(){
   return NAME;
}

std::vector<Animal> KamikazeBehaviour::nearestNeighbors(Animal& pet, Environment& myEnvironment){

   double         dist;
   std::vector<Animal> closestPets;
   std::vector<Animal> pets = myEnvironment.detectedNeighbors(pet);

   auto cord = pet.getCoordinates();
   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double best_distance = std::numeric_limits<double>::max();

   for (std::vector<Animal>::iterator it = pets.begin() ; it != pets.end() ; ++it){

      auto neighbor_cord = it->getCoordinates();
      int neighbor_x = std::get<0>(neighbor_cord);
      int neighbor_y = std::get<1>(neighbor_cord);

      dist = std::sqrt( (x-neighbor_x)*(x-neighbor_x) + (y-neighbor_y)*(y-neighbor_y) );
      if(dist <= best_distance){
         closestPets.push_back(*it);
      }

      }
      

      return closestPets;}



void KamikazeBehaviour::move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) {


   auto cord = pet.getCoordinates();
   auto cumul = pet.getCumul();
   auto orient_speed = pet.getOrientationSpeed();

   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);

   // We retrieve the coordinates of the nearest pet

   double nearestPet_x;
   double nearestPet_y;

   std::vector<Animal> closestPets = this->nearestNeighbors(pet,myEnvironment);

   // check if there is at leat one detected pet which should be the nearest one

   cout << "Previous Orientation " << orientation  << endl;

   if(!closestPets.empty()){

      auto nearestPet_cord = closestPets.back().getCoordinates();
      nearestPet_x = std::get<0>(nearestPet_cord);
      nearestPet_y = std::get<1>(nearestPet_cord);

      double abs_diff = abs(nearestPet_x-x);
      double ord_diff = abs(nearestPet_y-y);

      if(ord_diff != 0){
         orientation = acos (abs_diff / ord_diff) ;

         if(abs_diff==0){

            if (nearestPet_y >= y){
               orientation = M_PI/2;
            }

            else{
               orientation = -M_PI/2;
            }
         }
      }

      else{

         if (nearestPet_x >= x){
            orientation = 2*M_PI;
         }

         else{
            orientation = M_PI;
         }
      }
   }

   cout << "New Orientation " << orientation  << endl;

   

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
