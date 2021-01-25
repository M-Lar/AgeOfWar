#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
#include "Menu.hpp"


#ifndef terrain
#define terrain

class Jeu : public Terrain{
private:
  Menu m;
  bool jeuEnCour;
  bool isTourA;

public:
  Jeu():Terrain(12){
    menu=Menu();
    jeuEnCour=true;
    isTourA=true;
  }
  ~Jeu(){}

  void jouer();
};
//Menu Jeu::menu= Menu();

#endif
