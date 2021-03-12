#ifndef _PETS_H_
#define _PETS_H_

#include "UImg.h"

#include <iostream>
#include <tuple>

using namespace std;


class BehaviourStrategy;
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
   bool isMultiple;

   T* color;
   BehaviourStrategy* behaviour;


   void move(int xLim, int yLim, Environment& myEnvironment);

public :
   Pet();
   Pet(const Pet& p); // copy cstor
   ~Pet();

   void action(Environment& myEnvironment);
   void draw(UImg& support);
   bool isDetecting(const Pet& p) const;
   void initCoords(int xLim, int yLim);
   friend bool operator==(const Pet& p1, const Pet& p2);
   std::tuple<int, int> getCoordinates();
   std::tuple<double, double> getCumul();
   std::tuple<double, double> getOrientationSpeed();
   double getMaxSpeed();
   int getId();
   void setCoordinates(int new_x,int new_y);
   void setCumul(double new_cumul_x,double new_cumul_y);
   void setOrientationSpeed(double new_orientation,double new_speed);
   void changeBehaviour();
};

#endif
