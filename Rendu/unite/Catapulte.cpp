#include <iostream>
#include <cstdlib>

#include "Catapulte.hpp"


std::string Catapulte::to_string(){
  return "C["+Unite::to_string()+"]";
}

void Catapulte::afficheCarac(){
  std::cout<<"C";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<std::endl;
}
void Catapulte::afficheEtat(){
  std::cout<<"C";
  Unite::afficheEtat();
  std::cout<<std::endl;
}
void Catapulte::affiche(){
  std::cout<<"C[";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<"|";
  Unite::afficheEtat();
  std::cout<<"]"<<std::endl;
}

void Catapulte::print(int i){
  if(i==-1) std::cout<< colorGreen<< into_string(getPv(),3)+" ";
  else if(getIsCampA()) {
    std::cout << colorCyan;
    if(i==2)      std::cout<< "0\\  ";
    else if(i==1) std::cout<< "  \\ ";
    else if(i==0) std::cout<< "O‾‾O";
    else std::cout<< "    ";
  } else {
    std::cout << colorMagenta;
    if(i==2)      std::cout<< "  /0";
    else if(i==1) std::cout<< " /  ";
    else if(i==0) std::cout<< "O‾‾O";
    else std::cout<< "    ";
  }
  std::cout<< colorReset;
}

int Catapulte::Attaquer(Unite* cible){
  if(cible==nullptr) return 0;
  return (cible->loselife(att));
}


bool Catapulte::Avancer(){
  if(!getAsAction1()) return Unite::Avancer();
  return false;
}
