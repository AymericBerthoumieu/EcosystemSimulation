#include "Environment.h"
#include "PetFactory.h"

#include <cstdlib>
#include <ctime>

const T Environment::white[] = { (T)255, (T)255, (T)255 };

Environment::Environment(int _width, int _height, int nbAnimalsToStartWith, AnimalFactory& factory, Statistics& stats) : UImg( _width, _height, 1, 3 ), width(_width), height(_height), 
   petCreator(factory), statistics(stats){
   cout << "const Environment" << endl;
   this->animals = this->petCreator.initializePopulation(nbAnimalsToStartWith);
    cout << "((((((((((((((((((((((((" << endl;
#include <memory>
    for (auto const &pet : this->animals) {
       cout << "number of pets: "<< std::addressof(pet) << endl;
    }
   std::srand(time(NULL));}

Environment::~Environment(){
    delete &petCreator;
    delete &statistics;
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
