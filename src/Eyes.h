#include "BaseDecorator.h"

class Eyes: public BaseDecorator {
    public:
        Eyes(Animal& a);
        static const string getName() {return "c_Eyes";};
};

