#include <iostream>
#include <cstdlib>

#include "Terrain.hpp"


Terrain::Terrain(){ cases.resize(taille); }
Terrain::~Terrain(){}

void Terrain::affiche(){
  //std::cout << "inAffiche" << '\n';
  for(int li=4; li>=-1; li--){
    //cases[i].affiche();
    for(int i=0; i<taille; i++){
      cases.at(i).print(li);
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
  //std::cout << "outAffiche" << '\n';
}



void Terrain::addFantassin(bool isTourA){
  int dep;
  if(isTourA) dep=0;
  else dep=taille-1;

  Fantassin* fant= new Fantassin(isTourA, (isTourA?3:taille-1));
  cases[dep].set(fant);
  //fant.affiche();
  //cases.at(dep).get()->affiche();
  //scases.at(dep).get()->print(); std::cout << '\n';
}


void Terrain::tourAB(){
  //std::cout << "ab" << '\n';
  //std::cout << "0" << '\n';
  //Action1(true);
  //std::cout << "1" << '\n';
  Action2(true);
  //std::cout << "2" << '\n';
  Action3(true);
  //std::cout << "3" << '\n';
}
void Terrain::tourBA(){
  //Action1(false);
  Action2(false);
  Action3(false);
}

void Terrain::Action1(bool sensAB){

  if(sensAB){
    for(int i=0; i<taille; i++){
      auto uTemp= cases.at(i).get();
      auto portee= uTemp->getPortee();

      if(uTemp!=nullptr && uTemp->getIsCampA()){
        for(int j=i+portee.first; (j<=i+portee.second && j<taille) ; j++){
          auto cible=cases.at(j).get();
          if(cible!=nullptr){

            if(uTemp->Attaquer(cible)){
              uTemp->setAsAction1(true);
              if(instanceof<Catapulte> (uTemp)){ std::cout << "cata" << '\n'; }
            }

          }
        }
      }
    }
  } else {
    for(int i=taille-1; i>=0; i++){
      auto uTemp= cases.at(i).get();
      auto portee= uTemp->getPortee();

      if(uTemp!=nullptr && uTemp->getIsCampA()){
        for(int j=i-portee.second; (j>=i-portee.first && j>=0); j--){
          auto cible=cases.at(j).get();
          if(cible!=nullptr){

            if(uTemp->Attaquer(cible)){
              uTemp->setAsAction1(true);
              if(instanceof<Catapulte> (uTemp)){ std::cout << "cata" << '\n'; }
            }

          }
        }
      }
    }
  }

}
void Terrain::Action2(bool sensAB){

  if(sensAB){
    for(int i=taille-3; i>=0; i--){

      auto uTemp= cases.at(i).get();

      auto suiv=cases.at(i+1).get();
      if(uTemp!=nullptr && uTemp->getIsCampA())
      if(suiv==nullptr && !instanceof<Catapulte> (uTemp)){ //(std::is_base_of<Catapulte, typeid(uTemp).name()>::value)
        uTemp->Avancer();
        cases.at(i+1) =cases.at(i);
        cases.at(i)   =Case();
      }
    }
  } else {
    for(int i=3; i<taille; i++){
      auto uTemp= cases.at(i).get();

      auto suiv=cases.at(i-1).get();
      if(uTemp!=nullptr && !uTemp->getIsCampA())
      if(suiv==nullptr && !instanceof<Catapulte> (uTemp)){ //(std::is_base_of<Catapulte, typeid(uTemp).name()>::value)
        uTemp->Avancer();
        cases.at(i-1) =cases.at(i);
        cases.at(i)   =Case();
      }
    }
  }

}
void Terrain::Action3(bool sensAB){

  if(sensAB)
  for(int i=0; i<taille; i++){
    auto uTemp= cases.at(i).get();
    if(uTemp!=nullptr) {
      if(uTemp->getAsAction1()){}
      uTemp->setAsAction1(false);
    }

  }
}
