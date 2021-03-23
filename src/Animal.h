#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include "UImg.h"

#include <iostream>

#include <vector>
#include <tuple>

using namespace std;


class BehaviourStrategy;
class Environment;

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



   void changeBehaviour();
   void setColor(const T* c);
public :
    virtual void move(int xLim, int yLim, double speed, Environment &myEnvironment);
   Animal();
   Animal(const Animal& a); // copy cstor
   Animal(Animal&& a); // move cstor
   virtual ~Animal();

   friend bool operator==(const Animal& a1, const Animal& a2);
   Animal& operator=(Animal&& a) noexcept; // move cstor by assignment
   Animal& operator=(const Animal& a) noexcept; // assignment

   void initCoords(int xLim, int yLim);
   std::tuple<int, int> getCoordinates() const;
   void setCoordinates(int new_x, int new_y);
   tuple<double, double> getCumul();
   void setCumul(double new_cumul_x, double new_cumul_y);
   tuple<double, double> getOrientationSpeed();
   void setOrientationSpeed(double new_orientation, double new_speed);
   float getVisibility() const;
   double getMaxSpeed();
   vector<string> getAccessoriesAndCaptors();

   int getIdentity() const;
   int getLife() const;
   double getProbabilityOfFatalCollision() const;

   void decrement();
   virtual void onCollision();
   void action(Environment& myEnvironment);
   void draw(UImg& support);
   virtual bool isDetecting(const Animal& a) const;
   std::string getBehaviourName();
   bool getIsMultiple();
   void setBehaviour(string behaviourName);
   void setBehaviourAsMultiple();

   double getSpeed();


   // for tests
   void setLife(int i);
};

#endif
