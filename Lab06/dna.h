#pragma once


#include "rna.h"
#include <iostream>

class DNA : public RNA {

  public:
      DNA() = default;
      DNA(const RNA &, const RNA &);
      friend std::ostream& operator <<(std::ostream & out, const DNA & dna);
      



  private:
      RNA _chains[2];

};