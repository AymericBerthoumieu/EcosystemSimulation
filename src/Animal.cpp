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


Animal::Animal() {
   identity = ++next;

   cout << "const Animal (" << identity << ") par défaut" << endl;
   x = y = 0;
   cumulX = cumulY = 0.;

   probabilityOfFatalCollision = ((double) rand() / (RAND_MAX));
   life = 10000 * ((double) rand() / (RAND_MAX));; // must be initialized randomly

   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   speed = static_cast<double>( rand() )/RAND_MAX*MAX_SPEED;

   color = new T[ 3 ];
   behaviour = FearfulBehaviour::getBehaviourInstance();
   isMultiple = false;
}

Animal::Animal( const Animal& a ){
   identity = ++next;

   cout << "const Animal (" << identity << ") par copie" << endl;

   probabilityOfFatalCollision = ((double) rand() / (RAND_MAX));
   life = 10000 * ((double) rand() / (RAND_MAX));; // must be initialized randomly

   x = a.x;
   y = a.y;
   cumulX = cumulY = 0.;
   orientation = a.orientation;
   speed = a.speed;

  isMultiple = a.isMultiple;
  behaviour = a.behaviour;


  color = new T[ 3 ];
  memcpy( color, a.color, 3*sizeof(T) );}


Animal::~Animal(){
    if (color != NULL){
        delete[] color;
    }
    cout << "dest Pet" << endl;
}


Animal& Animal::operator=(Animal&& p) noexcept
{
    // Guard self assignment
    if (this == &p)
        return *this; // delete[]/size=0 would also be ok
    cout << "Affectation Pet(" << p.getIdentity() << ")" << endl;
    identity = p.getIdentity();

    probabilityOfFatalCollision = p.getProbabilityOfFatalCollision();
    life = p.getLife(); // must be initialized randomly

    x = p.x;
    y = p.y;
    behaviour = p.behaviour;
    isMultiple = p.isMultiple;
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
    probabilityOfFatalCollision = p.getProbabilityOfFatalCollision();
    life = p.getLife(); // must be initialized randomly

    x = p.x;
    y = p.y;
    behaviour = p.behaviour;
    isMultiple = p.isMultiple;
    cumulX = cumulY = 0.;
    orientation = p.orientation;
    speed = p.speed;
    memcpy( color, p.color, 3*sizeof(T) );
    return *this;
}


void Animal::initCoords( int xLim, int yLim ){
   x = rand() % xLim;
   y = rand() % yLim;}


void Animal::move( int xLim, int yLim, Environment& myEnvironment){
   behaviour->move(xLim,yLim,this, myEnvironment);}


void Animal::action( Environment & myEnvironment ){
    this->decrement();
    if (life > 0) {
      changeBehaviour();
      move( myEnvironment.getWidth(), myEnvironment.getHeight(), myEnvironment);
    }
}


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


void Animal::decrement() {
    // decrement the life of the animal
    --life;
}


void Animal::onCollision(){
    double proba = ((double) rand() / (RAND_MAX));
    if (proba < this->getProbabilityOfFatalCollision()) {
        cout << this->getIdentity() << " dies by collision" << endl;
        life = 0;
    }
}

double Animal::getSpeed(){
    return speed;
}

int Animal::getLife() const {
    return life;
}


int Animal::getIdentity() const {
   return this->identity;
}


double Animal::getProbabilityOfFatalCollision() const {
    return probabilityOfFatalCollision;
}


std::tuple<int, int> Animal::getCoordinates(){
    return std::make_tuple(this->x,this->y);
}

void Animal::setCoordinates(int new_x,int new_y){
   this->x = new_x;
   this->y = new_y;
}


std::tuple<double, double> Animal::getCumul(){
   return std::make_tuple(this->cumulX,this->cumulY);
}
   
void Animal::setCumul(double new_cumul_x,double new_cumul_y){
   this->cumulX = new_cumul_x;
   this->cumulY = new_cumul_y;
}


std::tuple<double, double> Animal::getOrientationSpeed(){
   return std::make_tuple(this->orientation,this->getSpeed());
}

void Animal::setOrientationSpeed(double new_orientation,double new_speed){
   this->orientation = new_orientation;
   this->speed = new_speed;
   }
vector<string> Animal::getAccessoriesAndCaptors(){
    vector<string> names;
    return names;
}

BehaviourStrategy* choose_behaviour() {
  BehaviourStrategy* behaviour;
  int which_behaviour;
  which_behaviour = rand() % 3 + 1;

  if ( which_behaviour == 1 ){
    behaviour = GregariousBehaviour::getBehaviourInstance();
  }
  if ( which_behaviour == 2 ){
    behaviour = FearfulBehaviour::getBehaviourInstance();
  }
  if ( which_behaviour == 3 ){
    behaviour = KamikazeBehaviour::getBehaviourInstance();
  }
  return behaviour;
}


void Animal::setBehaviourAsMultiple(){
    T c[3] = {0, 0, 0};
    this->setColor(c);
    this->isMultiple = true;
    this->behaviour = choose_behaviour();
}


// Method to randomly change the behaviour of an animal with multiple behaviour
void Animal::changeBehaviour(){
  double proba_to_change = ((double) rand() / (RAND_MAX));

  if (isMultiple && proba_to_change >= 0.9) {
      this->behaviour = choose_behaviour();
    }
}


void Animal::setColor(const T c[3]) {
    this->color[0] = c[0];
    this->color[1] = c[1];
    this->color[2] = c[2];
}


void Animal::setBehaviour(string behaviourName) {
    if (behaviourName == GregariousBehaviour::getBehaviourInstance()->getBehaviourName()) {
        this->setColor(GregariousBehaviour::getColor());
        this->behaviour = GregariousBehaviour::getBehaviourInstance();
        }
     else {
         if (behaviourName == FearfulBehaviour::getBehaviourInstance()->getBehaviourName()) {
            this->setColor(FearfulBehaviour::getColor());
            this->behaviour = FearfulBehaviour::getBehaviourInstance();
         }
          else {
             if (behaviourName == KamikazeBehaviour::getBehaviourInstance()->getBehaviourName()) {
                this->setColor(KamikazeBehaviour::getColor());
                this->behaviour = KamikazeBehaviour::getBehaviourInstance();
             }
          }
     }
}


double Animal::getMaxSpeed(){
   return MAX_SPEED;
}


bool Animal::getIsMultiple(){
  return isMultiple;
}


std::string Animal::getBehaviourName(){
  return behaviour->getBehaviourName();
}


// ############################## for tests ########################################
void Animal::setLife(int i){
    life = i;
}
