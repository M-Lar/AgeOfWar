#include <iostream>
#include <cstdlib>

#include "include.h"

/*
#include <chrono>
#include <thread>
*/

void init(){
  std::cout << " -- Bienvenue dans Age Of War --" << '\n';

  Terrain T= Terrain();
  T.affiche();
}

int main(){
  init();

  return 0;
}
