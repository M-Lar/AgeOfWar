#include <iostream>
#include <cstdlib>

#include "include.h"

void test1(){
  Fantassin f1= Fantassin(true,3);
  f1.affiche();

  Terrain T= Terrain();
  T.affiche();
  std::cout << "4" << '\n';
}

void test2(){

}


int main(){
  test1();

  //std::cout << "bye" << std::endl;
  return 0;
}
