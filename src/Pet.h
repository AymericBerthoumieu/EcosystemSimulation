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
   std::tuple<int, int> get_coordinates();
   std::tuple<double, double> get_cumul();
   std::tuple<double, double> get_orient_speed();
   int get_id();
   void set_coordinates(int new_x,int new_y);
   void set_cumul(double new_cumul_x,double new_cumul_y);
   void set_orient_speed(double new_orientation,double new_speed);
   void changeBehaviour();
};

#endif
