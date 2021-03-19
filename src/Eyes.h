#include "Animal.h"

class Eyes: public Animal {
public:
    Eyes(Animal& a);
    static const string getName() {return "name";};
};
