#include "Animal.h"

class Fin : public Animal{
public:
    Fin(Animal& a);
    static const string getName() {return "name";};
};
