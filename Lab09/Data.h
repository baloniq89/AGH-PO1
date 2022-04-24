#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <numeric>


class Sum;
//klasa Data reprezentuje wydatki w danym dniu
class Data {

  public:
      friend Sum sumData(const Data&);

      Data(std::string, std::vector<double>);
      void print()const;
      double operator [](unsigned)const;
      int size() const;
      




  private:
      std::vector<double> _exp;
      std::string _dayName;
};