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

std::string Case::contenueCase() const{
  if(contenue!=nullptr) {
    //std::cout << contenue->to_string() << '\n';
    return contenue->to_string();
  }
  return "";
}
