//
// Created by Rafinesque on 22/03/2021.
//

#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"
#include "Animal.h"
#include "Shell.h"

/*
 * Class used to test the decorator Shell
 */
int main(){
    Aquarium ecosystem(640, 480, 30);
    //Decorated Pet creation with Shell
    Shell f = Shell(new Pet());
    //Decoration of decorated object
    Shell f2 = Shell(f);
    //getName() method test
    std::cout << "Accessories name: " << f.getName() << std::endl;
    std::cout << "Set armor to 4 " << std::endl;
    f.setArmor(4.0);
    std::cout << "Get armor : " << f.getArmor() << std::endl;

    std::cout << "Accessories name: " << f2.getName() << std::endl;

    // Test of the ecosystem with Decorated Pet
    for (int i = 1; i <= 6; ++i){
        std::cout << "AddMember" << std::endl;
        ecosystem.getEnvironment().addMember(Shell(new Pet()));
    }
    ecosystem.run();

    return 0;
}
