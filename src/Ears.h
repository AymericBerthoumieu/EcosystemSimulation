//
// Created by Rafinesque on 19/03/2021.
//

#ifndef _EARS_H_
#define _EARS_H_
#include "Sensor.h"
/*
 * Ears is a concrete decorator that gives the capacity of decorated object to detect object in the environment
 */
class Ears: public Sensor {
    static string NAME;
public:
    Ears(Animal& animal); // Constructor that decorate the object in parameter
    ~Ears();
};

#endif
