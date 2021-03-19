//
// Created by Rafinesque on 12/03/2021.
//
#include "Aquarium.h"
#include "Environment.h"
#include "Pet.h"
#include "Animal.h"
#include "Fin.h"

int main(){
    Aquarium ecosystem(640, 480, 30);

    Fin f = Fin(new Pet());
    Fin f2 = Fin(f);
    std::cout << "Accessories name: " << f.getName() << std::endl;
    std::cout << "Accessories name: " << f2.getName() << std::endl;
    ecosystem.getEnvironment().addMember(f);
    ecosystem.getEnvironment().addMember(f2);
    ecosystem.run();
    return 0;
}
