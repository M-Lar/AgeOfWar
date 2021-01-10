#include <iostream>
#include <cstdlib>

#include "Terrain.hpp"
#include "../unite/Tour.hpp"

Terrain::Terrain(){
    if(taille>4) {
      cases=new Case[taille];

      Tour TourA= Tour(true,0);
      //Tour TourB= Tour(true,taille-1, 100);
      cases[0].set(TourA);
      //cases[taille-1].set(&TourB);
    }
}
Terrain::~Terrain(){
  delete [] cases;
}

void Terrain::affiche(){
  std::cout << "inAfficheT" << '\n';
  for(int i=0; i<taille; i++){
    cases[i].affiche();
  }
  std::cout<<std::endl;
}



/*
void Terrain::tourAB(){
  for(int i=0; i<taille; i++){

  }
}

void Terrain::tourBA(){

}
*/
