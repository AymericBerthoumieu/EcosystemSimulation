//
// Created by Rafinesque on 20/03/2021.
//

#include "Sensor.h"

Sensor::Sensor(Animal& a): BaseDecorator(a),
                                 capacityOfDetection((double)rand() / (double)RAND_MAX),
                                 minimumDistanceOfPerception(0.),
                                 maximumDistanceOfPerception((double)rand() / (double)RAND_MAX * LIMIT_VIEW + 1) {}

double Sensor::getCapacityOfDetection() const {
    return capacityOfDetection;
}

double Sensor::getMaximumDistanceOfPerception() const {
    return maximumDistanceOfPerception;
}

double Sensor::getMinimumDistanceOfPerception() const {
    return minimumDistanceOfPerception;
}

void Sensor::setCapacityOfDetection(double capacityOfDetection) {
    this->capacityOfDetection = capacityOfDetection;
}

void Sensor::setMaximumDistanceOfPerception(double maximumDistanceOfPerception) {
    this->maximumDistanceOfPerception = maximumDistanceOfPerception;
}

void Sensor::setMinimumDistanceOfPerception(double minimumDistanceOfPerception) {
    this->maximumDistanceOfPerception = minimumDistanceOfPerception;
}
