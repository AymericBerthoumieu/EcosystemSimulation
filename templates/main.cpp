#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include <iostream>

using namespace std;


int main(){
   Aquarium ecosystem(640, 480, 30);

   for (int i = 1; i <= 20; ++i)
      ecosystem.getEnvironment().addMember(Pet());
   ecosystem.run();

   return 0;}
