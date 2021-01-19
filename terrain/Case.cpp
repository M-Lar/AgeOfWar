#include <iostream>
#include <cstdlib>

#include "Case.hpp"

void Case::destruct(){
  if(contenue!=nullptr) delete contenue;
}
Case::~Case(){
  destruct();
}

void Case::affiche() const{
  //std::cout << "inAfficheCase" << '\n';
  if(contenue!=nullptr) {
    //std::cout<<" ouiiii ";
    contenue -> print();
  } else {
    std::cout<<" _ ";
  }
  //std::cout << "outAfficheCase" << '\n';
}

//template <class U>
void Case::set(Unite* u){
  contenue=u;
}
Unite* Case::get(){
  return contenue;
}

//void Case::tour(){
  /*
  contenue->Action1();
  contenue->Action2();
  contenue->Action3();
  */
  /*
  if(contenue)
  contenue->move();
  */
//};
