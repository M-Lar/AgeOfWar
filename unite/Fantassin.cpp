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

std::string Fantassin::print(int i){
  //std::cout<<"F";


  if(isCampA) {
    if(i==2)      return "O  /";
    else if(i==1) return "|-/ ";
    else if(i==0) return "|   ";
    else return "    ";

/*
    switch(i) {
      case 2: std::cout<< "O  /"; break;
      case 1: std::cout<< "|-/ "; break;
      case 0: std::cout<< "|	 "; break;
      default: std::cout<< "    ";
    }
*/
  } else {
    if(i==2)      return "\\  O";
    else if(i==1) return " \\-|";
    else if(i==0) return "   |";
    else return "    ";
/*
    switch(i) {
      case 2: std::cout<< "\\  O"; break;
      case 1: std::cout<< " \\-|"; break;
      case 0: std::cout<< "   |"; break;
      default: std::cout<< "    ";
    }
*/
  }
}
