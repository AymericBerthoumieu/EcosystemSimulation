//
// Created by Rafinesque on 19/03/2021.
//

#ifndef _SENSOR_H_
#define _SENSOR_H_
#include "BaseDecorator.h"

class Sensor: public BaseDecorator {
protected:
    Animal* wrapAnimal;
    float capacityOfDetection;
    float minimumDistanceOfPerception;
    float maximumDistanceOfPerception;

public:
    virtual bool isDetecting(const Animal* animal) =0;
};


#endif //CPP_ECOSYSTEM_PROJECT_SENSOR_H
