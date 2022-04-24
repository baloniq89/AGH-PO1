#include "Exponentiation.h"

Exponentiation::Exponentiation(double base, double exp) : _x(base), _pot(exp){}

void Exponentiation::print() const{
  
  std::cout<<_x << " ^ "<<_pot;
}

double Exponentiation::eval() const{
  return std::pow(_x, _pot);
}