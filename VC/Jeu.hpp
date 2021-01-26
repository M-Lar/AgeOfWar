#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
#include "Menu.hpp"


#ifndef jeu
#define jeu

class Jeu : public Terrain{
private:
  //static Menu m;
  bool jeuEnCour=true;
  bool victoire=false;
  bool isTourA=true;
  /*static*/ int maxTourDeJeu;
  int argentA=8;
  int argentB=8;

  bool multi=true;

public:
  Jeu(int mTJ): Terrain(12){ Jeu::maxTourDeJeu=mTJ; }
  ~Jeu(){}

  void affiche();
  void init();

  template <class U>
  bool achat();
  bool achatUnite(char u);
  bool achatUnite();

  void donnerArgent();
  void payer(int *budjet, int prix){ (*budjet)-=prix; }


  void jouer();

  void save();
  void load();
};
//int Jeu::maxTourDeJeu;
//Menu Jeu::menu;

#endif
