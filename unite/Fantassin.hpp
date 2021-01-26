#include <iostream>
#include <cstdlib>

#include "Unite.hpp"

#ifndef fantassin
#define fantassin


class Fantassin : public Unite{
private:
  static int prix;
  static int att;
  static std::pair<int,int> portee;
  bool isSuper= false;

public:
  Fantassin(bool isCampA, int pos): Unite(isCampA, pos, 10){};
  Fantassin(bool isCampA, int pos, int pv):  Unite(isCampA, pos, pv){};
  ~Fantassin(){};

  void afficheCarac();
  void afficheEtat();
  void affiche();

  void print(int i);

  std::pair<int,int> getPortee(){return portee;}
  void setIsSuper(){isSuper=true;}
  bool getIsSuper(){return isSuper;}

  bool Attaquer(Unite* enemie);

  std::string getInstance(){return "Fantassin";}
  //<class U> getInstance2(){return <Fantassin>;}

};
int Fantassin::prix = 10;
int Fantassin::att = 4;
std::pair<int,int> Fantassin::portee = std::make_pair(1,1);


#endif
