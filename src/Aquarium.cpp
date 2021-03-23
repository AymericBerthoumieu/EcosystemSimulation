#include "Aquarium.h"
#include "Environment.h"
#include "Statistics.h"
#include "PetFactory.h"


#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"

#include "Fin.h"
#include "Eyes.h"


Aquarium::Aquarium( int width, int height, int _delay, int startingNbOfAnimals, map<string, float> animalsDistribution) : CImgDisplay(), delay( _delay ){
   int screenWidth = 1280; //screen_width();
   int screenHeight = 1024; //screen_height();

   cout << "const Aquarium" << endl;
   string gregariousName = (GregariousBehaviour::getBehaviourInstance())->getBehaviourName();
   string fearfulName = (FearfulBehaviour::getBehaviourInstance())->getBehaviourName();
   string kamikazeName = (KamikazeBehaviour::getBehaviourInstance())->getBehaviourName();

   // TODO : fixer la liste des availableCaptorsAndAccessories
   Statistics* statistics = new Statistics({"b_multiple", gregariousName, fearfulName, kamikazeName, Fin::getName(), Eyes::getName()});

   // TODO : fixer la liste des availableCaptorsAndAccessories
   AnimalFactory* factory = new PetFactory(width, height, animalsDistribution,  {Fin::getName(), Eyes::getName()}, *statistics);

   water = new Environment(width, height, startingNbOfAnimals, *factory, *statistics);

   assign( *water, "Simulation d'écosystème" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );
}

Aquarium::~Aquarium( void ){
    KamikazeBehaviour::getRidOfInstance();
    GregariousBehaviour::getRidOfInstance();
    FearfulBehaviour::getRidOfInstance();
    delete water;
    cout << "dest Aquarium" << endl;}

void Aquarium::run( void ){
   cout << "running Aquarium" << endl;
   while ( ! is_closed() ){
      if ( is_key() ) {
         cout << "Vous avez pressé la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();}

      water->step();
      display( *water );

      wait( delay );}
}
