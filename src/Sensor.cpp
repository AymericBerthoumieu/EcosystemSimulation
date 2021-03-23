//
// Created by Rafinesque on 20/03/2021.
//

#include "Sensor.h"

Sensor::Sensor(Animal& a): BaseDecorator(a) {
    capacityOfDetection = (float)rand() / (float)RAND_MAX ;
    minimumDistanceOfPerception = 0;
    maximumDistanceOfPerception = (float)rand() / (float)RAND_MAX * LIMIT_VIEW;
}

float Sensor::getCapacityOfDetection() const {
    return capacityOfDetection;
}

float Sensor::getMaximumDistanceOfPerception() const {
    return maximumDistanceOfPerception;
}

float Sensor::getMinimumDistanceOfPerception() const {
    return minimumDistanceOfPerception;
}

void Sensor::setCapacityOfDetection(float capacityOfDetection) {
    this->capacityOfDetection = capacityOfDetection;
}

void Sensor::setMaximumDistanceOfPerception(float maximumDistanceOfPerception) {
    this->maximumDistanceOfPerception = maximumDistanceOfPerception;
}

void Sensor::setMinimumDistanceOfPerception(float minimumDistanceOfPerception) {
    this->maximumDistanceOfPerception = minimumDistanceOfPerception;
}
