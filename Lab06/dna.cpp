#include "dna.h"

DNA::DNA(const RNA & rna1, const RNA & rna2)
{
 _chains[0] = rna1;
 _chains[1] = rna2;
}

std::ostream & operator << (std::ostream & out, const DNA & dna)
{
  
   out<< dna._chains[0];

   for ( int i=0; i < dna._chains[0].get_RNA().size(); i++)
    {
      out << "| ";
    }
    out<<std::endl;
    out<<dna._chains[1];
    
        
    return out;
}