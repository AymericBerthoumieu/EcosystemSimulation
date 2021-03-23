#include "Environment.h"
#include "AnimalFactory.h"
#include "Statistics.h"

#include <cstdlib>
#include <ctime>
#include <math.h>
#include <memory>
#include <vector>

string multiple = "b_multiple"; // name for multiple behaviour
const T Environment::white[] = {(T) 255, (T) 255, (T) 255};

Environment::Environment(int _width, int _height, int nbAnimalsToStartWith, AnimalFactory& factory, Statistics& stats): 
 UImg( _width, _height, 1, 3 ), width(_width), height(_height), 
 petCreator(factory), statistics(stats){
   cout << "const Environment" << endl;
   this->nb_steps =0;
   this->animals = this->petCreator.initializePopulation(nbAnimalsToStartWith);
   std::srand(time(NULL));
}


Environment::~Environment() {
    delete &petCreator;
    delete &statistics;
    for (std::vector<Animal *>::iterator it = animals.begin(); it != animals.end(); ++it) {
        delete *it;
    }

    cout << "dest Environment" << endl;
}

int Environment::getWidth() const {
    return width;
}

int Environment::getHeight() const {
    return height;
}

void Environment::step() {
    ++nb_steps; // increment the number of steps
    cout << "[" << nb_steps << "]" << endl;
    statistics.saveData(); // save statistics of the previous step before doing the new one

    cimg_forXY(*this, x, y)
    fillC(x, y, 0, white[0], white[1], white[2]);

    for (std::vector<Animal *>::iterator it = animals.begin(); it != animals.end(); ++it) {
        hasCollision(*it); // check if there is a collision
        (*it)->action(*this);// let the animal do the action he has to do

        // we draw only if the pet is still alive
        if ((*it)->getLife() > 0) {
            (*it)->draw(*this);
        }
    }
    this->die(); // delete the dead animals
}

void Environment::addMember(Animal* a) {
    // add an animal to the ecosystem
    this->animals.push_back(a);
    this->animals.back()->initCoords(width, height);
}

bool mustDie(Animal * p) {
    // return true if the p has a life < 0. It means p must die at the end of the step
    bool ret = p->getLife() <= 0;
    if (ret){delete p;} // the animal must be deleted
    return ret;
}


std::vector<Animal *> Environment::detectedNeighbors(Animal* a){
   std::vector<Animal *> petNeighbors;

   for (std::vector<Animal *>::iterator it = animals.begin() ; it != animals.end() ; ++it)
      if (a->getIdentity() != (*it)->getIdentity() && a->isDetecting(**it)){
         petNeighbors.push_back(*it);
      }
   return petNeighbors;
}

void Environment::die() {
    // kill animal in the ecosystem at the end of the step
    cout << "size = " << animals.size() << endl;
    // first we update Statistics
    for (std::vector<Animal*>::iterator iter = animals.begin(); iter != animals.end(); ++iter) {
        // All animal at the end of the vector at this step are going to die
        // Behaviours
        if ((*iter)->getLife() <= 0){
            if ((*iter)->getIsMultiple()) {
                cout << " decrement multiple " << endl;
                statistics.modifyData(multiple, false);
            } else {
                std::string behaviour = (*iter)->getBehaviourName();
                cout << " decrement " << behaviour << endl;
                statistics.modifyData(behaviour, false);
            }
            // Captors and accessories
            // TODO: decrement accessories and captors
            /*std::vector <std::string> acc = (*iter)->getAccessoriesAndCaptors();
            for (std::string element : acc) {
                statistics.modifyData(element, false);
            }*/
        }
    }

    // then we identify the animals to remove (if any)
    std::vector<Animal*>::iterator it = std::remove_if(animals.begin(), animals.end(), mustDie);

    // Finally, we delete the relevant animals
    animals.erase(it, animals.end());
}

void Environment::hasCollision(Animal* p) {
    // Check if p has a collision with another animal
    int id = p->getIdentity(); // unique id of the animal p
    double r = 15; // collision radius
    std::tuple<int, int> pet_coords = p->getCoordinates(); // coordinates of p
    std::tuple<int, int> current_coords; // will be used to contain coordinates of other animals
    double dist;// will me used to store the distance between p and another animal

    // we check for every other animals
    for (std::vector<Animal *>::iterator it = animals.begin(); it != animals.end(); ++it) {
        // first we verify if the animal is not itself
        if ((*it)->getIdentity() != id) {
            current_coords = (*it)->getCoordinates();// get the other animal coordinates

            // calculation of the distance between the two animals
            dist = std::pow((std::pow((double(std::get<0>(pet_coords)) - double(std::get<0>(current_coords))), 2) +
                             std::pow((double(std::get<1>(pet_coords)) - double(std::get<1>(current_coords))), 2)),
                            0.5);
            // if the two animals are close enough (distance lower than the radius of collision) there is a collision
            if (dist <= r) {
                p->onCollision();
            }
        }
    }
}


// ############################## for tests ########################################
void Environment::setLife(int i) {
    // Set life to all pets at i
    // It is only used for nominal test purpose
    cout << "[TEST] Setting life of all pets at " << i << "." << endl;
    for (std::vector<Animal *>::iterator it = animals.begin(); it != animals.end(); ++it) {
        (*it)->setLife(i);
    }
}
