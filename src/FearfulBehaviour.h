#ifndef FEARFUL_BEHAVIOUR_H
# define FEARFUL_BEHAVIOUR_H

#include <string>
#include <UImg.h>

#include "BehaviourStrategy.h" 

using namespace std;


class FearfulBehaviour: public BehaviourStrategy {
        static const T color[3] ;
    public:
        static const T* getColor();
        static string getBehaviourName() {return "fearful";};

        ~FearfulBehaviour();
};

#endif
