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
  std::string print(int i) const;

  void set(Unite* u){ contenue=u; }
  Unite* get(){ return contenue; }
  bool estVide(){return contenue==nullptr;}

  //void tour();


};


#endif
