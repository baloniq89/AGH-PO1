#pragma once

#include <iostream>
#include <vector>
#include <functional>

class FilterCriteria {

  public:

    void add(std::function<bool(int)> funkcja){
      _vecFun.push_back(funkcja);
    }//funkcja dodajaca podany filrtr na koniec wektora funkcji filtrow

    int size()const { return _vecFun.size();}//funkcja zwracająca rozmiar vectora filtrow

    std::function<bool(int)> get(int i){
      return _vecFun[i];
    }//funkcja zwracajaca element funkcyjny znajdujacy sie na podanej pozycji i w wektorze filtrow 


  private:
      std::vector<std::function<bool(int)>> _vecFun;//wektor elementow funkcyjnych(filtrow)
};