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
  Action1(true);
  //Action2(true);
  //Action3(true);
}
void Terrain::tourBA(){

}

void Terrain::Action1(bool sensAB){
  int dep, arriv;
  if(sensAB){dep=0;arriv=taille-1;}
  else{dep=taille-1;arriv=0;}

  Unite * uTemp;
  for(int i=dep; i<=arriv; i++){
    uTemp= cases.at(i).get();
    //auto



    if(instanceof<Catapulte> (uTemp)){
      std::cout << "cata" << '\n';
    }
    //if(){}
    //uTemp->Attaquer();
  }
}
void Terrain::Action2(bool sensAB){
  int dep, arriv;
  if(sensAB){dep=0;arriv=taille-1;}
  else{dep=taille-1;arriv=0;}


  Unite * uTemp;
  for(int i=0; i<taille; i++){
    uTemp= cases.at(i).get();
    if(uTemp!=nullptr) {
      if(instanceof<Fantassin> (uTemp)){
        std::cout << "fant" << '\n';
      }//(uTemp instanceof Fantassin){}
      if(instanceof<Tour> (uTemp)){
        std::cout << "tour" << '\n';
      }
      std::cout << "tre" << '\n';
    }

  }

  
  dep=dep;
  arriv=arriv;

}
void Terrain::Action3(bool sensAB){
  int dep, arriv;
  if(sensAB){dep=0;arriv=taille-1;}
  else{dep=taille-1;arriv=0;}

  dep=dep;
  arriv=arriv;
}
