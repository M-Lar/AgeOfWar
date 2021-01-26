#include <iostream>
#include <cstdlib>
#include <cmath>
#include <type_traits>
#include <vector>
#include <algorithm>

#ifndef outils
#define outils
/*
template<class U, class S>
bool instanceof(const S*) {
  //std::cout << "inInstOf" << '\n';
  //std::cout << U.name() << "|" << S.name() << '\n';
   return std::is_base_of<U, S>::value;
}
*/

std::string into_string(const int i, int nbChiffre= 4, bool invers= false){
  std::string res="";
  int limite=pow(10,nbChiffre);


  for(int j=10; j<limite; j=j*10){
    if(i<j) res+=" ";
  }
  if(invers) return std::to_string(i)+res;
  return res+std::to_string(i);
}

char getEntree(std::vector<char> listeEntresPermises){
  std::string entre;

  do{
    std::cout << "entre: ";
    std::cin >> entre;
    //std::tolower(entre);
    std::transform(entre.begin(), entre.end(), entre.begin(),
    [](char c){ return std::tolower(c); });

    if(!entre.empty()){
      for(char cl : listeEntresPermises){//size_t i=0; i<listeEntresPermises.size(); i++){
        if(entre.front()=='q' || entre.front()==cl)//listeEntresPermises.at(i))
          return entre.front();
      }
    }
  }while(true);

  return 'q';
}

#endif
