#include <iostream>
#include <cstdlib>

#include "Fantassin.hpp"


std::string Fantassin::to_string(){
  return (isSuper?"S[":"F[")+Unite::to_string()+"]";
}

void Fantassin::afficheCarac(){
  std::cout<<(isSuper?"S[":"F[");
  Unite::afficheCarac(prix, att, portee);
  std::cout<<std::endl;
}
void Fantassin::afficheEtat(){
  std::cout<<(isSuper?"S[":"F[");
  Unite::afficheEtat();
  std::cout<<std::endl;
}
void Fantassin::affiche(){
  std::cout<<(isSuper?"S[":"F[");
  Unite::afficheCarac(prix, att, portee);
  std::cout<<"|";
  Unite::afficheEtat();
  std::cout<<"]"<<std::endl;
}

void Fantassin::print(int i){

  if(i==-1) std::cout<< colorGreen<< into_string(getPv(),3)+" ";
  else if(getIsCampA()) {
    std::cout << colorCyan;
    if(i==2)      std::cout<< (isSuper?"Ö":"O") <<"  /";
    else if(i==1) std::cout<< "|-/ ";
    else if(i==0) std::cout<< "|   ";
    else std::cout<< "    ";
  } else {
    std::cout << colorMagenta;
    if(i==2)      std::cout<< "\\  "<< (isSuper?"Ö":"O");
    else if(i==1) std::cout<< " \\-|";
    else if(i==0) std::cout<< "   |";
    else std::cout<< "    ";
  }
  std::cout<< colorReset;

}

int Fantassin::Attaquer(Unite* enemie){
  if(isSuper || !getAsAction1()){
   int isDead= Unite::Attaquer(enemie, att);
   if(isDead && enemie->getInstance()=="Fantassin") isSuper=true;
   return isDead;
 }
 return false;
}
