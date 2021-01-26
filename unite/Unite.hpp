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

  virtual void print(int i) =0;


  virtual std::string getInstance(){return "Unite";}
  //virtual <class U> getInstance2(){return <Unite>;}
  int getPv(){return pv;}
  int getPos(){return pos;}
  virtual std::pair<int,int> getPortee()=0;
  virtual int getPrix()=0;
  bool getIsCampA(){return isCampA;}
  bool getAsAction1(){return asAction1;}
  void setAsAction1(bool b){asAction1=b;}

  bool isSameCamp(Unite *u){return isCampA==u->getIsCampA();}

  virtual int Attaquer(Unite* enemie)=0;

  int Attaquer(Unite* enemie, int att);
  bool Avancer();


  bool loselife(int att);


/*
  template<class U>
  bool instanceofUnite(const U* u);
*/
};

#endif
