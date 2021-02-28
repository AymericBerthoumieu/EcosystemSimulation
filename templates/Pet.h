#ifndef _PETS_H_
#define _PETS_H_ /******* putting 2 blank lines after ifndef,define  *******/


#include "UImg.h" // ********* grouping includes of project's header files **********
#include "SomeStuff.h"
#include "SommeOtherStuff.h"

#include <iostream> // ********* grouping includes of external libraries **********
#include <somelib>
#include <someotherlib>

using namespace std;


class Pet{ // ********** putting 2 blanklines before a class definition *************
   static const double AFF_SIZE;
   static const double MAX_SPEED;
   static const double LIMIT_VIEWi; // ********** grouping constants, then putting a blank line ************

   static int next;

   int identity;

   int x, y;  // **************** grouping related attributes/variables ***************
   double cumulX, cumulY;
   double orientation;
   double speed;

   T* color;


   void move(int xLim, int yLim); // ************ putting 2 blank lines before method definition ************


public : // ******** putting 2 blank lines before new visibility ********
   Pet();
   Pet(const Pet& p); // ************ grouping constrictors and destructors, then putting a blank line
   ~Pet();

   void action(Environment& myEnvironment);
   void draw(UImg& support);
   bool iSeeYou(const Pet& p) const;
   void initCoords(int xLim, int yLim);
   friend bool operator==(const Pet& p1, const Pet& p2);};


#endif
