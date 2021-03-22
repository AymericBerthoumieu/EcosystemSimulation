//
// Created by Rafinesque on 19/03/2021.
//

#ifndef _EARS_H_
#define _EARS_H_
#include "Sensor.h"

class Ears: public Sensor {
protected:

public:
    void move(int xLim,int yLim, Environment &myEnvironment) override{return wrapAnimal->move(xLim,yLim, myEnvironment);};
    Ears(Animal* animal);
    bool isDetecting(const Animal& animal) const override;
    std::string getName() override;
    ~Ears();
};

#endif
