#include <iostream>
#include <cstdlib>

#include "Case.hpp"

void Case::destruct(){
  if(contenue!=nullptr) delete contenue;
}
Case::~Case(){
  destruct();
}

void Case::print(int i) const{
  //std::cout << "inAfficheCase" << '\n';
  //std::string res="";

  if(contenue!=nullptr) {
    //std::cout<<" ouiiii ";
    (contenue -> print(i));//res+=
  } else if(i==0) {
    //std::cout<<" __ ";
    std::cout<<" __ ";//res+=
  } else {
    //std::cout<<"    ";
    std::cout<<"    ";//res+=
  }
  //return res;
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
