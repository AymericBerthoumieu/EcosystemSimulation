#include "Pet.h"

#include "Environment.h"
#include "GregariousBehaviour.h"

#include <cstdlib>
#include <cmath>


const double Pet::AFF_SIZE = 8.;
const double Pet::MAX_SPEED = 10.;
const double Pet::LIMIT_VIEW = 30.;

int Pet::next = 0;


Pet::Pet( void ){
   identity = ++next;

   cout << "const Pet (" << identity << ") par défaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;

   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   speed = static_cast<double>( rand() )/RAND_MAX*MAX_SPEED;

   // initialize pet behaviour
   behaviour = new GregariousBehaviour();
   isMultiple = 0;

   color = new T[ 3 ];
   color[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   color[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );}


Pet::Pet( const Pet & p ){
   identity = ++next;

   cout << "const Pet (" << identity << ") par copie" << endl;

   x = p.x;
   y = p.y;
   cumulX = cumulY = 0.;
   orientation = p.orientation;
   speed = p.speed;

   // initialize pet behaviour
   behaviour = new GregariousBehaviour();
   isMultiple = 0;

   color = new T[ 3 ];
   memcpy( color, p.color, 3*sizeof(T) );}


Pet::~Pet( void ){
   delete behaviour;
   delete[] color;

   cout << "dest Pet" << endl;}


void Pet::initCoords( int xLim, int yLim ){
   x = rand() % xLim;
   y = rand() % yLim;}


void Pet::move( int xLim, int yLim, Environment& myEnvironment){
   /*double nx, ny;
   double dx = cos( orientation )*speed;
   double dy = -sin( orientation )*speed;
   int cx, cy;

   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;}
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;}

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;}
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;}}*/
   behaviour->move(xLim,yLim,*this, myEnvironment);}

void Pet::action( Environment & myEnvironment ){
   move( myEnvironment.getWidth(), myEnvironment.getHeight(), myEnvironment);}
   


void Pet::draw( UImg & support ){
   double xt = x + cos( orientation )*AFF_SIZE/2.1;
   double yt = y - sin( orientation )*AFF_SIZE/2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., color );
   support.draw_circle( xt, yt, AFF_SIZE/2., color );}


bool operator==( const Pet & b1, const Pet & b2 ){
   return ( b1.identity == b2.identity );}


bool Pet::isDetecting( const Pet & p ) const{
   double         dist;

   dist = std::sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
   return ( dist <= LIMIT_VIEW );}

std::tuple<int, int> Pet::get_coordinates(){
   return std::make_tuple(this->x,this->y);
}

std::tuple<double, double> Pet::get_cumul(){
   return std::make_tuple(this->cumulX,this->cumulY);
}
   
std::tuple<double, double> Pet::get_orient_speed(){
   return std::make_tuple(this->orientation,this->speed);
}

int Pet::get_id(){
   return this->identity;
}

void Pet::set_coordinates(int new_x,int new_y){
   this->x = new_x;
   this->y = new_y;
}

void Pet::set_cumul(double new_cumul_x,double new_cumul_y){
   this->cumulX = new_cumul_x;
   this->cumulY = new_cumul_y;
}
void Pet::set_orient_speed(double new_orientation,double new_speed){
   this->orientation = new_orientation;
   this->speed = new_speed;
   }
void Pet::changeBehaviour(){
   if (isMultiple) {
      delete behaviour;
      behaviour = new GregariousBehaviour();
}
}

