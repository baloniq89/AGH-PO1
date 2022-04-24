#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include "Functors.h"
#include "FilterCriteria.h"

class List {

  public:
      List() = default;//konstruktor domyślny

      ~List() {_array.clear();}//destruktor czyszczący liste

      void insert(int);//dodaje podane elementy do listy

      void print(std::string = "")const;//wypisuje prefix podany jakoa argument,a nastepnie elementy listy

      

      int& operator [](int);//zwraca referencje do elementu znajdujacego się pod podanym indeksem

      List filter(std::function <bool(int)>);//tworzy nowa liste, ktora zwiera elementy z listy oryginalnej ,ale tylko te ,ktore przeszly przez podany filtr



  private:
      std::vector<int> _array;//wektor elemntow listy


};