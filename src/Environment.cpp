#include "Environment.h"
#include "AnimalFactory.h"
#include "Statistics.h"

#include <cstdlib>
#include <ctime>
#include <math.h>
#include <memory>


const T Environment::white[] = {(T) 255, (T) 255, (T) 255};

Environment::Environment(int _width, int _height, int nbAnimalsToStartWith, AnimalFactory& factory, Statistics& stats): 
 UImg( _width, _height, 1, 3 ), width(_width), height(_height), 
 petCreator(factory), statistics(stats){
   cout << "const Environment" << endl;
   this->animals = this->petCreator.initializePopulation(nbAnimalsToStartWith);
   std::srand(time(NULL));
}


Environment::~Environment() {
    delete &petCreator;
    delete &statistics;
    // TODO : delete animals
    //cout << "dest Environment" << endl;
}


int Environment::getWidth() const{
   return width;}


int Environment::getHeight() const{
   return height;}


void Environment::step() {
    ++nb_steps;
    cimg_forXY(*this, x, y)
    fillC(x, y, 0, white[0], white[1], white[2]);

    for (std::vector<Animal>::iterator it = animals.begin(); it != animals.end(); ++it) {
        hasCollision(*it); // check if there is a collision
        it->action(*this);

        // we draw only if the pet is still alive
        if (it->getLife() > 0) {
            it->draw(*this);
        }
    }
    this->die();
}


//int Environment::nbNeighbors(const Animal& a){
//   int nb = 0;
//   for (std::vector<Animal>::iterator it = animals.begin() ; it != animals.end() ; ++it)
//      if (!(a == *it) && a.isDetecting(*it))
//         ++nb;
//   return nb;}


void Environment::addMember(const Animal & a) { 
	this->animals.push_back(a); 
	this->animals.back().initCoords(width, height);}


std::vector<Animal> Environment::detectedNeighbors(Animal & a){
   std::vector<Animal> petNeighbors;

   for (std::vector<Animal>::iterator it = animals.begin() ; it != animals.end() ; ++it)
      if (a.getIdentity() != it->getIdentity() && a.isDetecting(*it)){
         //cout << "Is detecting" << endl;
         petNeighbors.push_back(*it);
      }

   return petNeighbors;
}


bool mustDie(Animal const &p) {
    if (p.getLife() <= 0) {
        //cout << " Pets (" << p.getIdentity() << ") is gonna be destructed with life = " << p.getLife() << endl;
    }
    return p.getLife() <= 0;
}
void Environment::die() {
    //cout << "At step <" << nb_steps << "> : " << endl;
    auto it = std::remove_if(animals.begin(), animals.end(), mustDie);
    animals.erase(it, animals.end());
}


void Environment::hasCollision(Animal &p) {
    int id = p.getIdentity();
    double r = 15; // collision radius
    std::tuple<int, int> pet_coords = p.getCoordinates();
    std::tuple<int, int> current_coords;
    double dist;

    for (std::vector<Animal>::iterator it = animals.begin(); it != animals.end(); ++it) {
        if (it->getIdentity() != id) {
            current_coords = it->getCoordinates();

            dist = std::pow((std::pow((double(std::get<0>(pet_coords)) - double(std::get<0>(current_coords))), 2) +
                             std::pow((double(std::get<1>(pet_coords)) - double(std::get<1>(current_coords))), 2)), 0.5);
            if (dist <= r) {
                //cout << "Collision of " << p.getIdentity() << endl;
                p.onCollision();
            }
        }
    }
}


// ############################## for tests ########################################
void Environment::setLife(int i){
    //cout << "[TEST] Setting life of all pets at " << i << "." << endl;
    for (std::vector<Animal>::iterator it = animals.begin(); it != animals.end(); ++it) {
        it->setLife(i);
    }
}

