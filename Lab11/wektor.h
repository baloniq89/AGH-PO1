#pragma once

#include "TestObject.h"

/**
  *Llasa Vector reprezantujaca nasza tablice      
  */
class Vector {

  public:
    /**
      *szablon fukncji inicializujacej tablice
      *@param - T1  
    */
      template<typename T1>
      static void initialise(T1 intSize)
      {
        _size = intSize;
        _array = new T1[_size];
      }

      /**
        *szablon funkcji inicializujacej tablice(Vector) podanym objektem T2
        *@param const int, T2

      */
      template<typename T2>
      static void initialise(const int objSize, T2 object)
      {
        _size = objSize;
        _array = new T2[_size];

        for(int i = 0; i < _size; i++)
        {
          static_cast<T2*>(_array)[i] = object;
        }
      }

      /**
        *szablo funkcji ktora zwraca referencje do elementu tablicy o wskazanym indeksie
        *@param int
        *@return T1&
      */
      template<typename T1>
      static T1& at(int index)
      {
        return static_cast<T1*>(_array)[index];
      }


      /**
        *metoda statyczna usuwająca (resetujaca) tablice 
      */
      template<typename T1>
      static void reset()
      {
        if( _array != nullptr)
        {
          delete[] static_cast<T1*>(_array);
          _array = nullptr;
        }
      }

      /**
        *funnkcja statyczna zwracajaca rozmiar tablicy
        *@return int
      */
      static int size()
      {
        return _size;
      }



  private:
  //zmienne
      static int _size;
      static void *_array;
};
//obsługa zmiennych statycznych _size = 0, _array = nullptr
int Vector::_size = 0;
void *Vector::_array = nullptr;