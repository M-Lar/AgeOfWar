#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
//#include "Menu.hpp"


#ifndef jeu
#define jeu

class Jeu : public Terrain{
private:
  //static Menu m;
  bool jeuEnCour=true;
  bool victoire=false;
  bool isTourA=true;
  /*static*/ int maxTourDeJeu;


  bool multi=true;

public:
  Jeu(int mTJ): Terrain(12){ Jeu::maxTourDeJeu=mTJ; }
  ~Jeu(){}

  void affiche();
  void init();

  bool achatUnite(char u);
  bool achatUnite();


  void jouer();

  void save();
  void load();
};
//int Jeu::maxTourDeJeu;
//Menu Jeu::menu;

#endif
