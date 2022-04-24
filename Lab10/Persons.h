#pragma once

#include "Person.h"


class Man : public Person{

  public:
      explicit Man(std::string name, bool hair = true, bool beard = true);
      ~Man();

      void print() const override;
      bool done() const override;
      void makeup() override;
      void shave() override;


  private:
      bool _beard;
};

class Woman : public Person{

  public:
      explicit Woman(std::string name, bool hair = true, bool makeup = true);
      ~Woman() ;

      void print()const override;
      bool done() const override;
      void makeup() override;
      void shave() override;


  private:
      bool _makeup;
};