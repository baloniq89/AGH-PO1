#include "Dir.h"


Dir::Dir(std::string name) : FileBase(name) {}




Dir::~Dir() 
{
  std::cout<<"Destruktor Dir: "<< _name <<std::endl;

  for( auto &f : _inDir)
  {
    if(f)
    {
      delete f;
      f = nullptr;
    }
  }
}

std::ostream& Dir::print(std::ostream &stm, int spaces) const {
  
  for(int i = 0; i< spaces; i++) std::cout<<" ";
    spaces += 2;
    stm<<_name<<" (dir)" << std::endl;
    for( auto f: _inDir)
    {
      f -> print(stm, spaces);
    }
  return stm;

}

void Dir::operator+=(FileBase * newObject){
  _inDir.push_back(newObject);
}

void Dir::operator -=(std::string delF)
{
  for(int i=0; i< _inDir.size(); i++)
  {
    if( _inDir[i]->getName() == delF)
    {
      delete _inDir[i];
      return ;
    }
  }
}

FileBase* Dir::makeCopy() const{
  return new Dir(*this);
} 

void Dir::copy(FileBase *copyEl){

  *this += copyEl->makeCopy();
}

FileBase * Dir::get(std::string name){



  return nullptr;

}

Dir* Dir::getDir(std::string name)const{

  return nullptr;
}