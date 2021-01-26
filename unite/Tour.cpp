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

  if(isCampA){
    std::cout << colorCyan;
    if(i==3)      std::cout<< "|\\_/‾\\_/| ";
    else if(i==2) std::cout<< "|       | ";
    else if(i==1) std::cout<< "|     _ | ";
    else if(i==0) std::cout<< "|    | || ";
    else if(i==-1) std::cout<< into_string(pv,5)+"     ";
    else std::cout<< "          ";
  } else {
    std::cout << colorMagenta;
    if(i==3) std::cout<< " |\\_/‾\\_/|";
    else if(i==2) std::cout<< " |       |";
    else if(i==1) std::cout<< " | _     |";
    else if(i==0) std::cout<< " || |    |";
    else if(i==-1) std::cout<< into_string(pv,8)+"  ";
    else std::cout<< "          ";
  }
  std::cout<< colorReset;

}
void Tour::print(int i, Unite *u){
  if (u==nullptr) print(i);
  else{
    if(isCampA){
      std::cout << colorCyan;
      if(i==3) std::cout<< "|\\_/‾\\_/| ";
      else if(i==2) {std::cout<< "|  " ; u->print(i); std::cout<< colorCyan<< " | ";}
      else if(i==1) {std::cout<< "|  " ; u->print(i); std::cout<< colorCyan<< " | ";}
      else if(i==0) {std::cout<< "|  " ; u->print(i); std::cout<< colorCyan<< " | ";}
      else if(i==-1){std::cout<< into_string(pv,4)+" "<< colorGreen<< into_string(u->getPv(),3) <<"  ";}
      else std::cout<< "          ";
    } else {
      std::cout << colorMagenta;
      if(i==3) std::cout<< " |\\_/‾\\_/|";
      else if(i==2) {std::cout<< " | " ; u->print(i); std::cout<< colorMagenta<< "  |";}
      else if(i==1) {std::cout<< " | " ; u->print(i); std::cout<< colorMagenta<< "  |";}
      else if(i==0) {std::cout<< " | " ; u->print(i); std::cout<< colorMagenta<< "  |";}
      else if(i==-1){std::cout<< colorGreen << into_string(u->getPv(),4)<< colorMagenta << " " <<into_string(pv,4)+" ";}
      else std::cout<< "          ";
    }
    std::cout<< colorReset;
  }
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
