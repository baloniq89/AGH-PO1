#pragma once

#include "Operation.h"



class Division : public Operation{

  public:
      Division(double , double );//konstruktor dwuargumentowy

      void print() const override;// funkcja wypisujaca operacje dzielenia _l / _m

      double eval () const override;//funkcja zwracajaca wynik dzielenia _l / _m

  private:
      double _l;
      double _m;
      
};