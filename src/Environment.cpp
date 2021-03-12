#include "Environment.h"

#include <cstdlib>
#include <ctime>
#include <math.h>
#include <memory>


const T Environment::white[] = {(T) 255, (T) 255, (T) 255};

Environment::Environment(int _width, int _height) : UImg(_width, _height, 1, 3), width(_width), height(_height),
                                                    nb_steps(0) {
    cout << "const Environment" << endl;
    std::srand(time(NULL));
}

Environment::~Environment() {
    cout << "dest Environment" << endl;
}

void Environment::step() {
    ++nb_steps;
    cimg_forXY(*this, x, y)
    fillC(x, y, 0, white[0], white[1], white[2]);

    for (std::vector<Pet>::iterator it = pets.begin(); it != pets.end(); ++it) {
        hasCollision(*it); // check if there is a collision
        it->action(*this);

        // we draw only if the pet is still alive
        if (it->getLife() > 0) {
            it->draw(*this);
        }
    }
    this->die();
}

int Environment::nbNeighbors(const Pet &p) {
    int nb = 0;
    //for (std::vector<Pet>::iterator it = pets.begin() ; it != pets.end() ; ++it)
    //   if (!(p == *it) && p.iSeeYou(*it))
    //      ++nb;
    return nb;
}

bool mustDie(Pet const &p) {
    if (p.getLife() <= 0) {
        cout << " Pets (" << p.getIdentity() << ") is gonna be destructed with life = " << p.getLife() << endl;
    }
    return p.getLife() <= 0;
}

void Environment::die() {
    cout << "At step <" << nb_steps << "> : " << endl;
    auto it = std::remove_if(pets.begin(), pets.end(), mustDie);
    pets.erase(it, pets.end());
}

void Environment::hasCollision(Pet &p) {
    int id = p.getIdentity();
    double r = 15; // collision radius
    std::tuple<int, int> pet_coords = p.getCoordinates();
    std::tuple<int, int> current_coords;
    double dist;

    for (std::vector<Pet>::iterator it = pets.begin(); it != pets.end(); ++it) {
        if (it->getIdentity() != id) {
            current_coords = it->getCoordinates();

            dist = std::pow((std::pow((double(std::get<0>(pet_coords)) - double(std::get<0>(current_coords))), 2) +
                             std::pow((double(std::get<1>(pet_coords)) - double(std::get<1>(current_coords))), 2)), 0.5);
            if (dist <= r) {
                cout << "Collision of " << p.getIdentity() << endl;
                p.onCollision();
            }
        }
    }
}

// ############################## for tests ########################################

void Environment::setLife(int i){
    cout << "[TEST] Setting life of all pets at " << i << "." << endl;
    for (std::vector<Pet>::iterator it = pets.begin(); it != pets.end(); ++it) {
        it->setLife(i);
    }
}