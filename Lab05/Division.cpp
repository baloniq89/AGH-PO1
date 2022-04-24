#include "Division.h"


Division::Division(double licznik, double mianownik) : _l(licznik) , _m(mianownik){}

void Division::print() const{
  std::cout <<_l << " / " << _m;
}

double Division::eval() const{
  return _l / _m;
}