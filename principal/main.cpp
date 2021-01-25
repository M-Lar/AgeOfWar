#include <iostream>
#include <cstdlib>

#include "include.h"

void test1(){
  Fantassin f1= Fantassin(true,3);
  f1.affiche();
  std::cout << "la  " <<  typeid(f1).name() << '\n';


  Terrain T= Terrain();
  T.affiche();
  std::cout << "4" << '\n';
  T.addFantassin(true);
  T.addFantassin(false);
  T.affiche();

  //std::cout << "survie1" << '\n';
  //std::cout << "test1" << '\n';
  for (int i=0; i< 16; i++){
    //std::cout << "test2" << '\n';
    //std::cout << " i:" << i;
    T.tourAB(); T.tourBA();
  }
  T.affiche();
  std::cout << "survie2" << '\n';
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
