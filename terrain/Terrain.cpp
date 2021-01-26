#include <iostream>
#include <cstdlib>

#include "Terrain.hpp"

#include <chrono>
#include <thread>

Terrain::Terrain(int t){
  taille=t;
  cases.resize(taille);
  TourA= Tour(true,0);
  TourB= Tour(false,taille-1, 100);
}
Terrain::~Terrain(){}

void Terrain::affiche(){
  //std::this_thread::sleep_for(std::chrono::milliseconds(45)); std::system("clear");
  for(int li=4; li>=-1; li--){
    TourA.print(li,cases.at(0).get());
    for(int i=1; i<taille-1; i++){ cases.at(i).print(li);}
    TourB.print(li,cases.at(taille-1).get());
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

void Terrain::afficheVictoire(){
  std::system("clear");
  std::cout << "GG" << '\n';
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

      UniteABattaquer(uTemp,i);

/*
      if(uTemp!=nullptr) {
        auto portee= uTemp->getPortee();
        if(uTemp->getIsCampA()){
          for(int j=i+portee.first; (j<=i+portee.second && j<taille) ; j++){
            auto cible= cases.at(j).get();
            if(cible!=nullptr){
              if(!uTemp->getAsAction1()){
                bool isDead;
                                                          //std::cout << "instance:" << uTemp->getInstance() << '\n';
                                                          //instanceof<Catapulte> (uTemp)){
                if(uTemp->getInstance()=="Catapulte"){
                  std::cout << "cata" << '\n';
                  //Unite* cible2= nullptr;
                  if(j+1<=taille && j+1<i+portee.second) {
                    auto cible2= cases.at(j+1).get();

                    isDead= uTemp->Attaquer(cible2);
                    if(isDead) cases.at(j+1)= Case();
                  } else if(j==i+portee.second) {
                    auto cible2= cases.at(j-1).get();

                    isDead= uTemp->Attaquer(cible2);
                    if(isDead) cases.at(j-1)= Case();
                  }
                }
                isDead= uTemp->Attaquer(cible);

                if(isDead) cases.at(j)= Case();


                uTemp->setAsAction1(true);
                break;
              }
            } else if(j==taille-1){
              std::cout << "caseAttTourAB" << '\n';
              auto isDead= uTemp->Attaquer(&TourB);

              if(isDead) {std::cout << "tour dead" << '\n';}
              uTemp->setAsAction1(true);
              break;
            }
          }//endFor
          //affiche(); //a afficher
        }
      }
*/
    }
  } else {
    //std::cout << "isInCampB" << '\n';


    for(int i=taille-1; i>0; i--){
      auto uTemp= cases.at(i).get();

      UniteBAattaquer(uTemp,i);
/*
      if(uTemp!=nullptr) {
        auto portee= uTemp->getPortee();
        if(!uTemp->getIsCampA()){
          for(int j=i-portee.first; (j>=i-portee.second && j>0); j--){
            auto cible=cases.at(j).get();
            if(cible!=nullptr){
              if(!uTemp->getAsAction1()){
                auto isDead= uTemp->Attaquer(cible);
                if(uTemp->getInstance()=="Catapulte"){//instanceof<Catapulte> (uTemp)){
                  std::cout << "cata" << '\n';
                }

                if(isDead) cases.at(j)= Case();
                break;
              } else if(j==0){
                std::cout << "caseAttTourAB" << '\n';
                auto isDead= uTemp->Attaquer(&TourB);

                if(isDead) {break;}
              }
            }
          }
        }
      }
*/
    }

  }

}
void Terrain::Action2(bool sensAB){

  if(sensAB){
    for(int i=taille-3; i>=0; i--){
      deplacement(sensAB, i, true);
/*
      auto uTemp= cases.at(i).get();
      auto suiv=cases.at(i+1).get();

      if(uTemp!=nullptr && uTemp->getIsCampA())
      if(suiv==nullptr && !(uTemp->getInstance()=="Catapulte" )){//!instanceof<Catapulte> (uTemp)){ //(std::is_base_of<Catapulte, typeid(uTemp).name()>::value)
        uTemp->Avancer();
        cases.at(i+1) =cases.at(i);
        cases.at(i)   =Case();
      }
*/
    }
  } else {
    for(int i=2; i<taille; i++){
      deplacement(sensAB, i, true);

/*
      auto uTemp= cases.at(i).get();
      auto suiv=cases.at(i-1).get();

      if(uTemp!=nullptr && !uTemp->getIsCampA())
      if(suiv==nullptr && !(uTemp->getInstance()=="Catapulte" )){//!instanceof<Catapulte> (uTemp)){ //(std::is_base_of<Catapulte, typeid(uTemp).name()>::value)
        uTemp->Avancer();
        cases.at(i-1) =cases.at(i);
        cases.at(i)   =Case();
      }
*/
    }
  }

}
void Terrain::Action3(bool sensAB){

  if(sensAB) {
    for(int i=taille-2; i>=0; i--){
      auto uTemp= cases.at(i).get();
      if(uTemp!=nullptr) {
        if(!uTemp->getAsAction1() && uTemp->getInstance()=="Catapulte"){
          deplacement(sensAB, i, false);
          /*
          auto uTemp= cases.at(i).get();
          auto suiv=cases.at(i+1).get();

          if(uTemp!=nullptr && uTemp->getIsCampA())
          if(suiv==nullptr){//!instanceof<Catapulte> (uTemp)){ //(std::is_base_of<Catapulte, typeid(uTemp).name()>::value)
            uTemp->Avancer();
            cases.at(i+1) =cases.at(i);
            cases.at(i)   =Case();
          }*/
        }

        if(uTemp->getInstance()=="Fantassin") UniteABattaquer(uTemp, i);
        uTemp->setAsAction1(false);
      }


    }
  }

}

void Terrain::deplacement(bool sensAB, int i, bool expluCata){
  int sens;
  if(sensAB) {sens=1;}
  else {sens=-1;}
  auto uTemp= cases.at(i).get();
  auto suiv=cases.at(i+sens).get();

  if(uTemp!=nullptr && (!uTemp->getIsCampA() ^ sensAB) )
  if(suiv==nullptr && !(expluCata && (uTemp->getInstance()=="Catapulte"))){//!instanceof<Catapulte> (uTemp)){ //(std::is_base_of<Catapulte, typeid(uTemp).name()>::value)
    uTemp->Avancer();
    cases.at(i+sens) =cases.at(i);
    cases.at(i)   =Case();
  }
}
void Terrain::UniteABattaquer(Unite *uTemp,int i){
  if(uTemp!=nullptr) {
    auto portee= uTemp->getPortee();
    if(uTemp->getIsCampA()){
      for(int j=i+portee.first; (j<=i+portee.second && j<taille) ; j++){
        auto cible= cases.at(j).get();
        if(cible!=nullptr){
          if(!uTemp->getAsAction1()){
            bool isDead;
                                                      //std::cout << "instance:" << uTemp->getInstance() << '\n';
                                                      //instanceof<Catapulte> (uTemp)){
            if(uTemp->getInstance()=="Catapulte"){
              std::cout << "cata" << '\n';
              //Unite* cible2= nullptr;
              if(j+1<=taille && j+1<i+portee.second) {
                auto cible2= cases.at(j+1).get();

                isDead= uTemp->Attaquer(cible2);
                if(isDead) cases.at(j+1)= Case();
              } else if(j==i+portee.second) {
                auto cible2= cases.at(j-1).get();

                isDead= uTemp->Attaquer(cible2);
                if(isDead) cases.at(j-1)= Case();
              }
            }

            isDead= uTemp->Attaquer(cible);
            if(isDead) cases.at(j)= Case();


            uTemp->setAsAction1(true);
            break;
          }
        } else if(j==taille-1){
          std::cout << "caseAttTourAB" << '\n';
          auto isDead= uTemp->Attaquer(&TourB);

          if(isDead) {std::cout << "tour dead" << '\n';}
          uTemp->setAsAction1(true);
          break;
        }
      }//endFor
      //affiche(); //a afficher
    }
  }
}
void Terrain::UniteBAattaquer(Unite *uTemp,int i){
  if(uTemp!=nullptr) {
    auto portee= uTemp->getPortee();
    if(!uTemp->getIsCampA()){
      for(int j=i-portee.first; (j>=i-portee.second && j>=0) ; j--){
        auto cible= cases.at(j).get();
        if(cible!=nullptr){
          if(!uTemp->getAsAction1()){
            bool isDead;
                                                      //std::cout << "instance:" << uTemp->getInstance() << '\n';
                                                      //instanceof<Catapulte> (uTemp)){
            if(uTemp->getInstance()=="Catapulte"){
              std::cout << "cata" << '\n';
              //Unite* cible2= nullptr;
              if(j-1>=0 && j-1>i-portee.second) {
                auto cible2= cases.at(j+1).get();

                isDead= uTemp->Attaquer(cible2);
                if(isDead) cases.at(j-1)= Case();
              } else if(j==i-portee.second) {
                auto cible2= cases.at(j+1).get();

                isDead= uTemp->Attaquer(cible2);
                if(isDead) cases.at(j+1)= Case();
              }
            }

            isDead= uTemp->Attaquer(cible);
            if(isDead) cases.at(j)= Case();

            uTemp->setAsAction1(true);
            break;
          }
        } else if(j==0){
          std::cout << "caseAttTourAB" << '\n';
          auto isDead= uTemp->Attaquer(&TourA);

          if(isDead) {std::cout << "tour dead" << '\n';}
          uTemp->setAsAction1(true);
          break;
        }
      }//endFor
      //affiche(); //a afficher
    }
  }
}
