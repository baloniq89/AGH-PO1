#pragma once

#include "Persons.h"

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>


class VectorQ {

  public:
      void add(std::unique_ptr<Person> newClient);
      void print(std::string)const;

      std::vector<Woman*> getWomen()const;
      void countNames()const;
      void haircut(std::string);
      void haircut();
      void shave(std::string);
      void shave();




  private:
      std::vector<std::unique_ptr<Person>> _queue;
};