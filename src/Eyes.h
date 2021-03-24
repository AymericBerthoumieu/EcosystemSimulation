#include "Sensor.h"

class Eyes: public Sensor {
    static string NAME;
public:
    Eyes(Animal& a);
    vector<string> getAccessoriesAndCaptors();
};

