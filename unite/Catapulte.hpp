#include <iostream>
#include <cstdlib>

#include "Unite.hpp"

#ifndef catapulte
#define catapulte


class Catapulte : public Unite{
private:
  static int prix;
  static int att;
  static std::pair<int,int> portee;

public:
  Catapulte(bool isCampA, int pos): Unite(isCampA, pos, 12){};
  Catapulte(bool isCampA, int pos, int pv):  Unite(isCampA, pos, pv){};
  ~Catapulte(){};

  //Catapulte copy(Catapulte &u);

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
int Catapulte::prix = 20;
int Catapulte::att = 6;
std::pair<int,int> Catapulte::portee = std::make_pair(2,3);


#endif
