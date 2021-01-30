#include <iostream>
#include <cstdlib>

#include "../terrain/Terrain.hpp"
#include "Unite.hpp"
#include "../jeu/color.hpp"


Unite::Unite(bool isCampA, int pos, int pv) {
  Unite::pv=pv;

  Unite::pos=pos;
  Unite::isCampA=isCampA;
}

std::string Unite::to_string(){
  return "pv:"+std::to_string(pv)+"|pos:"+std::to_string(pos)+"|camp:"+std::to_string(isCampA);
}
void Unite::afficheCarac(int prix, int att, std::pair<int,int> portee){
  std::cout<<"prix:"<<prix<<"|att:"<<att<<"|portee:("<<portee.first<<","<<portee.second<<")";
}
void Unite::afficheEtat()/*const*/{
  std::cout<<to_string();
}



int Unite::Attaquer(Unite* enemie, int att){
  if(enemie==nullptr) return 0;
  if(enemie->isCampA==isCampA) return 0;
  if(enemie->loselife(att)) {std::cout << " dedU:" << (enemie->getPrix()/2) << '\n';return (enemie->getPrix()/2);}
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
