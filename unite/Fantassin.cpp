#include <iostream>
#include <cstdlib>

#include "Fantassin.hpp"



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

void Fantassin::print(int i){
  //std::cout<<"F";
  //return "F";


  if(i==-1) std::cout<< into_string(pv,3)+" ";
  else if(isCampA) {
    if(i==2)      std::cout<< "O  /";
    else if(i==1) std::cout<< "|-/ ";
    else if(i==0) std::cout<< "|   ";
    else std::cout<< "    ";
  } else {
    if(i==2)      std::cout<< "\\  O";
    else if(i==1) std::cout<< " \\-|";
    else if(i==0) std::cout<< "   |";
    else std::cout<< "    ";
  }

/*
  if(i==-1) std::cout<< into_string(pv,3)+" ";
  else if(isCampA) {
      switch(i) {
        case 2: std::cout<< "O  /"; break;
        case 1: std::cout<< "|-/ "; break;
        case 0: std::cout<< "|   "; break;
        default: std::cout<< "    ";
      }
  } else {
      switch(i) {
        case 2: std::cout<< "\\  O"; break;
        case 1: std::cout<< " \\-|"; break;
        case 0: std::cout<< "   |"; break;
        default: std::cout<< "    ";
      }
  }
*/
}
