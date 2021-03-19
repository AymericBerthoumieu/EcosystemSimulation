#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_


#include "UImg.h"
#include "Animal.h"
#include "PetFactory.h"
#include "Statistics.h"
#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Environment : public UImg{
   static const T white[];
   int width, height;
   std::vector<Animal> animals;
   int nb_steps;
   std::vector<float> natalityRatios;
   float cloningProbability;
   AnimalFactory& petCreator;
   Statistics& statistics;

public :
   Environment(int _width, int _height, int nbAnimalsToStartWith, AnimalFactory& factory, Statistics& stats);
   ~Environment();

   int getWidth() const;
   int getHeight() const;
   void step();
   void hasCollision(Animal& a);
   void die();
   bool mustDie(const Animal& a);
   void addMember(const Animal& a);
   void addMembersAtRuntime();
   void chooseMembersToClone();
   void addMemberToclone(Animal* a);
   void cloneMembers();
   int nbNeighbors(const Animal& a);
   std::vector<Animal> detectedNeighbors(Animal& a);
};


#endif
