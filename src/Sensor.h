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
    double capacityOfDetection; // Coefficient to use to determine if the object is detectable by the current object
    double minimumDistanceOfPerception; // Minimum distance for the object to know there is an object close to him
    double maximumDistanceOfPerception; // Maximum distance for the current object to know there is an object close to him
public:
    Sensor(Animal& a);
    double getCapacityOfDetection() const;
    void setCapacityOfDetection(double capacityOfDetection);
    double getMinimumDistanceOfPerception() const;
    void setMinimumDistanceOfPerception(double minimumDistanceOfPerception);
    double getMaximumDistanceOfPerception() const;
    void setMaximumDistanceOfPerception(double MaximumDistanceOfPerception);
};


#endif