#include "Aquarium.h"
#include "Environment.h"
#include "Statistics.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay ){
   int screenWidth = 1280; //screen_width();
   int screenHeight = 1024; //screen_height();

   cout << "const Aquarium" << endl;

   vector<string> names;
   Statistics* stats = new Statistics(names);

   water = new Environment( width, height, petcreator, stats );
   assign( *water, "Simulation d'écosystème" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );
}

Aquarium::~Aquarium( void ){
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
