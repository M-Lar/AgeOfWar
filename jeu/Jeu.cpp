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
bool Jeu::init(){
  std::system("clear");
  std::cout << '\n';
  for(int i=0; i<(int)((getTaille()*4+6*2) -31)/2; i++){std::cout << " ";}
  std::cout << "-- Bienvenue dans Age Of War --" << "\n\n";

  char c;
  {//multi
    std::cout << "Vouler vous jouer en Multijoueur ?" << "(y/n)";
    std::cout << '\n';
    c= getEntree({'y','n'});

    if(c=='n') bot=true;
    else if(c=='q') return false;
  }

  {//sauvegarde
    std::cout << "Vouler vous charger une sauvgarde ?" << "(y/n)";
    std::cout << '\n';
    c= getEntree({'y','n'});

    if(c=='y') load();
    else if(c=='q') return false;
  }

  //std::string clav; std::cin >> clav;
  //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
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
  if(!init()) {
    std::cout << "Partie interrompue" << '\n';
    return;
  }

  //int tourDeJeu=1;
  bool victoire=false;
  bool jeuEnCour=true;
  while(jeuEnCour && numTourCourant<=maxTourDeJeu){
    isTourA= !isTourA;
    if(!isTourA) numTourCourant++;

    donnerArgent(isTourA);


    victoire=victoire|| Action1(isTourA); affiche();
                        Action2(isTourA); affiche();
    victoire=victoire|| Action3(isTourA); affiche();
    if(victoire) break;


    jeuEnCour= achatUnite(); affiche();

  }
  affiche();

  if(!jeuEnCour){
    std::cout << "Vouler vous sauvgarder ?" << "(y/n)";
    std::cout << '\n';
    auto c= getEntree({'y','n'});

    if(c=='y') save();
  }
  else if(victoire){
    for(int i=0; i<(int)((getTaille()*4+6*2) -14)/2; i++) {std::cout << " ";}
    std::cout << colorYellow << "Bravo " << (isTourA?"Joueur 1":"Joueur 2") << colorReset << '\n';
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
//*
    std::string const fichierSauvegarde("../jeu/save.txt");
    std::ofstream flux(fichierSauvegarde.c_str());

    if(flux) {
        //flux << getNonValable();

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
        flux << ", ter:" << getTerrain();

    } else {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
//*/
}
void Jeu::load(){
//*
   std::ifstream fichier("../jeu/save.txt");

   if(fichier) {
      //L'ouverture s'est bien passée, on peut donc lire

      std::string ligne; //Une variable pour stocker les lignes lues
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

      /*
      //donnees init Terrain
      flux << " taille:" << getTaille(); //taille
      flux << " pvA:" << getPvA() << " pvB:" << getPvB(); //pv tour A et B
      flux << " aA:" << getArgentA() << " aB:" << getArgentB(); //argentA argentB

      //donnees init Jeu
      flux << " mTJ:" << maxTourDeJeu;
      flux << " nT:" << numTourCourant;
      flux << " isTA:" << isTourA;
      flux << " vsBot:" << bot;

      //Etat Terrain
      flux << getTerrain();
      */
      //Jeu(int mTJ=maxTourDeJeu, int t=12, int pvTour=100, int argent=8): Terrain(t, pvTour, argent){ Jeu::maxTourDeJeu=mTJ; }
      {

        size_t posV= ligne.find(",");
        size_t trouv= ligne.find("taille")+7;
        int t= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("pvA")+4;
        posV= ligne.find(",",posV+1,1);
        int pvA= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);


        trouv= ligne.find("pvB")+4;
        posV= ligne.find(",",posV+1,1);
        int pvB= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("aA")+3;
        posV= ligne.find(",",posV+1,1);
        int aA= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("aB")+3;
        posV= ligne.find(",",posV+1,1);
        int aB= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("mTJ")+4;
        posV= ligne.find(",",posV+1,1);
        int mTJ= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("nT")+3;
        posV= ligne.find(",",posV+1,1);
        int nT= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("isTA")+5;
        posV= ligne.find(",",posV+1,1);
        int isTA= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("vsBot")+6;
        posV= ligne.find(",",posV+1,1);
        int vsBot= std::stoi(ligne.substr (trouv,posV-trouv),nullptr);

        trouv= ligne.find("ter")+4;
        std::string ter=ligne.substr (trouv);

        //std::cout << "ligne:" << ligne << '\n' << '\n';
        //std::cout << t << " pvA:" << pvA << " pvB:" << pvB << " aA:" << aA << " aB:" << aB << " mTJ:" << mTJ << " nT:" << nT << " isTA:" << isTA << " vsBot:" << vsBot << " " << ter << '\n';
        //100 100 100 100 100 100 0 0 0 0 100 22 14 100 3 1 0 __f________
        //std::cout << "fin" << '\n';

        reset(mTJ, nT, isTA, vsBot, t, pvA, pvB, aA, aB, ter);
      }
   } else {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
   }
   //std::this_thread::sleep_for(std::chrono::milliseconds(30000));
   //std::string test; std::cin >> test;
//*/

}

void Jeu::reset(int mTJ, int nT, bool isTA, bool vsBot, int t, int pvA, int pvB, int aA, int aB, std::string ter){
  Terrain::reset(t, pvA, pvB, aA, aB, ter);
  maxTourDeJeu=mTJ;
  numTourCourant=nT;
  isTourA=isTA;
  bot=vsBot;
}
