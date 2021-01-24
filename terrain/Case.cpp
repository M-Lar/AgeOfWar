#include <iostream>
#include <cstdlib>

#include "Case.hpp"

void Case::destruct(){
  if(contenue!=nullptr) delete contenue;
}
Case::~Case(){
  destruct();
}

std::string Case::print(int i) const{
  //std::cout << "inAfficheCase" << '\n';
  std::string res="";

  if(contenue!=nullptr) {
    //std::cout<<" ouiiii ";
    res+= (contenue -> print(i));
  } else if(i==0) {
    //std::cout<<" __ ";
    res+=" __ ";
  } else {
    //std::cout<<"    ";
    res+="    ";
  }
  return res;
  //std::cout << res << '\n';
  //std::cout << "outAfficheCase" << '\n';
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
