#include <iostream>
#include <cstdlib>

#include "Terrain.hpp"


Terrain::Terrain(){
    //if(taille>4) cases=new Case[taille];
    cases.resize(taille);

}
Terrain::~Terrain(){
  //delete [] cases;
}

void Terrain::affiche(){
  std::cout << "inAffiche" << '\n';
  for(int i=0; i<taille; i++){
    //cases[i].affiche();
    cases.at(i).affiche();
  }
  std::cout<<std::endl;
  std::cout << "outAffiche" << '\n';
}



void Terrain::addFantassin(bool isTourA){

  Fantassin* fant= new Fantassin(isTourA, (isTourA?3:taille-1));
  cases[0].set(fant);
  //fant.affiche();
  cases.at(0).get()->affiche();
  cases.at(0).get()->print(); std::cout << '\n';
}


void Terrain::tourAB(){
  for(int i=0; i<taille; i++){
    //cases.at(i).tour();
  }
}
void Terrain::tourBA(){

}

void Terrain::Action1(){}
void Terrain::Action2(){
  for(int i=0; i<taille; i++){
    if(cases.at(i).get()!=nullptr) {}
  }

}
void Terrain::Action3(){}
