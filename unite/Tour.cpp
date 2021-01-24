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

std::string Tour::print(int i){
  return"T";
  i=i;
}
/*
void Tour::Action1(){
  asAction1=Attaquer(portee);
}
void Tour::Action2(){}
void Tour::Action3(){
  if(asAction1){

  }
}
*/
