#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
//#include "Menu.hpp"


#ifndef jeu
#define jeu

class Jeu : public Terrain{
private:
  bool isTourA=true;
  int maxTourDeJeu;
  bool bot=false;

public:
  Jeu(int mTJ): Terrain(12){ Jeu::maxTourDeJeu=mTJ; }
  ~Jeu(){}

  void affiche();
  void init();

  bool achatUnite(char u);
  bool achatUnite();


  void jouer();


  char decisionBot();

  void save();
  void load();
};

#endif
