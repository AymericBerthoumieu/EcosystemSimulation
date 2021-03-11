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
   int life;
   double probabilityOfFatalCollision;

   T* color;


   void move(int xLim, int yLim);

public :
   Pet();
   Pet(const Pet& p); // copy cstor
   Pet( Pet && p ); // move
   ~Pet();

   Pet& operator=(Pet&& p) noexcept; //move constructor by assignment
   Pet& operator=(const Pet& p); // assignment
   void action(Environment& myEnvironment);
   void draw(UImg& support);
   bool isDetecting(const Pet& p) const;
   void initCoords(int xLim, int yLim);
   void decrement();
   void onCollision();
   int getX() {return x;};
   int getY() {return y;};
   int getIdentity() const {return identity;};
   int getLife() const {return life;};
   double getProbabilityOfFatalCollision() const {return probabilityOfFatalCollision;};
   friend bool operator==(const Pet& p1, const Pet& p2);
};

#endif
