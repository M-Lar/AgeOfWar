#include <iostream>
#include <cstdlib>

#include "../principal/outils.cpp"



#ifndef unite
#define unite

//enum uniteType { Tour = 1, Fantassin, Archer, Catapulte, Super-soldat};

class Unite{
//private:
protected:

  int pv;

  int pos;
  bool isCampA;
  bool asAction1=false;

protected:
  //il faut lister les fonction que réalise les unités

  void afficheCarac(int prix, int att, std::pair<int,int> portee);

public:
  Unite(bool isCampG, int pos, int pv);
  virtual ~Unite(){};

  virtual void afficheCarac() =0;
  virtual void afficheEtat();//const Unite u) const;
  virtual void affiche() =0;

  virtual std::string print(int i) =0;

  virtual std::pair<int,int> getPortee()=0;
  bool getIsCampA(){return isCampA;}
  bool getAsAction1(){return asAction1;}
  void setAsAction1(bool b){asAction1=b;}

  //template <class U>
  virtual bool Attaquer(Unite* enemie, int att);
  virtual bool Avancer();

  virtual bool Attaquer(Unite* enemie)=0;

  virtual bool loselife(int att);


};

#endif
