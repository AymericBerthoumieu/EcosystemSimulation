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
    Ears f2 = Ears(f);
    //getName() method test
    std::cout << "Decorator Type : " << e.getName() << std::endl;

    // Test of the ecosystem with Decorated Pet
    for (int i = 1; i <= 6; ++i){
        std::cout << "AddMember" << std::endl;
        ecosystem.getEnvironment().addMember(Ears(new Pet()));
    }

    ecosystem.run();

    return 0;
}