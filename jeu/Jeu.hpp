#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
//#include "Menu.hpp"


#ifndef jeu
#define jeu

class Jeu : public Terrain{
private:
  int maxTourDeJeu;//=100;
  int numTourCourant=1;
  bool isTourA=false;
  bool bot=false;

protected:
  void reset(int mTJ, int nT, bool isTA, bool vsBot, int t, int pvA, int pvB, int aA, int aB, std::string ter, int nbUniteCree);

public:
  //Jeu(): Terrain(){}
  Jeu(int mTJ=100, int t=12, int pvTour=100, int argent=8): Terrain(t, pvTour, argent){ Jeu::maxTourDeJeu=mTJ; }

  ~Jeu(){}

  void affiche();
  bool init();

  bool achatUnite(char u);
  bool achatUnite();


  void jouer();


  char decisionBot();

  void save();
  void load();
};

#endif
