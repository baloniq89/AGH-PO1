#pragma once

#include "Operation.h"

class SumOfElements : public Operation {

  public:
      SumOfElements(double *, int);// konstruktor dwuargumentowy

      ~SumOfElements();// destruktor zwalniajacy pamiec zaalokowana na tabolice _numbersArray

      void print() const override;//funkcja wypisujaca operacje sumowania elementow tablicy _numbersArray[0] + _numbersArray[1] + .. + _numbersArray[_arraySize -1]

      double eval () const override;// funkcja zwracajaca sume elementow tablicy _numbersArray


  private:
      double *_numbersArray;
      int _arraySize;

};