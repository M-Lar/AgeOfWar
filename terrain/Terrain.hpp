#include <iostream>
#include <cstdlib>
#include "Case.hpp"
#include "../unite/Tour.hpp"
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
  Tour TourB= Tour(true,taille-1, 100);

public:
  Terrain();
  ~Terrain();

  int getTaille(){return taille;}

  void affiche();

//protected:
  void addFantassin(bool isTourA);

  void tourAB();
  void tourBA();

  void Action1();
  void Action2();
  void Action3();


  //void avancer();



};


#endif
