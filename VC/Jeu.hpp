#include <iostream>
#include <cstdlib>
#include <vector>

#include "../terrain/Terrain.hpp"
#include "Menu.hpp"


#ifndef jeu
#define jeu

class Jeu : public Terrain{
private:
  //static Menu m;
  bool jeuEnCour=true;
  bool isTourA=true;
  /*static*/ int maxTourDeJeu;
  int argentA=8;
  int argentB=8;

public:
  Jeu(int mTJ): Terrain(12){ Jeu::maxTourDeJeu=mTJ; }
  ~Jeu(){}

  void affiche();

  template <class U>
  bool achat();
  bool achatUnite(char u);
  static char getEntree(std::vector<std::string> entre);

  void payer(int *budjet, int prix){ (*budjet)-=prix; }

  void jouer();
};
//int Jeu::maxTourDeJeu;
//Menu Jeu::menu;

#endif
