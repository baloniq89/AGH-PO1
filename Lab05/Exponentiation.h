#pragma once
#include "Operation.h"
#include <cmath>


class Exponentiation : public Operation{

  public:
      Exponentiation(double , double );// kosntruktor dwuargumentowy

      void print()const override;// funkcja wypisujaca operacje potegowania , _x ^ _pot

      double eval () const override;// funkcja zwracająca wynik dzialania _x ^ _pot




  private:
      double _x;
      double _pot;

};