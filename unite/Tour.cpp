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

void Tour::print(int i){
  //return"T";
  if(i==-1) std::cout<< into_string(pv);
  else if(i==2) std::cout<< "  |\\_/‾\\_/|";
  else if(isCampA){
    if(i==1) std::cout<< " |     _ |";
    if(i==0) std::cout<< " |    | ||";
  } else {
    if(i==1) std::cout<< " | _     |";
    if(i==0) std::cout<< " || |    |";
  }
  std::cout<< "          ";
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
