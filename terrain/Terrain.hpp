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

public:
  Terrain(int t);
  ~Terrain();

  int getTaille(){return taille;}

  void affiche();

//protected:
  template <class U>
  void add(bool isTourDeA);

  void tourAB();
  void tourBA();

  void Action1(bool sensAB);
  void Action2(bool sensAB);
  void Action3(bool sensAB);

  void afficheVictoire();



  //void avancer();



};


#endif
