#ifndef GREGARIOUS_BEHAVIOUR_H
#define GREGARIOUS_BEHAVIOUR_H

#include <string>
#include <UImg.h>

#include "BehaviourStrategy.h"

using namespace std;


class GregariousBehaviour: public BehaviourStrategy {

    static const T color[3];

public:
    static string getBehaviourName(){return "gregarious";};
    static const T* getColor() ;

    ~GregariousBehaviour();
};

#endif
