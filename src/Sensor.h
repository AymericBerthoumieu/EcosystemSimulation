//
// Created by Rafinesque on 19/03/2021.
//

#ifndef _SENSOR_H_
#define _SENSOR_H_
#include "BaseDecorator.h"

/*
 * Ears and Eyes are going to heritate from this class there common inherit and method
 */
class Sensor: public BaseDecorator {
protected:
    float capacityOfDetection; // Coefficient to use to determine if the object is detectable by the current object
    float minimumDistanceOfPerception; // Minimum distance for the object to know there is an object close to him
    float maximumDistanceOfPerception; // Maximum distance for the current object to know there is an object close to him
};


#endif