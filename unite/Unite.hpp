#include <iostream>
#include <cstdlib>

#ifndef unite
#define unite

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

  //virtual Unite copy(Unite &u)=0;
  /*
  template <class U>
  U copy(U u);
  */

  virtual void afficheCarac() =0;
  virtual void afficheEtat();//const Unite u) const;
  virtual void affiche() =0;

  virtual void print() =0;
/*
  template <class U>
  virtual bool Attaquer(U* enemie, int att);
  virtual void Avancer();

  virtual void Action1() =0;
  virtual void Action2() =0;
  virtual void Action3() =0;
*/
  virtual bool loselife(int att);


};

#endif
