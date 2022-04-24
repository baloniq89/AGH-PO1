#include "SumOfElements.h"

SumOfElements::SumOfElements(double *numbers, int size){

  _arraySize = size;
  _numbersArray = new double [size];

  for(int i=0; i < size ; i++)
  {
    _numbersArray[i] = numbers[i];
  }
}

SumOfElements::~SumOfElements(){

  delete [] _numbersArray;
  _arraySize = 0;


}


void SumOfElements::print()const{

  for(int i=0; i< _arraySize - 1; i++)
  {
    std::cout<<_numbersArray[i]<< " + ";
  }
  std::cout<<_numbersArray[_arraySize - 1];
}

double SumOfElements::eval() const{

  double suma = 0.0;

  for(int i=0; i < _arraySize; i++)
  {
    suma += _numbersArray[i];
  }

  return suma;
}