#include "Operation.h"

void operator >>= (const std::string & text, const Operation & dzialanie) {

  std::cout<< text<< " ";
  dzialanie.print();
  std::cout<<" " << text<<std::endl;

}