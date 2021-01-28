#include <iostream>
#include <cstdlib>

#include "allUnite.h"

#ifndef case
#define case
class Case{
private:
  Unite *contenue;
  void destruct();

public:
  Case(){contenue=nullptr;}
  ~Case();
  void print(int i) const;
  std::string contenueCase() const;

  void set(Unite* u) {if(contenue==nullptr) contenue=u;}
  Unite* get(){ return contenue; }
  bool estVide(){return contenue==nullptr;}

  //void tour();


};


#endif
