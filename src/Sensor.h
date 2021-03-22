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
    virtual void move(int xLim, int yLim, Environment &myEnvironment) = 0;
    virtual std::string getName() = 0;
    //virtual bool isDetecting(const Animal& animal) const = 0;
    virtual ~Sensor() {};
};


#endif