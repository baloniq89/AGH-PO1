#pragma once
#include "rna.h"
#include <string>

class Virus {

  public:
      Virus() : _age(0), _chainRNA(nullptr){}
      Virus(std::string);
      Virus(Virus &);
      Virus(Virus &&);
      ~Virus() = default;

      int get_age()const;
      std::string get_name()const;
      RNA * get_RNA();

      void set_RNA(const std::vector<Nukleotyp> lancuch){ _chainRNA = new RNA(lancuch);}

  private:
      RNA *_chainRNA;
      std::string _name;
      int _age;
};