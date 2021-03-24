#include "KamikazeBehaviour.h"
#include "MoveUtils.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <limits>


std::string KamikazeBehaviour::NAME = "b_Kamikaze";


std::string KamikazeBehaviour::getBehaviourName(){
   return NAME;
}


const T KamikazeBehaviour::color[3] = {230, 0, 0};

const T* KamikazeBehaviour::getColor() {
    return color;
}


KamikazeBehaviour* KamikazeBehaviour::kamikazebehaviour= nullptr;


KamikazeBehaviour* KamikazeBehaviour::getBehaviourInstance(){
   if (kamikazebehaviour == nullptr ){
        kamikazebehaviour = new KamikazeBehaviour(); 
    }
    return kamikazebehaviour;
}

void KamikazeBehaviour::getRidOfInstance(void){
   delete kamikazebehaviour;
   cout << " LA DESTRUCTION DE LA KAMIKAZE EFFECTIVEMENT LIEU !" <<endl;   
}

KamikazeBehaviour::~KamikazeBehaviour() {
}


// Méthode permettant de récupérer la bestiole la plus proche
// de la bestiole courante
std::vector<Animal*> KamikazeBehaviour::nearestNeighbors(Animal* pet, Environment& myEnvironment){
   double         dist;
   Animal* closest;
   std::vector<Animal *> closestPets;
   // On récupère le vecteurs des voisins détectés dans l'environnement
   std::vector<Animal*> pets = myEnvironment.detectedNeighbors(pet);

   auto cord = pet->getCoordinates();
   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double best_distance = std::numeric_limits<double>::infinity();
   int neighbor = 0;

   // On ne garde que la bestiole la plus proche
   for (std::vector<Animal *>::iterator it = pets.begin() ; it != pets.end() ; ++it){
      auto neighbor_cord = (*it)->getCoordinates();
      int neighbor_x = std::get<0>(neighbor_cord);
      int neighbor_y = std::get<1>(neighbor_cord);
      ++neighbor;
      dist = std::sqrt( (x-neighbor_x)*(x-neighbor_x) + (y-neighbor_y)*(y-neighbor_y) );
      if(dist <= best_distance){
            // Pour la Kamikaze, on ne garde que la bestiole la plus proche
            closest = *it;
      }
   }
   if(neighbor != 0){    
       // Pour la Kamikaze, on ne garde que le voisin le plus proche
       // que l'on récupère dans le vecteur de sortie
       closestPets.push_back(closest);
   }
   return closestPets;
}


void KamikazeBehaviour::move(int xLim, int yLim, Animal* pet, Environment& myEnvironment) {
   auto cord = pet->getCoordinates();
   auto cumul = pet->getCumul();
   auto orient_speed = pet->getOrientationSpeed();

   int x = std::get<0>(cord);
   int y = std::get<1>(cord);
   double cumulX = std::get<0>(cumul); 
   double cumulY = std::get<1>(cumul);
   double orientation = std::get<0>(orient_speed);
   double speed = std::get<1>(orient_speed);

   // On récupère les coordonnées de la bestiole la plus proche
   // de la bestiole courante
   double nearestPet_x;
   double nearestPet_y;
   std::vector<Animal *> closestPets = this->nearestNeighbors(pet,myEnvironment);

   // On vérifie qu'il y a au moins une bestiole identifiée
   // comme étant la plus proche
   if(!closestPets.empty()){
      cout << "At least one neighbor for Kamikaze ! " << endl;
      // Lorsqu'une Kamikaze ne détecte aucun bestiole autour d'elle
      // la variable has_reset_orientation permettra de vérifier que
      // la bestiole a relancé son mouvement avec une orientation
      // aléatoire
      has_reset_orientation = 0;
      auto nearestPet_cord = closestPets.back()->getCoordinates();
      nearestPet_x = std::get<0>(nearestPet_cord);
      nearestPet_y = std::get<1>(nearestPet_cord);

      // La nouvelle orientation de la kamikaze sera fonction
      // de ses cordonnées et celles de son plus proche voisin
      double abs_diff = nearestPet_x-x;
      double ord_diff = nearestPet_y-y;
      double hypothenuse = sqrt (pow(abs_diff,2)+pow(ord_diff,2));
      if(hypothenuse != 0){
         // La nouvelle orientation de la kamikaze sera fonction
         // de ses cordonnées et celles de son plus proche voisin
         orientation = acos (abs_diff / hypothenuse) ;
        }
        else{
            // Si la kamikaze ne détecte rien, on lui attribue une orientation 
            // aléatoire (si cela n'a pas été déjà fait)
            cout << "No neighbor for Kamikaze "<< endl;
            if (!has_reset_orientation){
                 cout << "Reset Orientation for Kamikaze "<< orientation << endl;
                 has_reset_orientation = 1;
                 orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
            }
        }
        // On définit les nouveaux paramètres de mouvement de la bestiole
        MoveUtils::setMoveParameters(pet, x, y, xLim, yLim, orientation, speed, cumulX, cumulY);
   } 
}
