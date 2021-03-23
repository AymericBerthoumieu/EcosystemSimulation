#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

#include <iostream>
#include <CImg.h>
#include <map>

using namespace std;
using namespace cimg_library;


class Environment;


class Aquarium : public CImgDisplay{
    Environment *water;
    int delay;

public :
    Aquarium(int width, int height, int _delay, int startingNbOfAnimals, map<string, float> animalsDistribution);
    ~Aquarium(void);

    Environment& getEnvironment(void) {return *water;}

    void run(void);
};


#endif
