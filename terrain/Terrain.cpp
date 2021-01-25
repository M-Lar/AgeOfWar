#include <iostream>
#include <cstdlib>

#include "Terrain.hpp"


Terrain::Terrain(){ cases.resize(taille); }
Terrain::~Terrain(){}

void Terrain::affiche(){
  for(int li=4; li>=-1; li--){
    for(int i=0; i<taille; i++){
      cases.at(i).print(li);
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}


template <class U>
void Terrain::add(bool isTourDeA){
  int dep;
  if(isTourDeA) dep=0;
  else dep=taille-1;

  U* unit= new U(isTourDeA, (isTourDeA?3:taille-1));
  cases[dep].set(unit);
}


void Terrain::tourAB(){
  Action1(true);
  Action2(true);
  Action3(true);
}
void Terrain::tourBA(){
  Action1(false);
  Action2(false);
  Action3(false);
}

void Terrain::Action1(bool sensAB){
  if(sensAB){
    for(int i=0; i<taille-1; i++){
      auto uTemp= cases.at(i).get();
      if(uTemp!=nullptr) {
        auto portee= uTemp->getPortee();
        if(uTemp->getIsCampA()){
          for(int j=i+portee.first; (j<=i+portee.second && j<taille) ; j++){
            auto cible= cases.at(j).get();
            if(cible!=nullptr){
              if(!uTemp->getAsAction1()){
                auto isDead= uTemp->Attaquer(cible);
                if(instanceof<Catapulte> (uTemp)){ std::cout << "cata" << '\n'; }

                if(isDead) cases.at(j)= Case();
                break;
              }
            }
          }//endFor
        }
      }
    }
  } else {
    //std::cout << "isInCampB" << '\n';
    for(int i=taille-1; i>0; i--){
      auto uTemp= cases.at(i).get();

      if(uTemp!=nullptr) {
        auto portee= uTemp->getPortee();
        if(uTemp->getIsCampA()){
          //std::cout << "inCampB" << '\n';
          for(int j=i-portee.first; (j>=i-portee.second && j>0); j--){
            //std::cout << "marche" << '\n';
            auto cible=cases.at(j).get();
            //std::cout << typeid(uTemp).name() << " attaq=" << i << " cible=" << j << std::endl;
            if(cible!=nullptr){
              //std::cout << "enfaceB" << '\n';
              if(uTemp->Attaquer(cible)){
                //std::cout << "attaqueB" << '\n';
                uTemp->setAsAction1(true);
                if(instanceof<Catapulte> (uTemp)){ std::cout << "cata" << '\n'; }
                break;
              }
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
