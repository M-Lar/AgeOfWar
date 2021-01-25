#include <iostream>
#include <cstdlib>

#include "Super_soldat.hpp"


void Super_soldat::print(int i){
  if(i==-1) std::cout<< into_string(pv,3)+" ";
  else if(isCampA) {
    if(i==2)      std::cout<< "Ö  /";
    else if(i==1) std::cout<< "|-/ ";
    else if(i==0) std::cout<< "|   ";
    else std::cout<< "    ";
  } else {
    if(i==2)      std::cout<< "\\  Ö";
    else if(i==1) std::cout<< " \\-|";
    else if(i==0) std::cout<< "   |";
    else std::cout<< "    ";
  }
}
