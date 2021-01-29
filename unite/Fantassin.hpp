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
  //Fantassin(bool isCampA, int pos): Unite(isCampA, pos, 10){};
  Fantassin(bool isCampA, int pos, int pv= 10, bool isS=false):  Unite(isCampA, pos, pv){isSuper= isS;};
  Fantassin(Unite* u, bool isS=false):  Unite(u->getIsCampA(), u->getPos(), u->getPv()){isSuper=isS;};
  ~Fantassin(){};

  std::string to_string();

  void afficheCarac();
  void afficheEtat();
  void affiche();

  void print(int i);

  std::string getInstance(){return "Fantassin";}
  //<class U> getInstance2(){return <Fantassin>;}
  std::pair<int,int> getPortee(){return portee;}
  int getPrix(){return prix;};
  //static bool getIsSuper(Unite* u){return isSuper;}
  bool getIsSuper(){return isSuper;}
  void setIsSuper(){isSuper=true;}


  int Attaquer(Unite* enemie);



};
int Fantassin::prix = 10;
int Fantassin::att = 4;
std::pair<int,int> Fantassin::portee = std::make_pair(1,1);


#endif
