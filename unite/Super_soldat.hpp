#include <iostream>
#include <cstdlib>

#include "Unite.hpp"

#ifndef super_soldat
#define super_soldat


class Super_soldat : public Fantassin{
private:
  static int prix;
  static int att;
  static std::pair<int,int> portee;

public:
  //Super_soldat(bool isCampA, int pos): Fantassin(isCampA, pos, 10){};
  Super_soldat(bool isCampA, int pos, int pv):  Fantassin(isCampA, pos, pv){};
  ~Super_soldat(){};

  //Super_soldat copy(Super_soldat &u);

  void afficheCarac();
  void afficheEtat();
  void affiche();

  void print();

};
int Super_soldat::prix = 214;//2147483647;
int Super_soldat::att = 4;
std::pair<int,int> Super_soldat::portee = std::make_pair(1,1);


#endif
