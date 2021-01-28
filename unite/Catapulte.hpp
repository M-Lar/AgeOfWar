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

  std::string to_string();

  void afficheCarac();
  void afficheEtat();
  void affiche();

  void print(int i);

  std::string getInstance(){return "Catapulte";}
  //<class U> getInstance2(){return <Catapulte>;}
  std::pair<int,int> getPortee(){return portee;}
  int getPrix(){return prix;};

  int Attaquer(Unite* cible);
  //std::pair<bool,bool> Attaquer(Unite* enemie1, Unite* enemie2);
  bool Avancer();



};
int Catapulte::prix = 20;
int Catapulte::att = 6;
std::pair<int,int> Catapulte::portee = std::make_pair(2,4);


#endif
