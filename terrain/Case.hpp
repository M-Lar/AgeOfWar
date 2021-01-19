#include <iostream>
#include <cstdlib>

#include "../unite/Unite.hpp"

#ifndef case
#define case
class Case{
private:
  Unite *contenue;
  void destruct();

public:
  Case(){contenue=nullptr;}
  ~Case();
  void affiche() const;

  void set(Unite *u);
  Unite* get();

  //void tour();


};


#endif
