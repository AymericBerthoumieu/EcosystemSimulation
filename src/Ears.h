//
// Created by Rafinesque on 19/03/2021.
//

#ifndef _EARS_H_
#define _EARS_H_
#include "Sensor.h"



class Ears: public Sensor {
public:
    Ears(Animal& animal);
    bool isDetecting(const Animal& animal);
};


#endif //CPP_ECOSYSTEM_PROJECT_EARS_H
