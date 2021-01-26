#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
#include "Unite.hpp"
#include "../VC/color.hpp"

/*
std::string colorMagenta="\033[1;35m";
std::string colorCyan   ="\033[1;36m";
std::string colorGreen   ="\033[1;32m";
//std::string colorMagentaB="\033[1m\033[35m";
std::string colorReset="\033[0m";
*/
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



int Unite::Attaquer(Unite* enemie, int att){
  if(enemie==nullptr) return 0;
  if(enemie->isCampA==isCampA) return 0;
  if(enemie->loselife(att)) return (enemie->getPrix()/2);
  return 0;
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
  //asAction1= true;
  return false;
}

/*
template<class U>
bool instanceofUnite(const U* u){

  try {
   Unite *newU= (Unite)u;
   return true;
 } catch (static_cast& e) {
   std::cerr << e.what();
   return false;
 }
}
*/
