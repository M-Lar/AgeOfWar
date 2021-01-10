#include <iostream>
#include <cstdlib>

#include "Tour.hpp"


/*Tour Tour::copy(Tour &u){
  return Tour(u.isCampA, u.pos, u.pv);
}*/

void Tour::afficheCarac(){
  std::cout<<"T:";
  Unite::afficheCarac(prix, att, portee);
}
void Tour::afficheEtat(){
  std::cout<<"T:";
  Unite::afficheEtat();

}
void Tour::affiche(){
  std::cout<<"T:[";
  Unite::afficheCarac(prix, att, portee);
  std::cout<<"|";
  Unite::afficheEtat();
  std::cout<<"]"<<std::endl;
}

void Tour::print(){
  std::cout<<"T";
}
