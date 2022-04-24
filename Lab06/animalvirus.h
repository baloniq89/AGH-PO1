#pragma once

#include "virus.h"

class AnimalVirus : public Virus{

  public:
      AnimalVirus(std::string, std::string, const std::vector<Nukleotyp>);
      AnimalVirus(AnimalVirus & );
      AnimalVirus(AnimalVirus  &&);

      AnimalVirus operator =(AnimalVirus &);
      AnimalVirus operator = (AnimalVirus &&);

      std::string get_animal_host();
  private:
      std::string _animal;
}