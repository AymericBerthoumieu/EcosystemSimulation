#include "Aquarium.h"
#include "Environment.h"
#include "Statistics.h"
#include "PetFactory.h"
#include "Fin.h"
#include "Eyes.h"


Aquarium::Aquarium( int width, int height, int _delay, int startingNbOfAnimals, map<string, float> animalsDistribution) : CImgDisplay(), delay( _delay ){
   int screenWidth = 1280; //screen_width();
   int screenHeight = 1024; //screen_height();

   cout << "const Aquarium" << endl;

   Statistics* statistics = new Statistics({Fin::getName(), Eyes::getName()});

   AnimalFactory* factory = new PetFactory(width, height, animalsDistribution,  {Fin::getName(), Eyes::getName()}, *statistics);

   water = new Environment(width, height, startingNbOfAnimals, *factory, *statistics);
   assign( *water, "Simulation d'écosystème" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );
}

Aquarium::~Aquarium(){
    delete water;
    cout << "dest Aquarium" << endl;}

void Aquarium::run(){
   cout << "running Aquarium" << endl;
   while (! is_closed()){
      // cout << "iteration de la simulation" << endl;
      if ( is_key() ) {
         cout << "Vous avez pressé la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();}

      water->step();
      display( *water );

      wait( delay );}
}
