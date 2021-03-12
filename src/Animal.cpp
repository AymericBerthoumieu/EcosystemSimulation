#include "Animal.h"

#include "Environment.h"
#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"

#include <cstdlib>
#include <cmath>

#include <stdlib.h>


const double Animal::AFF_SIZE = 8.;
const double Animal::MAX_SPEED = 10.;
const double Animal::LIMIT_VIEW = 30.;

int Animal::next = 0;


Animal::Animal( void ){
   identity = ++next;

   //cout << "const Animal (" << identity << ") par défaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;

   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   speed = static_cast<double>( rand() )/RAND_MAX*MAX_SPEED;

   // initialize Animal behaviour

   int which_behaviour; 
   which_behaviour = rand() % 2 + 1;
  
      
   isMultiple = 0;
   
   if ( which_behaviour == 2 ){
      behaviour = new GregariousBehaviour();
   }

   if ( which_behaviour == 3 ){
      behaviour = new FearfulBehaviour();
   }

   if ( which_behaviour == 1 ){
      behaviour = new KamikazeBehaviour();
   }

   if ( which_behaviour == 4 ){
   behaviour = new FearfulBehaviour();
   isMultiple = 1;}

   color = new T[ 3 ];
   color[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );}


Animal::Animal( const Animal & p ){
   identity = ++next;

   //cout << "const Animal (" << identity << ") par copie" << endl;

   x = p.x;
   y = p.y;
   cumulX = cumulY = 0.;
   orientation = p.orientation;
   speed = p.speed;

  // initialize Animal behaviour

   std::string behaviour_name; 
   behaviour_name = p.getBehaviourName();
   isMultiple = p.isMultipleBehaviour();
   
   if ( behaviour_name == "Gregarious"){
      //cout << "Reach Here ? Gregarious" << endl;
      behaviour = new GregariousBehaviour();
   }

   if ( behaviour_name == "Fearful"){
      //cout << "Reach Here ? Fearful" << endl;
      behaviour = new FearfulBehaviour();
   }

   if ( behaviour_name == "Kamikaze" ){
      //cout << "Reach Here ? Kamikaze" << endl;
      behaviour = new KamikazeBehaviour();
  }
   
   
   color = new T[ 3 ];
   memcpy( color, p.color, 3*sizeof(T) );}


Animal::~Animal( void ){
   delete behaviour;
   delete[] color;

   //cout << "dest Animal" << endl;
}


void Animal::initCoords( int xLim, int yLim ){
   x = rand() % xLim;
   y = rand() % yLim;}


void Animal::move( int xLim, int yLim, Environment& myEnvironment){
   
   behaviour->move(xLim,yLim,*this, myEnvironment);}

void Animal::action( Environment & myEnvironment ){
   changeBehaviour();
   move( myEnvironment.getWidth(), myEnvironment.getHeight(), myEnvironment);}
   


void Animal::draw( UImg & support ){
   double xt = x + cos( orientation )*AFF_SIZE/2.1;
   double yt = y - sin( orientation )*AFF_SIZE/2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., color );
   support.draw_circle( xt, yt, AFF_SIZE/2., color );}


bool operator==( const Animal & b1, const Animal & b2 ){
   return ( b1.identity == b2.identity );}


bool Animal::isDetecting( const Animal & p ) const{
   double         dist;

   dist = std::sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
   return ( dist <= LIMIT_VIEW );}

std::tuple<int, int> Animal::getCoordinates(){
   return std::make_tuple(this->x,this->y);
}

std::tuple<double, double> Animal::getCumul(){
   return std::make_tuple(this->cumulX,this->cumulY);
}
   
std::tuple<double, double> Animal::getOrientationSpeed(){
   return std::make_tuple(this->orientation,this->speed);
}

int Animal::getIdentity(){
   return this->identity;
}

double Animal::getMaxSpeed(){
   return MAX_SPEED;
}

void Animal::setCoordinates(int new_x,int new_y){
   this->x = new_x;
   this->y = new_y;
}

void Animal::setCumul(double new_cumul_x,double new_cumul_y){
   this->cumulX = new_cumul_x;
   this->cumulY = new_cumul_y;
}
void Animal::setOrientationSpeed(double new_orientation,double new_speed){
   this->orientation = new_orientation;
   this->speed = new_speed;
   }
void Animal::changeBehaviour(){
   if (isMultiple) {
      cout << "Reach Here ? Change Behaviour" << endl;
      delete behaviour;
      behaviour = new FearfulBehaviour();
}
}

bool Animal::isMultipleBehaviour() const{
   return isMultiple;
}

std::string Animal::getBehaviourName() const{
   return behaviour->getBehaviourName();
}
