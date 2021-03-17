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
   Animal closest;
   std::vector<Animal> closestPets;
   std::vector<Animal> pets = myEnvironment.detectedNeighbors(pet);

   auto cord = pet.getCoordinates();
   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double best_distance = std::numeric_limits<double>::infinity();
   int neighbor = 0;
   for (std::vector<Animal>::iterator it = pets.begin() ; it != pets.end() ; ++it){

      auto neighbor_cord = it->getCoordinates();
      int neighbor_x = std::get<0>(neighbor_cord);
      int neighbor_y = std::get<1>(neighbor_cord);
      ++neighbor;
      dist = std::sqrt( (x-neighbor_x)*(x-neighbor_x) + (y-neighbor_y)*(y-neighbor_y) );
      if(dist <= best_distance){
            closest = *it;
      }

      }
      //cout << "Number of neighbor Kamikaze" << neighbor << endl;
      if(neighbor != 0){
         closestPets.push_back(closest);
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

   //cout << "No neighbor for Kamikaze ? " << closestPets.size() << endl;

   if(!closestPets.empty()){

      cout << "At least one neighbor for Kamikaze ! " << endl;
      has_reset_orientation = 0;

      auto nearestPet_cord = closestPets.back().getCoordinates();
      nearestPet_x = std::get<0>(nearestPet_cord);
      nearestPet_y = std::get<1>(nearestPet_cord);

      double abs_diff = nearestPet_x-x;
      double ord_diff = nearestPet_y-y;
      double hypothenuse = sqrt (pow(abs_diff,2)+pow(ord_diff,2));

      //cout << "Nearest neighbor for kamikaze"<< endl;

      if(hypothenuse != 0){

         orientation = acos (abs_diff / hypothenuse) ;
         /*if(abs_diff >= 0){
            orientation = acos (abs_diff / hypothenuse) ;
         }
         else{
            orientation = M_PI - acos (abs_diff / hypothenuse) ;
         }*/

      }

      /*if(hypothenuse == abs(abs_diff)){

         if(abs_diff >= 0){
            orientation = 2*M_PI; ;
         }
         else{
            orientation = M_PI;
         }
      }

      if(hypothenuse == abs(ord_diff)){
         
         if(ord_diff >= 0){
            orientation = M_PI/2; ;
         }
         else{
            orientation = -M_PI/2;
         }
      }*/
   }


   else{
      // If no nearest neighbor, we instantiate a random direction to the Animal
      cout << "No neighbor for Kamikaze "<< endl;
      if (!has_reset_orientation){
         cout << "Reset Orientation for Kamikaze "<< orientation << endl;
         has_reset_orientation = 1;
         orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
      }
   }

   //cout << "Nearest orientation for kamikaze "<<  orientation << endl;
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