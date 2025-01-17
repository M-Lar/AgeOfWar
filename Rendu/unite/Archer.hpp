#include <iostream>
#include <cstdlib>

#include "Unite.hpp"

#ifndef archer
#define archer


class Archer : public Unite{
private:
  static int prix;
  static int att;
  static std::pair<int,int> portee;

public:
  Archer(bool isCampA, int pos): Unite(isCampA, pos, 8){};
  Archer(bool isCampA, int pos, int pv):  Unite(isCampA, pos, pv){};
  ~Archer(){};


  std::string to_string();

  void afficheCarac();
  void afficheEtat();
  void affiche();

  void print(int i);

  std::string getInstance(){return "Archer";}
  std::pair<int,int> getPortee(){return portee;}
  int getPrix(){return prix;};

  int Attaquer(Unite* enemie);




};
int Archer::prix = 12;
int Archer::att = 3;
std::pair<int,int> Archer::portee = std::make_pair(1,3);


#endif
