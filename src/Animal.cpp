#include "Animal.h"

#include "Environment.h"
#include "GregariousBehaviour.h"
#include "FearfulBehaviour.h"
#include "KamikazeBehaviour.h"


#include <cstdlib>
#include <cmath>


const double Animal::AFF_SIZE = 8.;
const double Animal::MAX_SPEED = 10.;
const double Animal::LIMIT_VIEW = 30.;

int Animal::next = 0;


Animal::Animal() {
   identity = ++next;

   cout << "const Animal (" << identity << ") par défaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;

   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   speed = static_cast<double>( rand() )/RAND_MAX*MAX_SPEED;

   color = new T[ 3 ];
//   color[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
//   color[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
//   color[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}

Animal::Animal( const Animal & a ){
   identity = ++next;

   cout << "const Animal (" << identity << ") par copie" << endl;

   x = a.x;
   y = a.y;
   cumulX = cumulY = 0.;
   orientation = a.orientation;
   speed = a.speed;
   color = new T[ 3 ];
   memcpy( color, a.color, 3*sizeof(T) );}

Animal::Animal(Animal&& a){
    cout << "MOVE const Animal (" << identity << ")" << endl;
    x = a.x;
    y = a.y;
    cumulX = cumulY = 0.;
    orientation = a.orientation;
    speed = a.speed;
    color = a.color;
    a.color = NULL;
}

Animal& Animal::operator=(Animal&& p) noexcept
{
    // Guard self assignment
    if (this == &p)
        return *this; // delete[]/size=0 would also be ok
    cout << "Affectation Pet(" << p.getIdentity() << ")" << endl;
    identity = p.getIdentity();

//    probabilityOfFatalCollision = p.getProbabilityOfFatalCollision();
//    life = p.getLife(); // must be initialized randomly

    x = p.x;
    y = p.y;
    cumulX = cumulY = 0.;
    orientation = p.orientation;
    speed = p.speed;
    color = p.color;
    p.color = NULL;
    return *this;
}

// copy assignment
Animal& Animal::operator=(const Animal& p) noexcept
{
    cout << "Affectation par copie" << endl;
    // Guard self assignment
    if (this == &p)
        return *this;

    identity = p.getIdentity();
//    probabilityOfFatalCollision = p.getProbabilityOfFatalCollision();
//    life = p.getLife(); // must be initialized randomly

    x = p.x;
    y = p.y;
    cumulX = cumulY = 0.;
    orientation = p.orientation;
    speed = p.speed;
    memcpy( color, p.color, 3*sizeof(T) );
    return *this;
}


Animal::~Animal( void ){
   delete[] color;

   cout << "dest Animal" << endl;}


void Animal::initCoords( int xLim, int yLim ){
   x = rand() % xLim;
   y = rand() % yLim;}


void Animal::move( int xLim, int yLim ){
   double nx, ny;
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
      cumulY += ny - y;}}


void Animal::action( Environment & myEnvironment ){
   move( myEnvironment.getWidth(), myEnvironment.getHeight() );}


void Animal::draw( UImg & support ){
   double xt = x + cos( orientation )*AFF_SIZE/2.1;
   double yt = y - sin( orientation )*AFF_SIZE/2.1;

   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., color );
   support.draw_circle( xt, yt, AFF_SIZE/2., color );}


bool operator==( const Animal & b1, const Animal & b2 ){
   return ( b1.identity == b2.identity );}


bool Animal::isDetecting( const Animal & a ) const{
   double         dist;

   dist = std::sqrt( (x-a.x)*(x-a.x) + (y-a.y)*(y-a.y) );
   return ( dist <= LIMIT_VIEW );}


void Animal::setBehaviourAsMultiple(){
    T c[3] = {0, 0, 0};
    this->setColor(c);
    this->isMultiple = true;
}


void Animal::setColor(const T c[3]) {
    this->color[0] = c[0];
    this->color[1] = c[1];
    this->color[2] = c[2];
}


void Animal::setBehaviour(string behaviourName) {
    if (behaviourName == GregariousBehaviour::getBehaviourName()) {
        this->setColor(GregariousBehaviour::getColor());
        }
     else {
         if (behaviourName == FearfulBehaviour::getBehaviourName()) {
            this->setColor(FearfulBehaviour::getColor());
         }
          else {
             if (behaviourName == KamikazeBehaviour::getBehaviourName()) {
                this->setColor(KamikazeBehaviour::getColor());
             }
          }
     }
     
    // TODO set behaviour
}

int Animal::getIdentity() const {
    return identity;
}
