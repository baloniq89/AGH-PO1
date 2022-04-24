#include "Sum.h"

void Sum::operator()(double money) {

  _suma = _suma + money;

}

double Sum::value()const{
  return _suma;
}

Sum sumData(const Data & _moneySpent){
  return Sum(std::accumulate(_moneySpent._exp.begin(), _moneySpent._exp.end() ,0.0));
}