#include "virus.h"

Virus::Virus(std::string nazwa) : _name(nazwa), _age(0), _chainRNA(nullptr){}

Virus::Virus(Virus &copyVirus){

  _name = copyVirus._name;
  _age = 0;
  copyVirus._age += 1;

  _chainRNA = new RNA(copyVirus._chainRNA->get_RNA());

}

Virus::Virus(Virus && otherVirus) : _name(std::__exchange(otherVirus._name,"")), _age(std::__exchange(otherVirus._age,0)), _chainRNA(std::__exchange(otherVirus._chainRNA,nullptr)){

  _chainRNA ->mutate();
}

int Virus::get_age()const{

  return _age;
}

std::string Virus::get_name() const{

  return _name;
}

RNA * Virus::get_RNA(){
  return _chainRNA;
}