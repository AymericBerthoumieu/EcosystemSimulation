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
    //Decorated Pet creation with Shell
    Pet p = Pet();
    Shell f = Shell(p);
    //Decoration of decorated object
    Shell f2 = Shell(f);
    //getName() method test
    std::cout << "Accessories name: " << f.getName() << std::endl;
    std::cout << "Get armor : " << f.getArmor() << std::endl;
    std::cout << "Set armor to 4 " << std::endl;
    f.setArmor(4.0);
    std::cout << "Get armor : " << f.getArmor() << std::endl;

    std::cout << "Accessories name: " << f2.getName() << std::endl;

    return 0;
}
