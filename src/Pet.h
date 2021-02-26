#ifndef _PETS_H_
#define _PETS_H_

#include "UImg.h"

#include <iostream>

using namespace std;


class Environment;


class Pet{
   static const double AFF_SIZE;
   static const double MAX_SPEED;
   static const double LIMIT_VIEW;

   static int next;

   int identity;
   int x, y;
   double cumulX, cumulY;
   double orientation;
   double speed;

   T* color;


   void move(int xLim, int yLim);

public :
   Pet();
   Pet(const Pet& p); // copy cstor
   ~Pet();

   void action(Environment& myEnvironment);
   void draw(UImg& support);
   bool iSeeYou(const Pet& p) const;
   void initCoords(int xLim, int yLim);
   friend bool operator==(const Pet& p1, const Pet& p2);
};

#endif
