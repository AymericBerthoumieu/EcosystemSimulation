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

    //Decorated Pet creation with Fin
    Pet p = Pet();
    Fin f = Fin(p);
    //Decoration of decorated object
    Fin f2 = Fin(f);
    // methods test
    std::cout << "Accessories name: " << f.getName() << std::endl;
    std::cout << "Get speedCoef: " << f.getSpeedCoef() << std::endl;
    std::cout << "Set speedCoef to 1 " << std::endl;
    f.setSpeedCoef(1.0);
    std::cout << "Get speedCoef: " << f.getSpeedCoef() << std::endl;
    std::cout << "Accessories name: " << f2.getName() << std::endl;

    return 0;
}
