#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include "UImg.h"
#include "Animal.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class AnimalFactory;
class Statistics;

class Environment : public UImg{
   static const T white[];
   int width, height;
   std::vector<Animal *> animals;
   int nb_steps;
   AnimalFactory& petCreator;
   Statistics& statistics;

public :
   Environment(int _width, int _height, int nbAnimalsToStartWith, AnimalFactory& factory, Statistics& stats);
   ~Environment();

   int getWidth() const;
   int getHeight() const;
   void step();

   void hasCollision(Animal* a);
   void die();
   void addMember(Animal * a);
   std::vector<Animal *> detectedNeighbors(Animal* a);

   // for test
   void setLife(int i);
};


#endif
