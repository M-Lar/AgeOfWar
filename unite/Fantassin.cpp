#include <iostream>
#include <cstdlib>

#include "Fantassin.hpp"


/*Fantassin Fantassin::copy(Fantassin &u){
  return Fantassin(u.isCampA, u.pos, u.pv);
}*/

void Fantassin::afficheCarac(){
  std::cout<<"F:";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<std::endl;
}
void Fantassin::afficheEtat(){
  std::cout<<"F:";
  Unite::afficheEtat();
  std::cout<<std::endl;
}
void Fantassin::affiche(){
  std::cout<<"F:[";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<"|";
  Unite::afficheEtat();
  std::cout<<"]"<<std::endl;
}

void Fantassin::print(){
  std::cout<<"F";
}
