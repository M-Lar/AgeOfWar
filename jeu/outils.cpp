#include <iostream>
#include <cstdlib>
#include <cmath>
#include <type_traits>
#include <vector>
#include <algorithm>

#include <chrono>



#ifndef outils
#define outils


std::string into_string(const int i, int nbChiffre= 4, bool invers= false){
  std::string res="";
  int limite=pow(10,nbChiffre);


  for(int j=10; j<limite; j=j*10){
    if(i<j) res+=" ";
  }
  if(invers) return std::to_string(i)+res;
  return res+std::to_string(i);
}

char getEntree(std::vector<char> listeEntresPermises, bool include=true){
  std::string entre;

  do{
    std::cout << "entre: ";
    std::cin >> entre;
    //std::tolower(entre);
    std::transform(entre.begin(), entre.end(), entre.begin(),
    [](char c){ return std::tolower(c); });

    if(!entre.empty()){
      for(char cl : listeEntresPermises){//size_t i=0; i<listeEntresPermises.size(); i++){
        if(entre.front()=='q' || ((entre.front()==cl) ^ !include))//listeEntresPermises.at(i))
          return entre.front();
      }
    }
  }while(true);

  return 'q';
}

std::string getNomValable(){
  //std::cout << getEntree({'\n',' ','\\'}, false) << '\n';
  return "";
}

#endif
