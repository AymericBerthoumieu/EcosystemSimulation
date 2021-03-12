#include "Environment.h"

#include <cstdlib>
#include <ctime>


const T Environment::white[] = { (T)255, (T)255, (T)255 };

Environment::Environment(int _width, int _height) : UImg( _width, _height, 1, 3 ), width(_width), height(_height){
   cout << "const Environment" << endl;
   std::srand(time(NULL));}

Environment::~Environment(){
   cout << "dest Environment" << endl;}

int Environment::getWidth() const{
   return width;}

int Environment::getHeight() const{
   return height;}	   

void Environment::step(){
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for (std::vector<Animal>::iterator it = animals.begin() ; it != animals.end() ; ++it){
      it->action( *this );
      it->draw( *this );}}

int Environment::nbNeighbors(const Animal& a){
   int nb = 0;
   for (std::vector<Animal>::iterator it = animals.begin() ; it != animals.end() ; ++it)
      if (!(a == *it) && a.isDetecting(*it))
         ++nb;
   return nb;}

void Environment::addMember(const Animal & a) { 
	this->animals.push_back(a); 
	this->animals.back().initCoords(width, height);}
