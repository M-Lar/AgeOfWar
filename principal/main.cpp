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
  T.add<Fantassin>(false);
  T.add<Archer>(true);
  T.affiche();

  //std::cout << "survie1" << '\n';
  //std::cout << "test1" << '\n';
  for (int i=0; i< 30; i++){
    //std::cout << "test2" << '\n';
    //std::cout << " i:" << i;
    T.add<Fantassin>(false);
    T.tourAB(); T.tourBA();
    T.affiche();
    
  }
  T.affiche();
  std::cout << "survie2" << '\n';
  /*T.add<Fantassin>(true);
  T.tourAB();
  T.affiche();*/

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
