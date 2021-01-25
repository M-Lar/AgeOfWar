#include <iostream>
#include <cstdlib>

#include "Archer.hpp"



void Archer::afficheCarac(){
  std::cout<<"A:";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<std::endl;
}
void Archer::afficheEtat(){
  std::cout<<"A:";
  Unite::afficheEtat();
  std::cout<<std::endl;
}
void Archer::affiche(){
  std::cout<<"A:[";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<"|";
  Unite::afficheEtat();
  std::cout<<"]"<<std::endl;
}

void Archer::print(int i){
  if(i==-1) std::cout<< into_string(pv,3)+" ";
  else if(isCampA) {
    if(i==2)      std::cout<< "O \\ ";
    else if(i==1) std::cout<< "|- |";
    else if(i==0) std::cout<< "| / ";
    else std::cout<< "    ";
  } else {
    if(i==2)      std::cout<< " / O";
    else if(i==1) std::cout<< " | -|";
    else if(i==0) std::cout<< " \\ |";
    else std::cout<< "    ";
  }
}
