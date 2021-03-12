#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_


#include "UImg.h"
#include "Pet.h"

#include <iostream>
#include <vector>

using namespace std;


class Environment : public UImg{
   static const T white[];
   int width, height;
   std::vector<Pet> pets;

public :
   Environment(int _width, int _height);
   ~Environment();

   int getWidth() const { return width; };
   int getHeight() const { return height; };
   void step();
   void addMember(const Pet & p) { pets.push_back(p); pets.back().initCoords(width, height); };
   int nbNeighbors(const Pet & p);
   std::vector<Pet> detectedNeighbors(Pet & pet);};


#endif
