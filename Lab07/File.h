#pragma once

#include "FileBase.h"


class File : public FileBase{

  public:
      File(std::string name, int size = 0) : FileBase(name), _size(size){}

      ~File()
      {
       std::cout<<"---Destruktor File: " << getName() <<std::endl;
      }
      

      std::ostream& print(std::ostream & stm, int spaces=0) const override
      {
        for(int i = 0; i< spaces; i++)
        {
         stm<< " ";
        }
        return stm<<_name << " ("<<_size<<") "<<std::endl;
      }

      FileBase* makeCopy() const override {
        return new File(*this);
      }



  protected:
      int _size;

};