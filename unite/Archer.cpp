#include <iostream>
#include <cstdlib>

#include "Archer.hpp"


std::string Archer::to_string(){
  return "A["+Unite::to_string()+"]";
}

void Archer::afficheCarac(){
  std::cout<<"A";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<std::endl;
}
void Archer::afficheEtat(){
  std::cout<<"A";
  Unite::afficheEtat();
  std::cout<<std::endl;
}
void Archer::affiche(){
  std::cout<<"A[";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<"|";
  Unite::afficheEtat();
  std::cout<<"]"<<std::endl;
}

void Archer::print(int i){
  if(i==-1) std::cout<< colorGreen<< into_string(pv,3)+" ";
  else if(isCampA) {
    std::cout << colorCyan;
    if(i==2)      std::cout<< "O \\ ";
    else if(i==1) std::cout<< "|- |";
    else if(i==0) std::cout<< "| / ";
    else std::cout<< "    ";
  } else {
    std::cout << colorMagenta;
    if(i==2)      std::cout<< " / O";
    else if(i==1) std::cout<< "| -|";
    else if(i==0) std::cout<< " \\ |";
    else std::cout<< "    ";
  }
  std::cout<< colorReset;
}

int Archer::Attaquer(Unite* enemie){
  if (!asAction1) return (Unite::Attaquer(enemie, att));
  return false;
}
