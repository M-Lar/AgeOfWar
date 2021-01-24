#include <iostream>
#include <cstdlib>

#ifndef tour
#define tour
class Tour : public Unite{
private:
  static int prix;
  static int att;
  static std::pair<int,int> portee;

public:
  Tour(bool isCampA, int pos): Unite(isCampA, pos, 100){};
  Tour(bool isCampA, int pos, int pv): Unite(isCampA, pos, pv){};
  ~Tour(){};

  //Tour copy(Tour &u);

  void afficheCarac();
  void afficheEtat();
  void affiche();

  std::string print(int i);

  std::pair<int,int> getPortee(){return portee;}//portee;}

  bool Attaquer(Unite* enemie){return (Unite::Attaquer(enemie, att));}

};
int Tour::prix = 0;
int Tour::att = 0;
std::pair<int,int> Tour::portee = std::make_pair(0,0);

#endif
