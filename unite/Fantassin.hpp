#include <iostream>
#include <cstdlib>

#include "Unite.hpp"

#ifndef fantassin
#define fantassin


int F_pv = 10;
class Fantassin : public Unite{
private:
  static int prix;
  static int att;
  static std::pair<int,int> portee;

public:
  Fantassin(bool isCampA, int pos): Unite(isCampA, pos, F_pv){};
  Fantassin(bool isCampA, int pos, int pv):  Unite(isCampA, pos, pv){};
  ~Fantassin(){};

  //Fantassin copy(Fantassin &u);

  void afficheCarac();
  void afficheEtat();
  void affiche();

  void print();
/*
  void Action1();
  void Action2();
  void Action3();
*/
};
int Fantassin::prix = 10;
int Fantassin::att = 4;
std::pair<int,int> Fantassin::portee = std::make_pair(1,1);


#endif
