#include <iostream>
#include <cstdlib>
#include "Case.hpp"
#include "allUnite.h"

#include <vector>


#ifndef terrain
#define terrain
class Terrain{
private:
  //Case *cases;
  std::vector<Case> cases;
  /*
  int taille;
  int vieBg;
  int vieBd;*/
  int taille= 12;
  Tour TourA= Tour(true,0);
  Tour TourB= Tour(false,taille-1, 100);
  int argentA=8;
  int argentB=8;

public:
  Terrain(int t);
  ~Terrain();

  int getTaille(){return taille;}
  int getArgentA(){return argentA;}
  int getArgentB(){return argentB;}

  void affiche(int nbLi);

//protected:
  template <class U>
  void add(bool isTourDeA);
  template <class U>
  bool achat(bool isTourDeA);
  void donnerArgent(bool isTourDeA, int montant=8);
  void payer(int *budjet, int prix){ (*budjet)-=prix; }


  void tourAB();
  void tourBA();

  bool Action1(bool sensAB);
  bool Action2(bool sensAB);
  bool Action3(bool sensAB);

  void afficheVictoire();

  void deplacement(bool sensAB, int i, bool expluCata);
  bool UniteABattaquer(Unite *uTemp,int i);
  bool UniteBAattaquer(Unite *uTemp,int i);


  //void avancer();



};


#endif
