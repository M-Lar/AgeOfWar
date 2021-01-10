#include <iostream>
#include <cstdlib>

#include "Unite.hpp"

Unite::Unite(bool isCampA, int pos, int pv) {
  Unite::pv=pv;

  Unite::pos=pos;
  Unite::isCampA=isCampA;
}

/*Unite Unite::copy(Unite &u){
  return (Unite(u.pv, u.isCampA, u.pos));
}*/
/*
template <class U>
U Unite::copy(U u){
   return (U(u.isCampA, u.pos, u.pv));
}*/

void Unite::afficheCarac(int prix, int att, std::pair<int,int> portee){
  std::cout<<"prix:"<<prix<<"|att:"<<att<<"|portee:("<<portee.first<<","<<portee.second<<")";
}
void Unite::afficheEtat()/*const*/{
  std::cout<<"pv:"<<pv<<"|pos:"<<pos<<"|camp:"<<(isCampA?"A":"B");
}
