#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include "UImg.h"

#include <iostream>
#include <tuple>

using namespace std;

class Environment;
class BehaviourStrategy;


class Animal{
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
   Animal();
   Animal(const Animal& p); // copy cstor
   virtual  ~Animal();

   void action(Environment& myEnvironment);
   void draw(UImg& support);
   bool isDetecting(const Animal& p) const;
   void initCoords(int xLim, int yLim);
   friend bool operator==(const Animal& p1, const Animal& p2);
   std::tuple<int, int> getCoordinates();
   std::tuple<double, double> getCumul();
   std::tuple<double, double> getOrientationSpeed();
   double getMaxSpeed();
   int getIdentity();
   void setCoordinates(int new_x,int new_y);
   void setCumul(double new_cumul_x,double new_cumul_y);
   void setOrientationSpeed(double new_orientation,double new_speed);
   void changeBehaviour();
   std::string getBehaviourName() const;
   bool isMultipleBehaviour() const;
};

#endif
