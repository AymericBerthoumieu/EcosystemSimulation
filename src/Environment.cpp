#include "Environment.h"

#include <cstdlib>
#include <ctime>


const T Environment::white[] = { (T)255, (T)255, (T)255 };

Environment::Environment(int _width, int _height) : UImg( _width, _height, 1, 3 ), width(_width), height(_height){
   cout << "const Environment" << endl;
   std::srand(time(NULL));}

Environment::~Environment(){
   cout << "dest Environment" << endl;}

void Environment::step(){
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for (std::vector<Pet>::iterator it = pets.begin() ; it != pets.end() ; ++it){
      cout << "Pet id" << it->get_id()  << endl;
      it->action( *this );
      it->draw( *this );}}

int Environment::nbNeighbors(const Pet& p){
   int nb = 0;
   for (std::vector<Pet>::iterator it = pets.begin() ; it != pets.end() ; ++it)
      if (!(p == *it) && p.isDetecting(*it))
         ++nb;
   return nb;}

std::vector<Pet> Environment::nearestNeigbors(Pet & pet){
   std::vector<Pet> petNeighbors;

   for (std::vector<Pet>::iterator it = pets.begin() ; it != pets.end() ; ++it)
      if (pet.isDetecting(*it)){
         //cout << "reach here" << endl;
         petNeighbors.push_back(*it);
      }

   return petNeighbors;
}

