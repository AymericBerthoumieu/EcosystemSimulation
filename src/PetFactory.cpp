#include "PetFactory.h"
#include "Pet.h"

#include "FearfulBehaviour.h"
#include "GregariousBehaviour.h"
#include "KamikazeBehaviour.h"

#include "Fin.h"
#include "Eyes.h"

#include <iterator>
#include <random>

using namespace std;



PetFactory::PetFactory(int xLim, int yLim, map<string, float> behavioursDistribution, unordered_set<string> availableAccessoriesAndCaptors, Statistics& stats):
  XLIM(xLim), YLIM(yLim),
  statistics(stats),
  behavioursDistribution(behavioursDistribution), 
  availableAccessoriesAndCaptors(availableAccessoriesAndCaptors)
   {}

string choose_unchosen_element(const unordered_set<string> remaining_elements) {
    string chosen_one;

    // randomly choosing an index in remaining_elements
    default_random_engine random_generator;
    uniform_int_distribution<int> distribution(0, remaining_elements.size()-1);
    int index = distribution(random_generator);
    
    auto it = remaining_elements.begin();
    for (int _i=0; _i<index; _i++){
        it++;
    }
    chosen_one = *it;

    return  chosen_one;
}

unordered_set<string> choose_elements(const unordered_set<string> available_elements) {
    unordered_set<string> chosen_elements;
    unordered_set<string> remaining_elements;
    remaining_elements = available_elements;

    // randomly choosing a number of elements to choose
    // this number is bound by the number of elements in available_elements
    default_random_engine random_generator;
    uniform_int_distribution<int> distribution(0,available_elements.size());
    int nb_to_choose = distribution(random_generator);

    for (int i=0; i<nb_to_choose; i++){
        string chosen_elem;
        chosen_elem = choose_unchosen_element(remaining_elements);
        chosen_elements.insert(chosen_elem);
        remaining_elements.erase(chosen_elem);
    };
    return chosen_elements;
}

Animal* PetFactory::createMember(string behaviour) {
    Animal* pet = new Pet(); 

    // choosing and adding captors and accessories to the returned pet
    unordered_set<string> captorsAndAccessories = choose_elements(this->availableAccessoriesAndCaptors);
    for (string e : captorsAndAccessories) {
        if (e == "a_fin") {
            pet = new Fin(*pet);
        }
        else{
            if (e == "c_eyes") {
                pet = new Eyes(*pet);
            }
        }
    }

    // adding the requested behaviour the returned pet
    if (behaviour == "b_multiple"){
        pet->setBehaviourAsMultiple();
    }
    else{
        if (behaviour != "none"){
            pet->setBehaviour(behaviour);
        }
    }

    // updating stats
    this->statistics.modifyData(behaviour, true);
    for (string e : captorsAndAccessories) {
        this->statistics.modifyData(e, true);
    }

    pet->initCoords(this->XLIM, this->YLIM);

    return pet;
}

vector<Animal*> PetFactory::initializePopulation(int number){
    vector<Animal*> createdPets;
    map<string, int> toCreate;
    int createdNumber = 0;

    // computing the number of pets to create per behaviour
    for (const auto &dist : this->behavioursDistribution) {
        toCreate.insert(pair<string, int>(dist.first, static_cast<int>(dist.second*number/100.)));
    }

    // creating the pets with their behaviour and possibly some accessories and captors
    for (const auto &nbPetsPerBehaviourPair : toCreate) {
        createdNumber = createdNumber + static_cast<int>(nbPetsPerBehaviourPair.second);
        for (int _i=0; _i<nbPetsPerBehaviourPair.second; _i++) {
            cout << "                                      " << nbPetsPerBehaviourPair.first << endl;
            createdPets.push_back(this->createMember(nbPetsPerBehaviourPair.first));
        }
    // in case the rounding, while casting to int, results in a lower number of created pets than requested
    }
    for (int _i=0; _i < number-createdNumber; _i++) {
        const auto nbPetsPerBehaviourPair = toCreate.end();
        createdPets.push_back(this->createMember(nbPetsPerBehaviourPair->first));
    }
    return createdPets;
}

