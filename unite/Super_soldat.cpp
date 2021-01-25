#include <iostream>
#include <cstdlib>

#include "Super_soldat.hpp"


void Super_soldat::print(int i){
  if(isCampA) {
    if(i==2)      std::cout<< "Ô  /";
    else if(i==1) std::cout<< "|-/ ";
    else if(i==0) std::cout<< "|   ";
    else if(i==-1) std::cout<< into_string(pv,3)+" ";
    else std::cout<< "    ";
  } else {
    if(i==2)      std::cout<< "\\  Ô";
    else if(i==1) std::cout<< " \\-|";
    else if(i==0) std::cout<< "   |";
    else if(i==-1) std::cout<< into_string(pv,3)+" ";
    else std::cout<< "    ";
  }
}
