#include <iostream>
#include <cstdlib>
#include "Case.hpp"

#ifndef terrain
#define terrain
class Terrain{
private:
  Case *cases;
  /*
  int taille;
  int vieBg;
  int vieBd;*/
  int taille = 12;
  int vieBg = 100; /* a voir si je laisse la decl comme ça*/
  int vieBd = 100;

public:
  Terrain();
  ~Terrain();

  void affiche();
  //void tourAB();
  //void tourBA();
  void avancer();

};


#endif
