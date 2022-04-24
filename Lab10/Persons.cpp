#include "Persons.h"

Man::Man(std::string name, bool hair , bool beard ) : Person(name, true, hair), _beard(beard){} 

Man::~Man() {
  print();
  std::cout<<" idzie na piwko"<<std::endl;
}


void Man::print()const {

  std::cout<< _name << (_haircut ? " nieobciety" : " obciety" )<<" i " << (_beard ? "nieogolony": "ogolony"); 

}

bool Man::done()const {

  if(_haircut && _beard)
  {
    return false;
  }else{
    return true;
  }

}

void Man::shave(){

  if(_beard == true)
  {
    _beard = false;
  }else {
    std::cout<<std::endl;
    std::cout<<"!!!Klient juz ogolony!!!";
  }

}

Woman::Woman(std::string name, bool hair, bool makeup) : Person(name, false, hair), _makeup(makeup) {}

Woman::~Woman() {
  print();
  std::cout<<" idzie na zakupy"<<std::endl;
}


void Woman::print()const {

  std::cout<< _name << (_haircut ? " nieobcieta" : " obcieta")<<" i "<< (_makeup ? "nieumalowana": "umalowana"); 

}


bool Woman::done()const {

  if(_haircut && _makeup)
  {
    return false;
  }else{
    return true;
  }

}

void Woman::makeup(){

  if(_makeup == true)
  {
    _makeup = false;
  }else {
    std::cout<<std::endl;
    std::cout<<"!!!Klientka juz umalowana!!!";
  }

}

void Man::makeup(){

}
void Woman::shave() {

}