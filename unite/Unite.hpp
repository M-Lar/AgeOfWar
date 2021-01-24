#include <iostream>
#include <cstdlib>



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

  //virtual Unite copy(Unite &u)=0;
  /*
  template <class U>
  U copy(U u);
  */

  virtual void afficheCarac() =0;
  virtual void afficheEtat();//const Unite u) const;
  virtual void affiche() =0;

  virtual void print() =0;

  //template <class U>
  virtual bool Attaquer(Unite* enemie, int att);
  virtual bool Avancer();

  virtual bool loselife(int att);


};


template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}

#endif
