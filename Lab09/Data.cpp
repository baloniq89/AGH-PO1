#include "Data.h"

Data::Data(std::string name, std::vector<double> exponses) : _dayName(name), _exp(exponses){}


void Data::print()const {

  std::cout<<_dayName << ":";
  std::for_each(std::begin(_exp), std::end(_exp), [](double item){std::cout<<std::setw(6) << item;});
  std::cout<<std::endl;

}

double Data::operator [](unsigned i)const{
  return _exp[i];
}

int Data::size()const{
  return _exp.size();
}