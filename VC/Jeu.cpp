#include <iostream>
#include <cstdlib>

#include <chrono>
#include <thread>

#include "Jeu.hpp"


void Jeu::affiche(){
  std::this_thread::sleep_for(std::chrono::milliseconds(240));//45));

  std::system("clear");
  std::string nomJoueur= "Joueur ";

//ligne 0
  for(int i=0; i<(int)((getTaille()*4+6*2) -16)/2; i++) {std::cout << " ";}
  if(isTourA) std::cout << colorCyan << "Tour de Joueur 1" << '\n';
  else        std::cout << colorMagenta << "Tour de Joueur 2" << '\n';
  std::cout << colorReset;

//ligne 1
  std::cout /*<< colorCyan*/ << nomJoueur << "1";
  for(int i=0; i<(int)(getTaille()*4+6*2 -(nomJoueur.size()+1)*2); i++){ std::cout << " "; }
  std::cout /*<< colorMagenta*/ << nomJoueur << "2";
  std::cout << std::endl;

//ligne 2
  std::cout << colorYellow;
  std::cout << into_string(getArgentA(), 5)<< " p ";
  for(int i=0; i<(int)(getTaille()*4+6*2 -(3+5)*2)-1; i++){ std::cout << " "; }
  std::cout << into_string(getArgentB(), 5)<< " p ";
  std::cout << std::endl;
  std::cout << colorReset;

//affiche Terrain
  this->Terrain::affiche();
}
void Jeu::init(){
  std::system("clear");
  std::cout << '\n';
  for(int i=0; i<(int)((getTaille()*4+6*2) -31)/2; i++){std::cout << " ";}
  std::cout << "-- Bienvenue dans Age Of War --" << "\n\n";

  char c;
  std::cout << "Vouler vous jouer en Multijoueur ?" << "(y/n)";
  std::cout << '\n';
  c= getEntree({'y','n'});

  if(c=='n') bot=true;

  std::cout << "Vouler vous charger une sauvgarde ?" << "(y/n)";
  std::cout << '\n';
  c= getEntree({'y','n'});

  if(c=='y') load();
}

bool Jeu::achatUnite(char u){
  if(u=='f') return achat<Fantassin>(isTourA);
  else if(u=='a') return achat<Archer>(isTourA);
  else if(u=='c') return achat<Catapulte>(isTourA);
  else return false;
}
bool Jeu::achatUnite(){
  std::cout << "Voulez vous acheter une unite ?" << "(f/a/c) (passer:p)";
  std::cout << '\n';

  char c;

  if(bot && !isTourA) c= decisionBot();
  else    c= getEntree({'f','c','a','p','s'});



  if(c=='q') return false;
  else if(c=='p') return true;
  else if(c=='s') {save(); return true;}
  else {
    achatUnite(c);
    return true;
  }
}


void Jeu::jouer(){
  init();

  int tourDeJeu=0;
  bool victoire=false;
  bool jeuEnCour=true;
  while(jeuEnCour && tourDeJeu<=maxTourDeJeu && !victoire){
    donnerArgent(isTourA);


    victoire=victoire|| Action1(isTourA); affiche();
                        Action2(isTourA); affiche();
    victoire=victoire|| Action3(isTourA); affiche();

    jeuEnCour= achatUnite(); affiche();


    tourDeJeu++;
    isTourA= !isTourA;
  }
  affiche();

  if(!jeuEnCour){
    std::cout << "Vouler vous sauvgarder ?" << "(y/n)";
    std::cout << '\n';
    auto c= getEntree({'y','n'});

    if(c=='y') save();
  }
  else if(victoire){
    std::cout << '\n' << "Bravo" << '\n';
  }

  std::cout << "  Bonne journée" << '\n';

}

char Jeu::decisionBot(){
  if(achat<Catapulte>(isTourA)) return true;
  else {
    int alea= rand() % 3+1;

    if(alea==1) return achat<Archer>(isTourA);
    if(alea==2) return achat<Fantassin>(isTourA);
  }
  return false;
}

void Jeu::save(){

}
void Jeu::load(){

}
