#include <iostream>
#include <cstdlib>

#include "Catapulte.hpp"



void Catapulte::afficheCarac(){
  std::cout<<"C:";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<std::endl;
}
void Catapulte::afficheEtat(){
  std::cout<<"C:";
  Unite::afficheEtat();
  std::cout<<std::endl;
}
void Catapulte::affiche(){
  std::cout<<"C:[";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<"|";
  Unite::afficheEtat();
  std::cout<<"]"<<std::endl;
}

void Catapulte::print(int i){
  if(isCampA) {
    if(i==2)      std::cout<< "0\\  ";
    else if(i==1) std::cout<< "  \\ ";
    else if(i==0) std::cout<< "O‾‾O";
    else if(i==-1) std::cout<< into_string(pv,3)+" ";
    else std::cout<< "    ";
  } else {
    if(i==2)      std::cout<< "  /0";
    else if(i==1) std::cout<< " /  ";
    else if(i==0) std::cout<< "O‾‾O";
    else if(i==-1) std::cout<< into_string(pv,3)+" ";
    else std::cout<< "    ";
  }
}
