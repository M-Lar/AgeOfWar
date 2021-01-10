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
  if(contenue!=nullptr) {
    contenue -> print();
  } else {
    std::cout<<"_";
  }
}

template <class U>
void Case::set(U &u){
  std::cout << "inSet" << '\n';


  destruct();
  //contenue= Unite::copy(u);
  u=u;
  std::cout << "outSet" << '\n';
}
