//
// Created by Rafinesque on 19/03/2021.
//

#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"
#include "Animal.h"
#include "Ears.h"

/*
 * Class used to test the decorator Ears
 */
int main(){
    Aquarium ecosystem(640, 480, 30);

    //Decorated Pet creation with Ears
    Ears e = Ears(new Pet());
    //Decoration of decorated object
    Ears f2 = Ears(e);
    //getName() method test
    std::cout << "Decorator Type : " << e.getName() << std::endl;
    std::cout << "Set capacityOfDetection to 2 " << std::endl;
    e.setCapacityOfDetection(2);
    std::cout << "Get capacityOfDetection : " << e.getCapacityOfDetection() << std::endl;
    std::cout << "Set maximumDistanceOfPerception to 3 " << std::endl;
    e.setMaximumDistanceOfPerception(3.0);
    std::cout << "Get maximumDistanceOfPerception : " << e.getMaximumDistanceOfPerception() << std::endl;
    std::cout << "Set maximumDistanceOfPerception to 1 " << std::endl;
    e.setMinimumDistanceOfPerception(1);
    std::cout << "Get minimumDistanceOfPerception : " << e.getMaximumDistanceOfPerception() << std::endl;


    // Test of the ecosystem with Decorated Pet
    for (int i = 1; i <= 6; ++i){
        std::cout << "AddMember" << std::endl;
        ecosystem.getEnvironment().addMember(Ears(new Pet()));
    }

    ecosystem.run();

    return 0;
}