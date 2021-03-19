#ifndef KAMIKAZE_BEHAVIOUR_H
#define KAMIKAZE_BEHAVIOUR_H

#include <string>
#include <UImg.h>

#include "BehaviourStrategy.h"

using namespace std;

class KamikazeBehaviour: public BehaviourStrategy {
    static const T color[3];
public:
    ~KamikazeBehaviour();

    static string getBehaviourName() {return "kamik";};
    static const T* getColor() ;
};

#endif
