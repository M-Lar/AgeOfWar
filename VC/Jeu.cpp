#include <iostream>
#include <cstdlib>

#include "Jeu.hpp"


void Jeu::affiche(){
  std::string nomJoueur= "Joureur ";
//ligne 0
  std::cout << "  Tour de " << (isTourA?"A":"B") << '\n';

//ligne 1
  std::cout /*<< colorCyan*/ << nomJoueur << "1";
  for(int i=0; i<(int)(getTaille()*4+6*2 -(nomJoueur.size()+1)*2); i++){ std::cout << " "; }
  std::cout /*<< colorMagenta*/ << nomJoueur << "2";
  std::cout << std::endl;

//ligne 2
  std::cout << colorYellow;
  std::cout << into_string(argentA, 5)<< " p ";
  for(int i=0; i<(int)(getTaille()*4+6*2 -(3+5)*2)-1; i++){ std::cout << " "; }
  std::cout << into_string(argentB, 5)<< " p ";
  std::cout << std::endl;
  std::cout << colorReset;

//affiche Terrain
  this->Terrain::affiche();
}


template <class U>
bool Jeu::achat(){
  U* unit= new U(isTourA, (isTourA?0:getTaille()-1));
  auto prixU= unit->getPrix();
  int *budjet;

  if(isTourA) budjet=&argentA;
  else budjet=&argentB;

  if((*budjet)>=prixU){
    payer(budjet, prixU);
    add<U>(isTourA);
    return true;
  }
  return false;
}
bool Jeu::achatUnite(char u){
  if(u=='f') return achat<Fantassin>();
  else if(u=='a') return achat<Archer>();
  else if(u=='c') return achat<Catapulte>();
  else return false;
}

char Jeu::getEntree(std::vector<std::string> entre){
  entre.size();
  return 'r';
}

void Jeu::jouer(){
  //m.init();
  std::cout << '\n';
  for(int i=0; i<(int)((getTaille()*4+6*2) -31)/2; i++){std::cout << " ";}
  std::cout << "-- Bienvenue dans Age Of War --" << "\n\n";


  //std::string clavier;
  //std::cin>>clavier;

  int tourDeJeu=0;
  //std::cout << "avWhile" << '\n';
  while(jeuEnCour && tourDeJeu<=maxTourDeJeu){
    //std::cout << "inWhile ";
    if(isTourA) argentA+=8;
    else argentB+=8;

    affiche();

    Action1(isTourA);
    Action2(isTourA);
    Action3(isTourA);

    achatUnite('f');
    affiche();


    tourDeJeu++;
    isTourA= !isTourA;
  }
  affiche();

}
