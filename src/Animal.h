#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include "UImg.h"

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Environment;
class BehaviourStrategy;

class Animal{
protected:
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
   bool isMultiple; // for multiple behaviour type
   float visibility;

   BehaviourStrategy* behaviour; 

   T* color;


   void move(int xLim, int yLim);
   void changeBehaviour();
   void setColor(const T* c);

public :
   Animal();
   Animal(const Animal& a); // copy cstor
   Animal(Animal&& a); // move cstor
   virtual ~Animal();

   friend bool operator==(const Animal& a1, const Animal& a2);
   Animal& operator=(Animal&& a) noexcept; // move cstor by assignment
   Animal& operator=(const Animal& a) noexcept; // assignment

   void initCoords(int xLim, int yLim);
   std::tuple<int, int> getCoordinates();
   void setCoordinates(int new_x, int new_y);
   tuple<double, double> getCumul();
   void setCumul(double new_cumul_x, double new_cumul_y);
   tuple<double, double> getOrientationSpeed();
   void setOrientationSpeed(double new_orientation, double new_speed);
   float getVisibility();
   double getMaxSpeed();
   vector<string> getAccessoriesAndCaptors();

   int getIdentity() const;
   int getLife() const;
   double getProbabilityOfFatalCollision() const;

   void decrement();
   void onCollision();
   void action(Environment& myEnvironment);
   void draw(UImg& support);
   bool isDetecting(const Animal& a) const;

   void setBehaviour(string behaviourName);
   void setBehaviourAsMultiple();


};

#endif
