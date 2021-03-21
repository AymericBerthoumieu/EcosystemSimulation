#include <iostream>

#include "FearfulBehaviour.h"

string FearfulBehaviour::NAME = "b_Fearful";

const T FearfulBehaviour::color[3] = {0, 0, 230};

const T* FearfulBehaviour::getColor() {
    return color;
}


FearfulBehaviour* FearfulBehaviour::fearfulbehaviour= nullptr;


FearfulBehaviour::~FearfulBehaviour() {
    delete[] &color;
}


string FearfulBehaviour::getBehaviourName(){
   return NAME;
}


void FearfulBehaviour::getRidOfInstance(void){
   delete fearfulbehaviour;
   cout << " LA DESTRUCTION DE LA PEUREUSE A EFFECTIVEMENT EU LIEU !" <<endl;
}


FearfulBehaviour* FearfulBehaviour::getBehaviourInstance(){
   if (fearfulbehaviour == nullptr ){
        fearfulbehaviour = new FearfulBehaviour();
    }
    return fearfulbehaviour;
}


vector<Animal> FearfulBehaviour::nearestNeighbors(Animal& pet, Environment& myEnvironment){
  vector<Animal> pets = myEnvironment.detectedNeighbors(pet);
  return pets;}


void FearfulBehaviour::move(int xLim, int yLim, Animal& pet, Environment& myEnvironment) {
   auto cord = pet.getCoordinates();
   auto cumul = pet.getCumul();
   auto orient_speed = pet.getOrientationSpeed();

   int x = get<0>(cord);
   int y = get<1>(cord);
   double cumulX = get<0>(cumul);
   double cumulY = get<1>(cumul);
   double orientation = get<0>(orient_speed);
   double speed = get<1>(orient_speed);

   // Computing the number of surrounding animals 
   int nb_neighbors = 0;
   vector<Animal> closestPets = this->nearestNeighbors(pet,myEnvironment);
   for (vector<Animal>::iterator it = closestPets.begin() ; it != closestPets.end() ; ++it){
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

