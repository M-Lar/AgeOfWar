#include <iostream>
#include <cstdlib>

#include "Jeu.hpp"


void Jeu::jouer(){
  std::cout << " -- Bienvenue dans Age Of War --" << '\n';

  while(jeuEnCour){
    Action1(isTourA);
    Action2(isTourA);
    Action3(isTourA);
    

    isTourA= !isTourA;
  }

}
