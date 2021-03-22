#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"

#include <iostream>

using namespace std;

int main(){
   Aquarium ecosystem(640, 480, 30);

   for (int i = 1; i <= 150; ++i)
      ecosystem.getEnvironment().addMember(new Pet());
   ecosystem.run();

   return 0;}
