#include "Pet.h"
#include "Animal.h"



Pet::Pet(): Animal(){};
Pet::Pet(const Pet& p): Animal(p){};
Pet::~Pet() {};
