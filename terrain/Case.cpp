#include <iostream>
#include <cstdlib>

#include "Case.hpp"

void Case::destruct(){
  if(contenue!=nullptr) delete contenue;
}
Case::~Case(){
  //destruct();
  delete contenue;
}

void Case::print(int i) const{

  if(contenue!=nullptr) {
    (contenue -> print(i));
  } else {
    if(i==0) std::cout<<" __ ";
    else std::cout<<"    ";
  }
}

char Case::contenueCase() const{
  if(contenue!=nullptr) {
    if(contenue->getInstance()=="Fantassin") return 'f';
    else if(contenue->getInstance()=="Archer") return 'a';
    else if(contenue->getInstance()=="Catapulte") return 'c';
  }
  return '_';
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
