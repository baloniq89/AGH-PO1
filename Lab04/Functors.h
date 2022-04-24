#pragma once

#include "List.h"
#include <iostream>
#include <functional>



namespace Functors {

  class DivisibleBy {
    
    public:
        DivisibleBy() = default;//konstruktor domyślny

        DivisibleBy(int x) : _divider(x){}//konstruktor jednoargumentowy

        ~DivisibleBy() = default;//destruktor domyślny

        bool operator()(int liczba)const {
          return !(liczba % _divider);
        }//przeladowany operator () ktory sprawdza podzielnosc podanej liczby przez _divider


    private:
        int _divider;//wartosc liczby przez ktora bedzie sprawdzana podzielnosc
    


  };

  class LowerThan {

    public:
      LowerThan() = default;//kostruktor domyślny

      LowerThan(int x) : _compare(x){}//konstruktor jednoargumentowy 

      ~LowerThan() = default;//destruktor domyślny

        bool operator()(int liczba)const{
          return (liczba < _compare);
        }//przeladowany operator () ,ktory sprawdza czy podana liczba jest mniejsza od _compare



    private:
        int _compare;//wartosc liczby do porownania
  };

}
