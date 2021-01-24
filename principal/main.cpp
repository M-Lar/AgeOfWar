#include <iostream>
#include <cstdlib>

#include "include.h"

void test1(){
  Fantassin f1= Fantassin(true,3);
  //f1.affiche();
  std::cout << "la  " <<  typeid(f1).name() << '\n';


  Terrain T= Terrain();
  T.affiche();
  std::cout << "4" << '\n';
  T.addFantassin(true);
  T.addFantassin(false);
  T.affiche();

  for (int i=0; i< 16; i++){
    T.tourAB(); T.tourBA();
  }
  T.addFantassin(true);
  T.tourAB();
  T.affiche();
  //std::cout << "5gfds" << std::flush << '\n';
}

void test2(){
  //std::cout << clear;
}


int main(){
  test1();

  //system("clear");
  return 0;
}
