#include <iostream>
#include <cstdlib>
#include <fstream>

#include <chrono>
#include <thread>

#include "Jeu.hpp"


void Jeu::affiche(){
  std::this_thread::sleep_for(std::chrono::milliseconds(45));//200));

  std::system("clear");
  std::string nomJoueur= "Joueur ";

//ligne 0
  for(int i=0; i<(int)((getTaille()*4+6*2) -16)/2; i++) {std::cout << " ";}
  if(isTourA) std::cout << colorCyan << "Tour de Joueur 1";
  else        std::cout << colorMagenta << "Tour de Joueur 2";
  for(int i=0; i<(int)((getTaille()*4+6*2 -16-6-4-1)/2); i++) {std::cout << " ";}
  std::cout << colorBlack << into_string(numTourCourant, 6) << '\n';
  std::cout << colorReset;

//ligne 1
  std::cout /*<< colorCyan*/ << nomJoueur << "1";
  for(int i=0; i<(int)(getTaille()*4+6*2 -(nomJoueur.size()+1)*2); i++){ std::cout << " "; }
  std::cout /*<< colorMagenta*/ << nomJoueur << "2";
  std::cout << std::endl;

//ligne 2
  std::cout << colorYellow;
  std::cout << into_string(getArgentA(), 5)<< " p ";
  for(int i=0; i<(int)(getTaille()*4+6*2 -(3+5)*2); i++){ std::cout << " "; }
  std::cout << into_string(getArgentB(), 5)<< " p ";
  std::cout << std::endl;
  std::cout << colorReset;

//affiche Terrain
  this->Terrain::affiche();
}
bool Jeu::init(bool &asLoad){
  std::system("clear");
  std::cout << '\n';
  for(int i=0; i<(int)((getTaille()*4+6*2) -31)/2; i++){std::cout << " ";}
  std::cout << "-- Bienvenue dans Age Of War --" << "\n\n";

  char c;

  {//sauvegarde
    std::cout << "Vouler vous charger une sauvegarde ?" << "(y/n)";
    std::cout << '\n';
    c= getEntree({'y','n'});

    if(c=='y') {
      load();
      asLoad=true;
      return true;}
    else if(c=='q') return false;
  }

  {//multi
    std::cout << "Vouler vous jouer en Multijoueur ?" << "(y/n)";
    std::cout << '\n';
    c= getEntree({'y','n'});

    if(c=='n') bot=true;
    else if(c=='q') return false;
  }







  return true;
}

bool Jeu::achatUnite(char u){
  if(u=='f') return acheter<Fantassin>(isTourA);
  else if(u=='a') return acheter<Archer>(isTourA);
  else if(u=='c') return acheter<Catapulte>(isTourA);
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
  bool asLoad;
  if(!init(asLoad)) {
    std::cout << "Partie interrompue" << '\n';
    return;
  }

  bool victoire=false;
  bool jeuEnCour=true;

  if(asLoad) {
    affiche();
    jeuEnCour= achatUnite(); affiche();
    if(!isTourA) numTourCourant++;
    isTourA= !isTourA;
  }
  while(jeuEnCour && numTourCourant<=maxTourDeJeu){

    donnerArgent(isTourA);


    victoire=victoire|| Action1(isTourA); affiche();
                        Action2(isTourA); affiche();
    victoire=victoire|| Action3(isTourA); affiche();
    if(victoire) break;


    jeuEnCour= achatUnite(); affiche();


    if(!isTourA) numTourCourant++;
    isTourA= !isTourA;
  }
  affiche();

  if(!jeuEnCour){
    std::cout << "Vouler vous sauvegarder ?" << "(y/n)";
    std::cout << '\n';
    auto c= getEntree({'y','n'});

    if(c=='y') save();
  }
  else if(victoire){
    for(int i=0; i<(int)((getTaille()*4+6*2) -14)/2; i++) {std::cout << " ";}
    std::cout << colorYellow << "Bravo Joueur ";
    if(isTourA) std::cout << colorCyan << "1";
    else        std::cout << colorMagenta << "2";
    std::cout << colorReset << '\n';
  }

  std::cout << '\n' << "Bonne journée" << '\n';

}

char Jeu::decisionBot(){
  if(acheter<Catapulte>(isTourA)) return 'c';
  else {
    int alea= rand() % 3+1;

    if(alea==1 && acheter<Archer>(isTourA)) return 'a';
    if(alea==2 && acheter<Fantassin>(isTourA)) return 'f';
  }
  return false;
}

void Jeu::save(){
    std::string const fichierSauvegarde("../jeu/save.txt");
    std::ofstream flux(fichierSauvegarde.c_str());

    if(flux) {

        //donnees init Terrain
        flux << " taille:" << getTaille(); //taille
        flux << ", pvA:" << getPvA() << ", pvB:" << getPvB(); //pv tour A et B
        flux << ", aA:" << getArgentA() << ", aB:" << getArgentB(); //argentA argentB

        //donnees init Jeu
        flux << ", mTJ:" << maxTourDeJeu;
        flux << ", nT:" << numTourCourant;
        flux << ", isTA:" << isTourA;
        flux << ", vsBot:" << bot;

        //Etat Terrain
        int nbUniteCree;
        flux << ", ter:" << getTerrain(nbUniteCree);
        flux << ", nbUC:" << nbUniteCree;

    } else {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
void Jeu::load(){
   std::ifstream fichier("../jeu/save.txt");

   if(fichier) {
      std::string ligne;
      getline(fichier, ligne);

      /*
      bool bonneLigne=false;
      std::string nomSave= nonValable();
      while(getline(fichier, ligne) && !bonneLigne){
         auto nomLigne = ligne.substr (0,ligne.find(" "));

         if(nomLigne==nomSave) bonneLigne=true;
         std::cout << ligne << std::endl;
      }
      */

      //Jeu(int mTJ=maxTourDeJeu, int t=12, int pvTour=100, int argent=8): Terrain(t, pvTour, argent){ Jeu::maxTourDeJeu=mTJ; }
      {//lecture ligne

        size_t posV= ligne.find(",");
        size_t trouv= ligne.find("taille")+7;
        int t= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("pvA")+4;
        int pvA= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("pvB")+4;
        int pvB= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("aA")+3;
        int aA= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("aB")+3;
        int aB= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("mTJ")+4;
        int mTJ= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("nT")+3;
        int nT= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("isTA")+5;
        int isTA= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("vsBot")+6;
        int vsBot= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);
        posV= ligne.find(",",posV+1,1);

        trouv= ligne.find("ter")+4;
        std::string ter=ligne.substr (trouv,posV-trouv);

        trouv= ligne.find("nbUC")+5;
        int nbUC= std::stoi(ligne.substr (trouv),nullptr);


        //std::cout << "ligne:" << ligne << '\n';
        //std::cout << "ligne: taille:" << t << ", pvA:" << pvA << ", pvB:" << pvB << ", aA:" << aA << ", aB:" << aB << ", mTJ:" << mTJ << ", nT:" << nT << ", isTA:" << isTA << ", vsBot:" << vsBot << ", ter:" << ter << ", nbUC:" << nbUC << '\n';

        reset(mTJ, nT, isTA, vsBot, t, pvA, pvB, aA, aB, ter, nbUC);
      }
   } else {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
   }
}

void Jeu::reset(int mTJ, int nT, bool isTA, bool vsBot, int t, int pvA, int pvB, int aA, int aB, std::string ter, int nbUC){
  Terrain::reset(t, pvA, pvB, aA, aB, std::make_pair(ter, nbUC));
  maxTourDeJeu=mTJ;
  numTourCourant=nT;
  isTourA=isTA;
  bot=vsBot;
}
