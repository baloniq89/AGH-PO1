#pragma once 

#include "Data.h"

//klasa sumujaca wydatki
class Sum {

  public:
      
      Sum(double value) : _suma(value){}//konstruktor jednoargumentowy
      void operator () (double);//metoda dodajace podana wartosc do sumy
      double value()const;






  private:
      double _suma;

};
