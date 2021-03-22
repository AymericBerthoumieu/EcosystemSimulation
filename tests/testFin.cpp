//
// Created by Rafinesque on 12/03/2021.
//
#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"
#include "Animal.h"
#include "Fin.h"

/*
 * Class used to test the decorator Fin
 */
int main(){
    Aquarium ecosystem(640, 480, 30);
    //Decorated Pet creation with Fin
    Fin f = Fin(new Pet());
    //Decoration of decorated object
    Fin f2 = Fin(f);
    //getName() method test
    std::cout << "Accessories name: " << f.getName() << std::endl;
    std::cout << "Accessories name: " << f2.getName() << std::endl;

    // Test of the ecosystem with Decorated Pet
    for (int i = 1; i <= 6; ++i){
        std::cout << "AddMember" << std::endl;
        ecosystem.getEnvironment().addMember(Fin(new Pet()));
    }
    ecosystem.run();

    return 0;
}
