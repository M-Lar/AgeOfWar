#include <iostream>
#include <cstdlib>

#include <chrono>
#include <thread>

#include "Jeu.hpp"


void Jeu::affiche(){
  std::this_thread::sleep_for(std::chrono::milliseconds(45));//180));

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
  std::cout << "Solo ou Multijoueur ?" << "(s/m)";
  std::cout << '\n';
  c= getEntree({'s','m'});

  if(c=='s') multi=false;

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

  char c= getEntree({'f','c','a','p','s'});

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
  while(jeuEnCour && tourDeJeu<=maxTourDeJeu){
    donnerArgent(isTourA);

    Action1(isTourA); affiche();
    Action2(isTourA); affiche();
    Action3(isTourA); affiche();

    jeuEnCour= achatUnite(); affiche();


    tourDeJeu++;
    isTourA= !isTourA;
  }
  affiche();

  if(!jeuEnCour){
    std::cout << "Vouler vous sauvgarder ?" << "(Y/N)";
    std::cout << '\n';
    auto c= getEntree({'y','n'});

    if(c=='y') save();
  }
  std::cout << "  Bonne journée" << '\n';

}

void Jeu::save(){

}
void Jeu::load(){

}
