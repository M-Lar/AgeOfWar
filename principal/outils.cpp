#include <iostream>
#include <cstdlib>
#include <cmath>
#include <type_traits>

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

std::string into_string(const int i, int nbChiffre= 4){
  std::string res="";
  /*if(i<100) {res+=" ";
  if(i<10) res+=" ";}
  //std::cout << "test:" << res+std::to_string(i) << '\n';
  return res+std::to_string(i)+" "; //printf("%4d", 123);;*/
  int limite=pow(10,nbChiffre);
  for(int j=10; j<limite; j=j*10){
    if(i<j) res+=" ";
  }
  return res+std::to_string(i);
}
#endif
