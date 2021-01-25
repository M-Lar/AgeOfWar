#include <iostream>
#include <cstdlib>

#include "Unite.hpp"

#ifndef super_soldat
#define super_soldat


class Super_soldat : public Fantassin{
private:

public:
  //Super_soldat(bool isCampA, int pos): Fantassin(isCampA, pos, 10){};
  Super_soldat(bool isCampA, int pos, int pv):  Fantassin(isCampA, pos, pv){};
  ~Super_soldat(){};

  void print(int i);

  std::string getInstance(){return "Super_soldat";}

};

#endif
