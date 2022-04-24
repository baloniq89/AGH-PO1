#pragma once

#include "Data.h"

//Klasa Table reprezentuje wydatki w dniach tygodnia
class Table {

  public:
      void print() const;//wypisywanie tabeli

      void operator +=(const Data &);//dodawanie wydatkow do tabeli
      Table& sort(int);
      Table& sortBy(std::function<bool(const Data&, const Data&)>);





  private:
      std::vector<Data> _day;
      

      
};

bool cmp(const Data &, const Data &, int);//funkcja, ktora porowuje dni po podanej kolumnie 