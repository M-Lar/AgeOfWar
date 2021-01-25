#include <iostream>
#include <cstdlib>

#include "include.h"

void test1(){
  Fantassin f1= Fantassin(true,3);
  f1.affiche();
  std::cout << "la  " <<  typeid(f1).name() << '\n';


  Terrain T= Terrain(12);
  T.affiche();
  std::cout << "4" << '\n';
  //T.add<Fantassin>(false);
  T.add<Catapulte>(true);
  T.affiche();

  //std::cout << "survie1" << '\n';
  //std::cout << "test1" << '\n';
  for (int i=0; i< 10; i++){
    //std::cout << "test2" << '\n';
    //std::cout << " i:" << i;
    //T.add<Catapulte>(true);
    //T.add<Fantassin>(false);
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
  //Jeu jeu= Jeu();
  //jeu.jouer();
}


int main(){
  test1();
  //test2();

  //system("clear");
  return 0;
}
