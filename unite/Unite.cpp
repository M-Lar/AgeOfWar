#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
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



bool Unite::Attaquer(Unite* enemie, int att){
  std::cout << "inAttaquerUnite" << '\n';

  if(enemie->isCampA==isCampA) return false;
  return enemie->loselife(att);
  //return false;
}
bool Unite::Avancer(){
  if(isCampA) pos+=1;
  else if(!isCampA) pos-=1;
  else return false;
  return true;
}


bool Unite::loselife(int att){
  //std::cout << "inLoselife" << '\n';
  pv-=att;
  if(pv<=0) return true;
  asAction1= true;
  return false;
}
